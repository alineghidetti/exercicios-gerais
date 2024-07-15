#include "empresa.h"

tEmpresa criaEmpresa(int id){
    tEmpresa e;
    e.id = id;
    e.qtdFuncionarios = 0;
    return e;
}

tEmpresa leEmpresa(){
    int id, qtd;
    tEmpresa e;
    tFuncionario funcionario;
    scanf("%d %d", &id, &qtd);
    e = criaEmpresa(id);

    for(int i=0; i<qtd; i++){
        funcionario=leFuncionario();
        e = contrataFuncionarioEmpresa(e, funcionario);
    }
    return e;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int i;

    for(i=0; i<empresa.qtdFuncionarios; i++){
        if(getIdFuncionario(empresa.funcionarios[i])==funcionario.id){
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(funcionario));
            return empresa;
        }
    }
    empresa.qtdFuncionarios++;
    empresa.funcionarios[empresa.qtdFuncionarios-1]=funcionario;
    return empresa;

}

void imprimeEmpresa(tEmpresa empresa){
    printf("Empresa %d:\n", empresa.id);
    for(int i=0; i<empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}