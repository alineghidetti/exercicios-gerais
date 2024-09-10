#include <stdio.h>
#include <stdlib.h>
#include "tarefamultiplica.h"

struct mult{
    float n1;
    float n2;
};

/**
 * @brief Cria uma tarefa do tipo multiplicação de dois números
 * 
 * @param n1 - Primeiro número que será multiplicado quando a tarefa for executada
 * @param n2 - Segundo número que será multiplicado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult *mult = (tMult*)calloc(1,sizeof(tMult));
    if(mult==NULL){
        exit(1);
    }
    mult->n1=n1;
    mult->n2=n2;

    return mult;
}

/**
 * @brief Função que executa uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult){
    tMult *m = (tMult*)mult;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", m->n1, m->n2, m->n1*m->n2);}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult){
    tMult *m = (tMult*)mult;
    if(m!=NULL){
        free(m);
    }
}