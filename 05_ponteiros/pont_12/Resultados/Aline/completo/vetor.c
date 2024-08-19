#include "vetor.h"
#include <stdio.h>
#include <string.h>

void LeVetor(Vetor *vetor){
    scanf("%d\n", &vetor->tamanhoUtilizado);
    for(int i=0; i< vetor->tamanhoUtilizado; i++){
        scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int i;
    int resultado = vetor->elementos[0];

    for(i=1; i<vetor->tamanhoUtilizado; i++){
        resultado = op(resultado, vetor->elementos[i]);
    }
    return resultado;
}