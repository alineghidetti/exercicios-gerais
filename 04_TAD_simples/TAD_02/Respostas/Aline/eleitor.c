#include "eleitor.h"
#include <stdio.h>

tEleitor CriaEleitor(int id, int votoP, int votoG){
    tEleitor eleitor;
    eleitor.id = id;
    eleitor.votoP = votoP;
    eleitor.votoG = votoG;
    return eleitor;
}

tEleitor LeEleitor(){
    tEleitor eleitor;
    int id, votoP, votoG;
    scanf("%d %d %d", &id, &votoP, &votoG);
    eleitor = CriaEleitor(id, votoP, votoG);
    return eleitor;
}

int ObtemVotoPresidente(tEleitor eleitor){
    int voto;
    voto = eleitor.votoP;
    return voto;
}

int ObtemVotoGovernador(tEleitor eleitor){
    int voto;
    voto = eleitor.votoG;
    return voto;
}

int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2){
    if(eleitor1.id == eleitor2.id){
        return 1;
    }
    return 0;
}