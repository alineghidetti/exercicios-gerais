#include "data.h"
#include <stdio.h>

int main(){
    int ano1, mes1, dia1, ano2, mes2, dia2, aux;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if(verificaDataValida(dia1, mes1, ano1)== 0|| verificaDataValida(dia2, mes2, ano2)==0 ){
        printf("A primeira e/ou segunda data(s) invalida(s)");
        return 0;
    }

    printf("Primeira data: ");
    imprimeDataExtenso(dia1, mes1, ano1);
    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);

    aux = comparaData( dia1, mes1, ano1, dia2, mes2, ano2);
    if(aux == 1){
    	printf("A segunda data eh mais antiga\n");
    }
    else if(aux == -1){
    	printf("A primeira data eh mais antiga\n");
    }
    else if(aux == 0){
    	printf("As datas sao iguais\n");
    }

    aux = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);
    printf("A diferenca em dias entre as datas eh: %02d dias\n", aux);
    return 0;
}