#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam, *v;
    float media;
    scanf("%d", &tam);
    v = CriaVetor(tam);
    LeVetor(v, tam);
    media = CalculaMedia(v, tam);
    printf("%.2f", media);
    LiberaVetor(v);
    return 0;
}