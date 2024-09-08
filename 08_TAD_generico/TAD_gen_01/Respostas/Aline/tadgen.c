#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic{
    void *dados;
    int numElem;
    Type type;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *gen = (tGeneric*)calloc(1, sizeof(tGeneric));
    gen->type = type;
    gen->numElem = numElem;
    if(type==0){
        gen->dados = (float*)calloc(numElem, sizeof(float));
    }
    else if(type==1){
        gen->dados = (int*)calloc(numElem, sizeof(int));
    }

    return gen;

}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    if(gen!=NULL){
        free(gen->dados);
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    int i=0;
    printf("\nDigite o vetor:\n");
    if(gen->type == 1){
        for(i=0; i<gen->numElem; i++){
            scanf("%d", (int*)gen->dados + i);
        }
    }
    else if(gen->type == 0){
        for(i=0; i<gen->numElem; i++){
            scanf("%f", (float*)gen->dados + i);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    int i=0;
    if(gen->type == 1){
        for(i=0; i<gen->numElem; i++){
            printf("%d ", *((int*)gen->dados + i));
        }
    }
    else if(gen->type == 0){
        for(i=0; i<gen->numElem; i++){
            printf("%.2f ", *((float*)gen->dados + i));
        }
    }

}