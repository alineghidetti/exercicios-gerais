#include "vetor.h"
#include <stdio.h>

int Soma(int x, int y) {
    return x + y;
}
int Multiplica(int x, int y) {
    return x * y;
}
int main() {
    Vetor vetor;
    LeVetor(&vetor);
    Operation op = Soma;
    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, op));
    op = Multiplica;
    printf("Produto: %d", AplicarOperacaoVetor(&vetor, op));
    return 0;
}