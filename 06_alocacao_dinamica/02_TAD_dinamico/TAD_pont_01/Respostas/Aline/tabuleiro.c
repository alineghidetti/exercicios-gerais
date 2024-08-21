#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

tTabuleiro* CriaTabuleiro(){
    int i, j;
    tTabuleiro* tabuleiro;
    tabuleiro = (tTabuleiro*) calloc(1, sizeof(tTabuleiro));
    tabuleiro->posicoes = (char**) calloc(TAM_TABULEIRO, sizeof(char*));
    
    if (tabuleiro == NULL) {
    perror("Falha ao alocar memória para o tabuleiro");
    exit(1);
}
    
    for(i=0; i<TAM_TABULEIRO; i++){
        tabuleiro->posicoes[i] = (char*) calloc(TAM_TABULEIRO, sizeof(char));
    }
}