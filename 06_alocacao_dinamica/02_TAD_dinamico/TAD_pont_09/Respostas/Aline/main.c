#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main(){
    int n, i;
    scanf("%d", &n);
    tEmpresa **emp;
    emp = (tEmpresa**)calloc(n, sizeof(tEmpresa*));
    for(i=0; i<n; i++){
        emp[i] = CriaEmpresa();
        LeEmpresa(emp[i]);
    }
    for(i=0; i<n; i++){
        ImprimeEmpresa(emp[i]);
        ApagaEmpresa(emp[i]);
    }
    free(emp);
    return 0;
}

/*
int main(){
    int n, i, j, k, flag;
    tFuncionario func;
    
    scanf("%d", &n);
    tEmpresa emp[n];

    for(i=0; i<n; i++){
        emp[i] = leEmpresa();
    }

    for(i=0; i<n; i++){
        imprimeEmpresa(emp[i]);
    }

    return 0;
    */