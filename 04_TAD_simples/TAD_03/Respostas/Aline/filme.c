#include "filme.h"
#include <string.h>
#include <stdio.h>

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme filme;
    
    filme.codigo = codigo;
    strcpy(filme.nome, nome);
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;

    return filme;
}

tFilme leFilme(int codigo){
    tFilmefilme;
    char nome[MAX_CARACTERES];
    int valor;
    int quantidade;

    scanf("%[^,],%d,%d\n");
    filme = criarFilme(nome, codigo, valor, quantidade);
    
    return filme;
}

int obterCodigoFilme (tFilme filme){
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme){
    printf("%s", filme.nome);
}

int obterValorFilme (tFilme filme){
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme){
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo){
    if(filme.codigo == codigo){
        return 1;
    }
    return 0;
}

tFilme alugarFilme (tFilme filme){
    filmme.qtdAlugada++;
    filme.qtdEstoque--;

    return filme;
}

tFilme devolverFilme (tFilme filme){
    filmme.qtdAlugada--;
    filme.qtdEstoque++;

    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2){
    return (strcmp(filme1.nome, filme2.nome));
}
