#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#define MAX_NOME 5

tAluno* CriaAluno(){
    tAluno* aluno;
    aluno = (tAluno*)calloc(1, sizeof(tAluno));
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;
    aluno->matricula = -1;

    return aluno;
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno){
    int i = 0;
    char c;
    while(1){
        scanf("%c", &c);
        i++;
        aluno->nome = realloc(aluno->nome, i*sizeof(char));
        if(c == '\n'){
            aluno->nome[i-1] = '\0';
            break;
        }
        aluno->nome[i-1] = c;
    }
    scanf("%d%*c", &(aluno->matricula));
    scanf("%d %d %d%*c", &(aluno->n1), &(aluno->n2), &(aluno->n3));
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula > aluno2->matricula){
        return 1;
    }
    else if(aluno1->matricula < aluno2->matricula){
        return -1;
    }
    return 0;
}

int CalculaMediaAluno(tAluno* aluno){
    int total = 0;
    total += aluno->n1;
    total += aluno->n2;
    total += aluno->n3;
    total = total/3;
    return total;
}

int VerificaAprovacao(tAluno* aluno){
    if(CalculaMediaAluno(aluno) >= 7){
        return 1;
    }
    return 0;
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}