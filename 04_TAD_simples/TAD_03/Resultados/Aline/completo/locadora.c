#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

tLocadora criarLocadora() {
    tLocadora locadora;

    locadora.numFilmes = 0;
    locadora.lucro = 0;

    return locadora;
}

int verificaFilmeCadastrado(tLocadora locadora, int codigo) {
    int f;

    for (f = 0; f < locadora.numFilmes; f++) {
        if (obterCodigoFilme(locadora.filme[f]) == codigo) {
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme) {
    if (verificaFilmeCadastrado(locadora, filme.codigo)) {
        printf("Filme ja cadastrado no estoque\n");
    }else {
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes += 1;

        printf("Filme cadastrado %d - %s\n", filme.codigo, filme.nome);
    }
    return locadora;
}

tLocadora lerCadastroLocadora(tLocadora locadora) {
    int codigo;
    tFilme filme;

    while(scanf("%d,", &codigo) == 1) {

        filme = leFilme(codigo);

        locadora = cadastrarFilmeLocadora(locadora, filme);
    }

    return locadora;
}

tLocadora alugarFilmesLocadora(tLocadora locadora, int codigos[], int quantidadeCodigos) {
    int c, f;
    int existeFilme;
    int contAlugados = 0, custo = 0;

    for (c = 0; c < quantidadeCodigos; c++) {
        existeFilme = 0;
        for (f = 0; f < locadora.numFilmes; f++) {
            if (ehMesmoCodigoFilme(locadora.filme[f], codigos[c])) {
                existeFilme = 1;
            
                if (obterQtdEstoqueFilme(locadora.filme[f]) > 0) {
                    locadora.filme[f] = alugarFilme(locadora.filme[f]);
                    custo += obterValorFilme(locadora.filme[f]);
                    contAlugados++;
                }else {
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[f]));
                    imprimirNomeFilme(locadora.filme[f]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
                break;
            }
        }
        if (!(existeFilme)) {
            printf("Filme %d nao cadastrado.\n", codigos[c]);
        }
    }

    if (contAlugados > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n", contAlugados, custo);
    }

    return locadora;    
}

tLocadora lerAluguelLocadora(tLocadora locadora) {
    int codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];

    while(scanf("%d\n", &codigo) == 1) {
        codigosFilmes[qtdCodigos] = codigo;
        qtdCodigos++;
    }
    locadora = alugarFilmesLocadora(locadora, codigosFilmes, qtdCodigos);

    return locadora;
}

tLocadora devolverFilmesLocadora(tLocadora locadora, int codigos[], int quantidadeCodigos) {
    int c, f;
    int existeFilme;

    for (c = 0; c < quantidadeCodigos; c++) {
        existeFilme = 0;
        for (f = 0; f < locadora.numFilmes; f++) {
            if (ehMesmoCodigoFilme(locadora.filme[f], codigos[c])) {
                existeFilme = 1;
            
                if (obterQtdAlugadaFilme(locadora.filme[f]) > 0) {
                    locadora.filme[f] = devolverFilme(locadora.filme[f]);
                    locadora.lucro += obterValorFilme(locadora.filme[f]);
                    printf("Filme %d - ", codigos[c]);
                    imprimirNomeFilme(locadora.filme[f]);
                    printf(" Devolvido!\n");
                }else {
                    printf("Nao e possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[f]));
                    imprimirNomeFilme(locadora.filme[f]);
                    printf(".\n");
                }
                break;
            }
        }
        if (!(existeFilme)) {
            printf("Filme %d nao cadastrado.\n", codigos[c]);
        }
    }
    return locadora;
}

tLocadora lerDevolucaoLocadora(tLocadora locadora) {
    int codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];

    while(scanf("%d\n", &codigo) == 1) {
        codigosFilmes[qtdCodigos] = codigo;
        qtdCodigos++;
    }
    locadora = devolverFilmesLocadora(locadora, codigosFilmes, qtdCodigos);

    return locadora;
}

tLocadora ordenarFilmesLocadora(tLocadora locadora) {
    int f, o;
    tFilme aux;

    for (f = 0; f < (locadora.numFilmes - 1); f++) {
        for(o = f + 1; o < locadora.numFilmes; o++) {
            if (compararNomesFilmes(locadora.filme[f], locadora.filme[o]) > 0) {
                aux = locadora.filme[f];
                locadora.filme[f] = locadora.filme[o];
                locadora.filme[o] = aux;
            }
        }
    }
    return locadora;
}

void consultarEstoqueLocadora(tLocadora locadora) {
    int f, cont = 1;

    printf("~ESTOQUE~\n");

    for (f = 0; f < locadora.numFilmes; f++) {
        printf("%d - ", obterCodigoFilme(locadora.filme[f]));
        imprimirNomeFilme(locadora.filme[f]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[f]));

        cont++;
    }
}

void consultarLucroLocadora(tLocadora locadora) {
    if (locadora.lucro > 0) {
        printf("\nLucro total R$%d\n", locadora.lucro);
    }
}