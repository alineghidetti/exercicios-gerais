#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"
#include "gerenciadorpacotes.h"

struct gerenciadorpacotes{
    tPacote **pacotes;
    int qtd;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador(){
    tGerenciador *ger = (tGerenciador*)calloc(1, sizeof(tGerenciador));
    ger->qtd = 0;
    ger->pacotes = NULL;
    
    return ger;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    geren->qtd++;
    int total = geren->qtd;
    geren->pacotes = realloc(geren->pacotes, total*sizeof(tPacote*));
    geren->pacotes[total-1]=pac;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){
    if(geren!=NULL){
        for(int i=0; i<geren->qtd; i++){
            DestroiPacote(geren->pacotes[i]);
        }
        free(geren->pacotes);
        free(geren);
    }
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->pacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){
    for(int i=0; i<geren->qtd; i++){
        ImprimePacote(geren->pacotes[i]);
    }
}