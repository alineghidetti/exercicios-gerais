#include <stdlib.h>
#include "listapessoas.h"

ListaPessoa* criaListaPessoa(){
    ListaPessoa *lp = (ListaPessoa*)calloc(SHIFT, sizeof(ListaPessoa));
    if(lp == NULL){
        printf("ERRO");
        exit(1);
    }
    lp->qtdDados = 0;
    lp->qtdAlocado = SHIFT;
    lp->dados = (Pessoa**)calloc(lp->qtdAlocado, sizeof(Pessoa*));
    if(lp->dados == NULL){
        printf("ERRO");
        free(lp);
        exit(1);
    }
    return lp;
}

void adicionaPessoaLista(ListaPessoa *lp, Pessoa *p) {
    if (lp->qtdDados >= lp->qtdAlocado) {
        lp->qtdAlocado += SHIFT;
        lp->dados = (Pessoa **)realloc(lp->dados, lp->qtdAlocado * sizeof(Pessoa *));
        if (lp->dados == NULL) {
            printf("Erro ao realocar memória para dados.\n");
            exit(1);
        }
    }
    lp->dados[lp->qtdDados] = p;
    lp->qtdDados++;
}

// Função para liberar a memória associada à lista de pessoas
void liberaListaPessoa(ListaPessoa *lp) {
    for (int i = 0; i < lp->qtdDados; i++) {
        liberaPessoa(lp->dados[i]); // Libera cada pessoa na lista
    }
    free(lp->dados); // Libera o array de ponteiros
    free(lp); // Libera a estrutura ListaPessoa
}