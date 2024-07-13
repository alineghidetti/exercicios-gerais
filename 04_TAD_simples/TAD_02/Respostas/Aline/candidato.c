#include "candidato.h"
#include <stdio.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;
    int i;
    for(i=0; i<50; i++){
        candidato.nome[i] = nome[i];
    }
    for(i=0; i<50; i++){
        candidato.partido[i] = partido[i];
    }
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;
    return candidato;
}


tCandidato LeCandidato(){
    tCandidato candidato;
    char nome[50], partido[50], cargo;
    int id;
    scanf("%*c%[^,], %[^,], %c, %d", nome, partido, &cargo, &id);
    candidato = CriaCandidato(nome, partido, cargo, id);
    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id){
    if(candidato.id == id){
        return 1;
    }
    return 0;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    if (candidato1.id == candidato2.id){
        return 1;
    }
    return 0;
}

char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    float percentual;
    percentual = (float)(candidato.votos)/(totalVotos);
    percentual = percentual*100;
    return percentual;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s (%s), %d voto(s), %.2f\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}
