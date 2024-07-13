#include "circulo.h"
#include <stdio.h>

float areaCirculo(float raio){
    return PI * raio * raio;
}

float multaPorHectarCirculo(float hect){
    return hect * FATOR_MULTA;
}