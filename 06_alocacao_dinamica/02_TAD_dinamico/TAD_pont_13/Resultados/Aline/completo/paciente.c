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
    int qtdCirurgias = 0;
    for (int i = 0; i < p->qtdLesoes; i++) {
        if (PrecisaCirurgiaLesao(p->listaLesao[i])) {
            qtdCirurgias++;
        }
    }
    return qtdCirurgias;
}

tData* GetNascimentoPaciente(tPaciente* p){
    return p->nascimento;
}

tPaciente* CriaPaciente(){
    tPaciente *p = (tPaciente*)calloc(1, sizeof(tPaciente));
    if (p == NULL) {
        exit(1);
    }

    p->nome = (char*)calloc(TAM_NOME, sizeof(char));
    p->cartaoSus = (char*)calloc(TAM_CSUS, sizeof(char));
    p->nascimento = NULL; // Inicialmente, não alocar data aqui
    
    p->listaLesao = (tLesao**)calloc(QTD_LESAO, sizeof(tLesao*));
    p->qtdLesoes = 0;
    p->maxLesoes = QTD_LESAO;
    p->genero = ' ';

    if (p->nome == NULL || p->cartaoSus == NULL || p->listaLesao == NULL) {
        printf("Erro ao alocar memória para campos do paciente.\n");
        free(p->nome);
        free(p->cartaoSus);
        free(p->listaLesao);
        free(p);
        exit(1);
    }

    return p;
}

void LePaciente(tPaciente* p){
    if (p == NULL) {
        exit(1);
    }

    scanf("%[^\n\n]", p->nome);
    if (p->nascimento != NULL) {
        LiberaData(p->nascimento);  // Liberar a memória antiga
    }
    p->nascimento = LeData();
    scanf("%[^\n\n]", p->cartaoSus);
    scanf("%c%*c", &p->genero);
    p->qtdLesoes = 0;
}

void ImprimePaciente(tPaciente* p){
    if (p->qtdLesoes > 0) {
        printf("- %s - ", p->nome);

        for (int i = 0; i < p->qtdLesoes; i++) {
            printf("%s ", GetIdLesao(p->listaLesao[i]));
            if (i < p->qtdLesoes - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

void LiberaPaciente(tPaciente* p) {
    if (p == NULL) return;

    free(p->nome);
    LiberaData(p->nascimento);
    
    for (int i = 0; i < p->qtdLesoes; i++) {
        if (p->listaLesao[i] != NULL) {
            LiberaLesao(p->listaLesao[i]);
        }
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
    if (p->qtdLesoes < p->maxLesoes) { // Verifica se ainda há espaço para mais lesões
        p->listaLesao[p->qtdLesoes] = l;
        p->qtdLesoes++;
    } else {
        printf("Número máximo de lesões atingido.\n");
    }
}
