#include "utils_char2.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char *v = CriaVetorTamPadrao();
    int tamanho = 10;
    v = LeVetor(v, &tamanho);
    ImprimeString(v);
    LiberaVetor(v);
    
    return 0;
}