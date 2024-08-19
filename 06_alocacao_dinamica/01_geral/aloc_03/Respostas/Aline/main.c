#include <stdio.h>
#include "utils_char.h"

int main(){
    char *v;
    int tam;
    scanf("%d\n", &tam);
    v = CriaVetor(tam);
    ImprimeString(v, tam);
    LeVetor(v, tam);
    ImprimeString(v, tam);
    LiberaVetor(v);
    return 0;
}