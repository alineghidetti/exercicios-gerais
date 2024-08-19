#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rolagem.h"

// Função para exibir o painel de mensagens
void ExibePainel(char *mensagens, int tamanhoDisplay, int posicao) {
    int comprimentoTotal = strlen(mensagens);
    for (int i = 0; i < tamanhoDisplay; i++) {
        int index = (posicao + i) % comprimentoTotal;
        putchar(mensagens[index]);
    }
    putchar('\n');
    fflush(stdout);
}

// Função de rolagem de mensagens
void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim) {
    char mensagens[NUM_MAX_MSGS][TAM_MAX_MSG];
    int numMsgs = 0;

    // Recebe as mensagens da função callback
    FuncMsg(mensagens, &numMsgs);

    // Concatena as mensagens em uma única string
    char textoConcat[TAM_MAX_MSG * NUM_MAX_MSGS];
    textoConcat[0] = '\0';
    for (int i = 0; i < numMsgs; i++) {
        strcat(textoConcat, mensagens[i]);
    }

    int comprimentoTotal = strlen(textoConcat);
    for (int pos = 0; pos < comprimentoTotal + tamanhoDisplay; pos++) {
        // Limpa a tela
        printf("\033[H\033[J");
        
        // Exibe o painel na posição atual
        ExibePainel(textoConcat, tamanhoDisplay, pos);

        // Espera antes de mostrar o próximo passo
        usleep(1000000 / tempoFim);
    }
}
