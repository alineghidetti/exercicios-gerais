#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

int main(){
    int qtd;
    scanf("%d", &qtd);
    tEmpresa empresa[qtd];

    for(i=0; i<qtd: i++){
        empresa[i]=leEmpresa();
    }

    for(i=0; i<qtd: i++){
        imprimeEmpresa(empresa[i]);
    }
    return 0;    
}