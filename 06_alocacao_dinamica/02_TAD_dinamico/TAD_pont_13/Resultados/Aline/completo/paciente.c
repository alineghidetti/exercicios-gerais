#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>

char* GetCartaoSusPaciente(tPaciente* p){
    return p->cartaoSus;
}

int GetQtdLesoesPaciente(tPaciente* p){
    return p->qtdLesoes;
}

int GetQtdCirurgiasPaciente(tPaciente* p){
    int qtdCirurgias=0;
    int i;
    for(i=0; i<p->qtdLesoes; i++){
        if(PrecisaCirurgiaLesao(p->listaLesao[i])){
        qtdCirurgias ++;
        }
    }
    return qtdCirurgias;
}

tData* GetNascimentoPaciente(tPaciente* p){
    return p->nascimento;
}

tPaciente* CriaPaciente(){
    tPaciente *p;
    p = (tPaciente*)calloc(1, sizeof(tPaciente));
    if(p==NULL){
        exit(1);
    }
    // Aloca e inicializa os campos do paciente
    p->nome = (char*)calloc(TAM_NOME, sizeof(char));
    p->cartaoSus = (char*)calloc(TAM_CSUS, sizeof(char));
    p->nascimento = CriaData(1, 1, 1900); // Define uma data padrão para nascimento
    p->listaLesao = (tLesao**)calloc(QTD_LESAO, sizeof(tLesao*));
    p->qtdLesoes = 0;
    p->maxLesoes = QTD_LESAO;
    p->genero = ' ';

    if (p->nome == NULL || p->cartaoSus == NULL || p->nascimento == NULL || p->listaLesao == NULL) {
        printf("Erro ao alocar memória para campos do p.\n");
        free(p->nome);
        free(p->cartaoSus);
        LiberaData(p->nascimento);
        free(p->listaLesao);
        free(p);
        exit(1);
    }

    return p;
}

void LePaciente(tPaciente* p){

    if(p==NULL){
        exit(1);
    }

    scanf("%[^\n\n]", p->nome);
    p->nascimento = LeData();
    scanf("%[^\n\n]", p->cartaoSus);
    scanf("%c%*c", &p->genero);
    p->qtdLesoes = 0;
}

void ImprimePaciente(tPaciente* p){
    if(p->qtdLesoes>0){
    printf("- %s - ", p->nome);

    if(p->qtdLesoes>0){
        printf("L");
        for(int i=0; i<p->qtdLesoes; i++){
            printf("%d", i+1);
            if(i<p->qtdLesoes-1){
                printf(", ");
            }
        }
    }
    printf("\n");}
}

void LiberaPaciente(tPaciente* p) {
    if (p == NULL) return;

    free(p->nome);
    LiberaData(p->nascimento); // Correto para liberar p->nascimento
    
    for (int i = 0; i < p->qtdLesoes; i++) {
        LiberaLesao(p->listaLesao[i]);
    }
    free(p->listaLesao);
    free(p->cartaoSus);
    free(p);
}

void AdicionaLesaoPaciente(tPaciente* p, tLesao* l) {
    if (p == NULL || l == NULL) {
        printf("Ponteiro para paciente ou lesão é nulo.\n");
        return;
    }

    // // Verifica se há espaço suficiente na lista de lesões
    // if (p->qtdLesoes >= p->maxLesoes) {
    //     // Aumenta a capacidade da lista de lesões
    //     int novaCapacidade = p->maxLesoes * 2;
    //     tLesao** novaLista = (tLesao**)realloc(p->listaLesao, novaCapacidade * sizeof(tLesao*));
    //     if (novaLista == NULL) {
    //         printf("Erro ao realocar memória para a lista de lesões.\n");
    //         return;
    //     }
    //     p->listaLesao = novaLista;
    //     p->maxLesoes = novaCapacidade;
    // }

    // Adiciona a nova lesão à lista
    p->listaLesao[p->qtdLesoes] = l;
    p->qtdLesoes++;
}