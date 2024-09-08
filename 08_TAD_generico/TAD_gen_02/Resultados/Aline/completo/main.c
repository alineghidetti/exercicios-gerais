#include "gerenciadorpacotes.h"
#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

void Menu(){
    printf("\nEscolha uma opcao:\n\t(1) Cadastrar um novo pacote\n\t(2) Imprimir um pacote específico\n\t(3) Imprimir todos os pacotes e sair\n");
}

int main(){
    int op;
    tGerenciador* geren = CriaGerenciador();
    printf("tad_gen_02\n");
    while(1){
        Menu();
        if(scanf("%d%*c", &op) == 1){
            if(op == 1){
                int tam, tipo;
                Type tp;
                printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
                scanf("%d %d", &tipo, &tam);
                if(tipo == 0){
                    tp = 2;
                }
                else if(tipo == 1){
                    tp = 1;
                }
                if(tipo != 0 && tipo != 1){
                    printf("\nDigite um tipo valido!\n");
                }else{
                    tPacote* pacote = CriaPacote(tp, tam);
                    LePacote(pacote);
                    AdicionaPacoteNoGerenciador(geren, pacote);
                }
            }
            else if(op == 2){
                int indice;
                printf("Digite o índice do pacote: \n");
                scanf("%d%*c", &indice);
                ImprimirPacoteNoIndice(geren, indice);
            }
            else if(op == 3){
                ImprimirTodosPacotes(geren);
                break;
            }
            else{
                printf("Escolha uma opcao valida para o menu!\n");
            }
        }
    }
    DestroiGerenciador(geren);
    return 0;
}