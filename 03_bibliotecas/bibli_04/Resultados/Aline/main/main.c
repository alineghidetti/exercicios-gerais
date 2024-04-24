#include "data.h"
#include <stdio.h>

int main(){
    int ano, mes, dia, aux;
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if(verificaDataValida(dia, mes, ano)== 0){
        printf("A data informada eh invalida");
        return 0;
    }

    printf("Data informada: ");
    imprimeDataExtenso(dia, mes, ano);

    if(verificaBissexto(ano)){
        printf("O ano informado eh bissexto\n");
    }else{
        printf("O ano informado nao eh bissexto\n");
    }

    printf("O mes informado possui %d dias\n", numeroDiasMes(mes, ano));

    printf("A data seguinte eh: ");
    imprimeProximaData(dia, mes, ano);

    return 0;
}