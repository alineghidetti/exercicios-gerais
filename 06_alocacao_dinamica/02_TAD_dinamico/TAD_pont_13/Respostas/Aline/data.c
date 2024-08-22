#include "data.h"
#include <stdio.h>
#include <stdlib.h>

tData* LeData(){
    tData* data;
    data = (tData*)calloc(1, sizeof(tData));
    if (data == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    scanf("%02d/%02d/%04d", &data->dia, &data->mes, &data->ano);
    return data;
}

tData* CriaData(int dia, int mes, int ano){
    tData* data;
    data = (tData*)calloc(1, sizeof(tData));
    if(data == NULL){
        exit(1);
    }

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    return data;
}

void LiberaData(tData* d){
    free(d);
}

int CalculaIdadeData(tData* nascimento, tData* diacalc) {
    int idade = diacalc->ano - nascimento->ano;

    // Verifica se o aniversário já passou no ano da data de cálculo
    if (diacalc->mes < nascimento->mes || 
        (diacalc->mes == nascimento->mes && diacalc->dia < nascimento->dia)) {
        idade--; // Se não passou, subtrai 1 da idade
    }

    return idade;
}

void ImprimeData(tData* d) {
    if (d != NULL) {
        printf("%02d/%02d/%04d\n", d->dia, d->mes, d->ano);
    } else {
        printf("Data inválida.\n");
    }
}
