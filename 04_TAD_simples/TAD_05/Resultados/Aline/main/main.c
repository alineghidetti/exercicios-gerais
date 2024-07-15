#include <stdio.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"

int main(){
    int qtd, opc, i, id, c=0;
    float valor;

    scanf("%d", &qtd);

    tConta conta[qtd];
    tUsuario usuario[qtd];

    do{
        scanf("%d", &opc);
        if(opc==1){
            scanf("%d %f", &id, &valor);
            for(i=0; i<c; i++){
                if(VerificaConta(conta[i], id)){
                    conta[i]=SaqueConta(conta[i], valor);
                    break;
                }
            }
        }
        else if(opc==2){
            scanf("%d %f", &id, &valor);
            for(i=0; i<c; i++){
                if(VerificaConta(conta[i], id)){
                    conta[i]=DepositoConta(conta[i], valor);
                    break;
                }
            }            
        }
        else if(opc==3){
            char nome[20], cpf[15];
            int numero;
            scanf("%s %s %d", nome, cpf, &numero);
            if(c<qtd){
                usuario[c]=CriaUsuario(nome, cpf);
                conta[c]=CriaConta(numero, usuario[c]);
                c++;
            }
        }
        else if(opc==4){
            printf("===| Imprimindo Relatorio |===\n");
            for(i=0; i<c; i++){
                ImprimeConta(conta[i]);
                printf("\n");
            }
        }

    }while(opc!=0);
     
    return 0;


    
}