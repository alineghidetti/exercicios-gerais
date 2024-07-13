#include "circulo.h"
#include <stdio.h>

#define CONVERSAO_HEC_M 10000

float converteMetrosHectares(float metros){
    return metros/CONVERSAO_HEC_M;
}

int main(){
    int N, i;
    char tipo;
    float raio, comp, larg, base, altura;
    float area, multa;
    
    scanf("%d", &N);
    
    for(i=0; i<=N; i++){
        scanf("%c", &tipo);
        if(tipo=='C'){
            scanf("%f", &raio);

            area = areaCirculo(raio);
            area = converteMetrosHectares(area);
            multa = multaPorHectarCirculo(area);
        }
    }
    printf("Preço: %.2f\n", multa);
}