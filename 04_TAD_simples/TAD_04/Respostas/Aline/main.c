#include <stdio.h>
#include "aluno.h"
#include <string.h>

int main(){
    int qtd, i, menorid, j, menor;
    
    scanf("%d", &qtd);
    
    tAluno aluno[qtd], aux;

    for(i=0; i< qtd; i++){
        aluno[i] = LeAluno();
    }

    for(i=0; i<qtd; i++){
        menor = aluno[i].matricula;
        menorid = i;
        for(j=i+1; j<qtd; j++){
            if(aluno[j].matricula < menor){
                menor = aluno[j].matricula;
                menorid = j;
            }
        }
        aux = aluno[i];
        aluno[i] = aluno[menorid];
        aluno[menorid] = aux;
    }

	for(i=0; i<qtd; i++){
		if(VerificaAprovacao(aluno[i])){
			ImprimeAluno(aluno[i]);
		}
	}
	return 0;
}