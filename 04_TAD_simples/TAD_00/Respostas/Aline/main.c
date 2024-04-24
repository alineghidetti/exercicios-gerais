#include "ponto.h"
#include <stdio.h>

int main(){
    /*
    float x1, y1, x2, y2;
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);
    pto_cria(x1, y1);
    pto_cria(x2, y2);
    */

    float distancia;
    float x, y;
    Ponto p1, p2;
    scanf("%f %f", &x, &y);
    p1 = pto_cria(x, y);
    scanf("%f %f", &x, &y);
    p2 = pto_cria(x, y);

    distancia = pto_distancia(p1, p2);
    printf("%g", distancia);

    
}