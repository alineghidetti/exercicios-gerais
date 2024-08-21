#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

Pessoa *lePessoa(){
    Pessoa *p = (Pessoa*)calloc(1, sizeof(Pessoa));
    if (p == NULL) {
        printf("Erro ao alocar memória para Pessoa.\n");
        exit(1);
    }
    p->nome = (char*)calloc(TAM_NOME, sizeof(char));
    p->cpf = (char*)calloc(TAM_CPF, sizeof(char));

    // strcpy(p->nome, nome);
    // strcpy(p->cpf, cpf);

    scanf("%[^\n]\n", p->nome);
    scanf("%[^\n]\n", p->cpf);

    return p;
}

void liberaPessoa(Pessoa *p){
    free (p->nome);
    free(p->cpf);
    free(p);
}

void imprimePessoa(Pessoa *p){
    printf("NOME: %s\n", p->nome);
    printf("CPF: %s\n", p->cpf);
}