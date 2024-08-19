#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int *CriaVetor(int tamanho){
    int *vetor = (int*) calloc(tamanho, sizeof(int));
    if(vetor == NULL){
        printf("ERRO\n");
        exit(1);
    }

    return vetor;
}

void LeVetor(int *vetor, int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho){
    float soma=0;
    int i;
    for(i=0; i<tamanho; i++){
        soma+=vetor[i];
    }    
    return soma/tamanho;
}

void LiberaVetor(int *vetor){
    free(vetor);
}