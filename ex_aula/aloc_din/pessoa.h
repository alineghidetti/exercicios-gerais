#ifndef _PESSOA_H
#define _PESSOA_H
#define TAM_NOME 5
#define TAM_CPF 11
#include <stdio.h>

typedef struct{
    char *nome;
    char *cpf;
}Pessoa;

Pessoa *lePessoa();

void liberaPessoa(Pessoa *p);

void imprimePessoa(Pessoa *p);

#endif