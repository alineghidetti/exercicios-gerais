#include <stdio.h>
#include <string.h>
#include "vendedor.h"
#include "loja.h"

tLoja AbreLoja(int id, float aluguel){
    tLoja loja;
    loja.id = id;
    loja.totalVendedores = 0;
    loja.aluguel = aluguel;
    loja.lucro = 0;
    
    return loja;
}

int VerificaIdLoja(tLoja loja, int id){
    if(loja.id == id){
        return 1;
    }
    return 0;
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor){
    loja.vendedores[loja.totalVendedores] = vendedor;
    loja.totalVendedores++;
    return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor){
    int i=0;
    for(i=0; i<loja.totalVendedores;i++){
        if(VerificaNomeVendedor(loja.vendedores[i], nome)){
            loja.vendedores[i].valor_vendido+= valor;
            break;
        }
    }
    return loja;
}

tLoja CalculaLucro(tLoja loja){
    int i=0;
    float val;
    float vendido=0, vendedores=0;
    for(i; i<loja.totalVendedores; i++){
        loja.lucro += (GetTotalVendido(loja.vendedores[i]) - GetTotalRecebido(loja.vendedores[i]));

    }
    loja.lucro -= loja.aluguel;
    return loja;
}

void ImprimeRelatorioLoja(tLoja loja){
    int i;
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);
    for(i=0; i<loja.totalVendedores; i++){
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}