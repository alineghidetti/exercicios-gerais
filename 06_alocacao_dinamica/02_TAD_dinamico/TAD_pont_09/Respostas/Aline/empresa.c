#include "empresa.h"
#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>

tEmpresa* CriaEmpresa(){
    tEmpresa *empresa;
    empresa = (tEmpresa*)calloc(1, sizeof(tEmpresa));
    if(empresa == NULL){
        printf("Erro na alocação de Empresa.");
        exit(1);
    }
    empresa->funcionarios = NULL;
    empresa->qtdFuncionarios = 0;
    return empresa;
}


void LeEmpresa(tEmpresa* empresa){
    int qtdReal=0;
    empresa->qtdFuncionarios=0; //qtdAlocada
    scanf("%d", &empresa->id);
    scanf("%d", &qtdReal);
    empresa->funcionarios = (tFuncionario**)calloc(qtdReal, sizeof(tFuncionario*));
    if (empresa->funcionarios == NULL) {
        printf("Erro ao alocar memória para funcionários.\n");
        exit(1); // Saia do programa se a alocação falhar
    }
    // Aloca e lê cada funcionário
    for (int i = 0; i < qtdReal; ++i) {
        tFuncionario* funcionario = CriaFuncionario();
        LeFuncionario(funcionario);
        ContrataFuncionarioEmpresa(empresa, funcionario);


    }
    empresa->qtdFuncionarios = qtdReal;
}

void ApagaEmpresa(tEmpresa* empresa) {
    int i;
    for(i=0; i<empresa->qtdFuncionarios; i++){
        ApagaFuncionario(empresa->funcionarios[i]);
        
    }
    free(empresa->funcionarios);
    free(empresa);
}


void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario){
    int i=0;
    int flag=0;
    for(i=0; i<empresa->qtdFuncionarios; i++){
        // print("id: %d funcionario %d", i, funcionario->id);
        if(GetIdFuncionario(empresa->funcionarios[i]) == funcionario->id){
            flag=1;
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, funcionario->id);
            ApagaFuncionario(funcionario);
            break;
        }
    }
    if(!flag){
        empresa->funcionarios[i]=funcionario;
        empresa->qtdFuncionarios++;
    }
    // else{
    //     ApagaFuncionario(funcionario);
    // }
}

void ImprimeEmpresa(tEmpresa *empresa){
    printf("Empresa %d:\n", empresa->id);
    for(int i=0; i<empresa->qtdFuncionarios; i++){
        if(empresa->funcionarios[i] != NULL){
            ImprimeFuncionario(empresa->funcionarios[i]);
        }
    }
}