#include <stdio.h>
#include "rolagem.h"

// Função callback que fornece as mensagens
void LeMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs) {
    int qtd;
    char buffer[TAM_MAX_MSG];

    scanf("%d\n", &qtd);
    *numMsgs = qtd;
    
    for (int i = 0; i < qtd; i++) {
        if (fgets(buffer, sizeof(buffer), stdin)) {
            buffer[strcspn(buffer, "\n")] = '\0'; // Remove a nova linha
            strncpy(msg[i], buffer, TAM_MAX_MSG);
        }
    }
}

int main(void) {
    int tamanhoDisplay = 30; // Tamanho do painel
    int tempoFim;

    // Lê o tempo de duração da rolagem
    scanf("%d", &tempoFim);

    // Chama a função de rolagem
    RolaMsg(LeMensagens, tamanhoDisplay, tempoFim);

    return 0;
}
