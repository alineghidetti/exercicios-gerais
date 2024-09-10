
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

// typedef void *DataType; // void pointe
struct Vector{
    DataType *data;
    int tam;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *vetor = (Vector*)calloc(1, sizeof(Vector));
    if(vetor==NULL){
        exit(1);
    }

    vetor->data=NULL;
    vetor->tam=0;

    return vetor;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->tam++;
    v->data = realloc(v->data, v->tam*sizeof(DataType*));
    v->data[v->tam-1]=val;
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v){
    DataType removido = v->data[0];
    for(int i=0; i<v->tam-1; i++){
       v->data[i] = v->data[i+1];
    }
    v->tam--;
    return removido;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->tam;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    if(v!=NULL){
        for(int i=0; i<v->tam; i++){
            if(v->data[i]!=NULL){
                destroy(v->data[i]);
            }
            else{
                free(v->data[i]);
            }
        }
        free(v->data);
        free(v);
    }
}


