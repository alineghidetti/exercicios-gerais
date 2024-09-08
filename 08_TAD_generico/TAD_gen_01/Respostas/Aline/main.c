#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main(){
    int numElem;
    int type;
    printf("tad_gen_01\nDigite o tipo e numero de elementos: ");
    scanf("%d %d", &type, &numElem);

    tGeneric *gen = CriaGenerico(type, numElem);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);

    return 0;
}