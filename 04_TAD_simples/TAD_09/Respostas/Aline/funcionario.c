#include <stdio.h>
#include <string.h>
#include "funcionario.h"

tFuncionario criaFuncionario(int id, float salario){
    tFuncionario fun;
    fun.id = id;
    fun.salario = salario;
    return fun;
}

tFuncionario leFuncionario(){
    int id;
    float salario;
    tFuncionario fun;
    scanf("%d %f", &id, &salario);
    fun = criaFuncionario(id, salario);
    return fun;
}

int getIdFuncionario(tFuncionario funcionario){
    return funcionario.id;
}

void imprimeFuncionario(tFuncionario funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario.id, funcionario.salario);
}