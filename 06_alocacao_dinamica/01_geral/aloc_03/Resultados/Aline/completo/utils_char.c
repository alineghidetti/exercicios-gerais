#include "utils_char.h"
#include <stdio.h>
#include <stdlib.h>

char *CriaVetor(int tamanho){
    char *v;
    v = (char*) calloc(tamanho, sizeof(char));
    if(v == NULL){
        printf("erro de alocacao\n");
        exit(1);
    }
    for(int i=0; i<tamanho; i++){
        v[i] = '_';
    }
    return v;
}

void LeVetor(char *vetor, int tamanho){
    int i=0;
    char c;
    while(scanf("%c", &c)==1){
        if(c == '\n'){
            break;
        }
        vetor[i] = c;
        i++;

        if(i == tamanho){
            break;
        }
    }
}

void ImprimeString(char *vetor, int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
        printf("%c", vetor[i]);
    }
    printf("\n");
}

void LiberaVetor(char *vetor){
    free(vetor);
}