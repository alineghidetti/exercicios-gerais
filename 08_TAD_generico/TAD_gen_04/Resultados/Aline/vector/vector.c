#include <stdio.h>
#include <stdlib.h> 
#include "vector.h"

// typedef void *DataType; // void pointer
struct Vector{
    int tam;
    DataType *vetor;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *v = (Vector*)calloc(1, sizeof(Vector));
    if(v == NULL){
        exit(1);
    }
    v->vetor=NULL;
    v->tam=0;

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->tam++;
    v->vetor = realloc(v->vetor, v->tam*sizeof(DataType*)); //realoca e joga o novo valor no novo espaço
    v->vetor[v->tam-1] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
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
            if(v->vetor[i] != NULL){
                destroy(v->vetor[i]);
            }
            else{
                free(v->vetor[i]);
            }
        }
        free(v->vetor);
        free(v);
    }
}