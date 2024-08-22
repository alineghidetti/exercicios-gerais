#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>

tFuncionario* CriaFuncionario(){
    tFuncionario* func;
    func = (tFuncionario*)calloc(1, sizeof(tFuncionario));
    if(func == NULL){
        printf("ERRO NA ALOCAÇÃO DE FUNCIONÁRIO.");
        exit(1);
    }
    return func;
}

void ApagaFuncionario(tFuncionario* funcionario){
    free(funcionario);
}

void LeFuncionario(tFuncionario* funcionario){
    scanf("%d %f", &funcionario->id, &funcionario->salario);
}

int GetIdFuncionario(tFuncionario* funcionario){
    return funcionario->id;
}

void ImprimeFuncionario(tFuncionario* funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario->id, funcionario->salario);
}
