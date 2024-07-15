#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

int main() {
    tLocadora locadora;
    char parada = '\0';
    char operacao[10];
    char opcoes[4][10] = {"Cadastrar", "Alugar", "Devolver", "Estoque"};
    int acao = 0;

    locadora = criarLocadora();

    while(scanf("%s", operacao) == 1) {
        
        if ((strcmp(operacao, opcoes[0]) == 0)) {
            locadora = lerCadastroLocadora(locadora);
            printf("\n");
            if ((scanf("%c", &parada) == 1) && (parada == '#')) {
                continue;
            }
        }
        if ((strcmp(operacao, opcoes[1]) == 0)) {
            locadora = lerAluguelLocadora(locadora);
            printf("\n");
            if ((scanf("%c", &parada) == 1) && (parada == '#')) {
                continue;
            }
        }
        if ((strcmp(operacao, opcoes[2]) == 0)) {
            locadora = lerDevolucaoLocadora(locadora);
            printf("\n");
            if ((scanf("%c", &parada) == 1) && (parada == '#')) {
                continue;
            }
        }
        if ((strcmp(operacao, opcoes[3]) == 0)) {
            locadora = ordenarFilmesLocadora(locadora);
            consultarEstoqueLocadora(locadora);

            if ((scanf("%c", &parada) == 1) && (parada == '#')) {
                continue;
            }
        }
    }
    consultarLucroLocadora(locadora);

    return 0;
}