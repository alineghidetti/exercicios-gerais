#include "utils_char2.h"
#include <stdio.h>
#include <stdlib.h>

char *CriaVetorTamPadrao(){
    char *vetor;
    vetor = (char*) calloc(TAM_PADRAO+1, sizeof(char));

    for(int i=0; i<TAM_PADRAO; i++){
        vetor[i] = '_';
    }

    vetor[TAM_PADRAO] = '\0';

    if(vetor == NULL){
        exit(1);
    }
    return vetor;
}

char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){
    vetor = realloc(vetor, (tamanhoantigo+TAM_PADRAO+1)*sizeof(char));
    int i;
    for(i=tamanhoantigo; i<=tamanhoantigo+TAM_PADRAO; i++){
        vetor[i] = '_';
    }
    vetor[tamanhoantigo+TAM_PADRAO]='\0';
    return vetor;
}

char* LeVetor(char *vetor, int *tamanho){
    int i=0;
    char c;
    while(scanf("%c", &c) == 1){
        if(c == '\n'){
            break;
        
        }
        if(i==*tamanho){
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }
        vetor[i] = c;
        i++;
    }
    return vetor;
}

void ImprimeString(char *vetor){
    printf("%s", vetor);
    
}

void LiberaVetor(char *vetor){
    free(vetor);
}