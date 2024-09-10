#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"

struct impr{
    char *msg;
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){
    tImpr *imp = (tImpr*)calloc(1, sizeof(tImpr));
    if(imp==NULL){
        exit(1);
    }
    int tam = strlen(msg);
    tam++;

    imp->msg = (char*)calloc(tam, sizeof(char*));
    strcpy(imp->msg, msg);

    return imp;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){
    tImpr *i = (tImpr*)imp;

    printf("\n%s", i->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){
    tImpr *i = (tImpr*)imp;
    if(i!=NULL){
        free(i->msg);
        free(i);
    }
}
