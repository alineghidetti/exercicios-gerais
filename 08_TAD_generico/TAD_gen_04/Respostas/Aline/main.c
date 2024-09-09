#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

int main(){
    tBanco* banco = CriaBanco();
    LeBanco(banco);
    
    char opc;

    while(scanf("%c", &opc) == 1 && opc !='F'){
        if(opc=='A'){
            tAgencia* agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        }
        else if(opc=='C'){
            tConta *conta = CriaConta();
            LeConta(conta);
            int idA;
            scanf("%d%*c", &idA);
            InsereContaBanco(banco, idA, conta);
        }
    }
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);
    return 0;
}