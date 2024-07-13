#include <stdio.h>
#include <string.h>
#include "vendedor.h"
#include "loja.h"

int main(){
    int qtd, opc, id;
    int i=0;
    float salario, comissao;
    float aluguel, valorVenda;
    char nome[50];
    tLoja lojas[qtd];
    
    scanf("%d", &qtd);
    scanf("%d", &opc);

    //registrar loja
    if(opc == 1){
        scanf("%d %f", &id, &aluguel);
        lojas[i]=AbreLoja(id, aluguel);
        i++;
    }
    //contratar vendedor
    else if(opc == 2){
        scanf("%s %f %f", nome, &salario, &comissao);
        scanf("%d", &id);
        for(int j=0; j<i; j++){
            if(VerificaIdLoja(lojas[j], id)==0){
                lojas[j] = ContrataVendedor(lojas[j], RegistraVendedor(nome, salario, comissao));
            }
        }
    }
    //registrar venda
    else if(opc == 3){
        scanf("%d %s %f", &id, nome, &valorVenda);
        for (int q = 0; q <i; q++) {
            if (VerificaIdLoja(lojas[q], id)) {
                lojas[q] = RegistraVenda(lojas[q], nome, valorVenda);
            }
        }
    }
    else if(opc == 4){
        for (int q = 0; q < i; q++) {
        lojas[q] = CalculaLucro(lojas[q]);
        ImprimeRelatorioLoja(lojas[q]);
        }
    }
    else if(opc == 0){
        return 0;
    }

}