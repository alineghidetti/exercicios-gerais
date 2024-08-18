#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int qtd, i;
    scanf("%d\n", &qtd);
    tPessoa pessoas[qtd];
    for(i=0; i<qtd; i++){
        pessoas[i]=CriaPessoa();
        LePessoa(&pessoas[i]);
    }
    
    AssociaFamiliasGruposPessoas(pessoas);

    for(i=0; i<qtd; i++){
        ImprimePessoa(&pessoas[i]);
    }
    return 0;
}