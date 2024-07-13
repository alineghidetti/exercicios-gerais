#include <stdio.h>
#include <stdlib.h>
#include "loja.h"
#include "vendedor.h"

int main() {
    int qtdLojas, opcao, idLoja, q;
    int l = 0;
    int encerrar = 0;
    float aluguel, salario, comissao, valorVenda;
    char nome[50];

    scanf("%d", &qtdLojas);

    tLoja lojas[qtdLojas];

    while (1) {
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 0:
                encerrar = 1;
                break;;
            case 1:
                scanf("%d %f", &idLoja, &aluguel);
                lojas[l] = AbreLoja(idLoja, aluguel);
                l++;
                break;
            case 2:
                scanf("%s %f %f", nome, &salario, &comissao);
                scanf("%d", &idLoja);
                for (q = 0; q < l; q++) {
                    if (VerificaIdLoja(lojas[q], idLoja)) {
                        lojas[q] = ContrataVendedor(lojas[q], RegistraVendedor(nome, salario, comissao));
                    }
                }
                break;
            case 3:
                scanf("%d %s %f", &idLoja, nome, &valorVenda);
                for (q = 0; q < l; q++) {
                    if (VerificaIdLoja(lojas[q], idLoja)) {
                        lojas[q] = RegistraVenda(lojas[q], nome, valorVenda);
                    }
                }
                break;
            case 4:
                for (q = 0; q < l; q++) {
                    lojas[q] = CalculaLucro(lojas[q]);
                    ImprimeRelatorioLoja(lojas[q]);
                }
                break;
        }
        if (encerrar) {
            break;
        }
    }
    return 0;
}