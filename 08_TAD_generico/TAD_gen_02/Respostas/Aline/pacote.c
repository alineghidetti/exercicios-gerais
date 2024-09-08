#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

// typedef enum {
//     INT = 1,
//     CHAR = 2
// } Type;

struct pacote{
    void *vetor;
    int somaVerificacao;
    Type type;
    int tam;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote *pac = (tPacote*)calloc(1, sizeof(tPacote));
    pac->type = type;
    pac->tam = numElem;
    pac->somaVerificacao = 0;
    
    if(type==1){
        pac->vetor = (int*)calloc(numElem, sizeof(int));
    }else if(type == 2){
        pac->vetor = (char*)calloc(numElem, sizeof(char));
    }

    return pac;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    free(pac->vetor);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    scanf("%*c");
    printf("\nDigite o conteúdo do vetor/mensagem: ");
    if(pac->type == 1){
        for(int i=0; i<pac->tam; i++){
            scanf("%d", (int*)pac->vetor + i);
        }
    }else if(pac->type == 2){
        for(int i=0; i<pac->tam; i++){
            scanf("%c", (char*)pac->vetor + i);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->somaVerificacao);
    int i=0;
    if(pac->type == 1){
        for(i=0; i<pac->tam; i++){
            printf("%d ", *((int*)pac->vetor + i));
        }
    }else if(pac->type == 2){
        for(i=0; i<pac->tam; i++){
            printf("%c", *((char*)pac->vetor + i));
        }
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    pac->somaVerificacao = 0;  // Certifique-se de reinicializar a soma
    if(pac->type == 1){
        for(int i=0; i<pac->tam; i++){
            pac->somaVerificacao += *((int*)pac->vetor + i);
        }
    }else if(pac->type == 2){
        for(int i=0; i<pac->tam; i++){
            if (*((char*)pac->vetor + i) != '\n') {
                pac->somaVerificacao += *((char*)pac->vetor + i);
            }
            
        }
    }
}

