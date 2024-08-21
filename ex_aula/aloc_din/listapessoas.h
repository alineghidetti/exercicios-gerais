#ifndef _LISTA_PESSOAS_H
#define _LISTA_PESSOAS_H
#define SHIFT 5

#include "pessoa.h"

typedef struct{
    Pessoa **dados;
    int qtdDados;
    int qtdAlocado;
}ListaPessoa;

ListaPessoa *criaListaPessoa();

void adicionaPessoaLista(ListaPessoa *lp, Pessoa *p);

void liberaListaPessoa(ListaPessoa *lp);

#endif