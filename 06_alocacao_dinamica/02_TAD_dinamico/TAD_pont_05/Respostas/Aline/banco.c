#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#define SHIFT 5

tBanco *CriaBanco(){
    tBanco *banco;
    banco = (tBanco*)calloc(SHIFT, sizeof(tBanco));
    if(banco == NULL){
        exit(1);
    }
    return banco;
}

void DestroiBanco(tBanco *banco) {
    if (banco == NULL) {
        return; // Evita tentar liberar memória de um ponteiro nulo
    }

    // Libera a memória de cada conta
    for (int i = 0; i < banco->qtdContas; i++) {
        if (banco->contas[i] != NULL) {
            DestroiConta(banco->contas[i]);
        }
    }

    // Libera a memória do array de ponteiros para contas
    free(banco->contas);

    // Libera a memória do banco
    free(banco);
}
