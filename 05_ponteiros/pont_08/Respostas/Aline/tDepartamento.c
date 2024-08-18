#include "tDepartamento.h"
#include <stdio.h>
#include <string.h>

tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento depto;
    strncpy(depto.curso1, curso1, STRING_MAX - 1);   
    strncpy(depto.curso2, curso2, STRING_MAX - 1);
    strncpy(depto.curso3, curso3, STRING_MAX - 1);
    strncpy(depto.nome, nome, STRING_MAX - 1);
    depto.m1 = m1;
    depto.m2 = m2;
    depto.m3 = m3;
    strncpy(depto.diretor, diretor, STRING_MAX - 1);
    return depto;
}

void ImprimeAtributosDepartamento(tDepartamento depto){
    printf("Departamento: %s\n", depto.nome);
    printf("	Diretor: %s\n", depto.diretor);
    printf("	1o curso: %s\n", depto.curso1);
    printf("	Media do 1o curso: %d\n", depto.m1);
    printf("	2o curso: %s\n", depto.curso2);
    printf("	Media do 2o curso: %d\n", depto.m2);
    printf("	3o curso: %s\n", depto.curso3);
    printf("	Media do 3o curso: %d\n", depto.m3);
    printf("	Media dos cursos: %.2f\n", ((float)depto.m1+(float)depto.m2+(float)depto.m3)/3);
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos) {
    for (int i = 0; i < num_deptos - 1; i++) {
        for (int j = 0; j < num_deptos - i - 1; j++) {
            // Calculando as médias diretamente na função de ordenação
            float media1 = (vetor_deptos[j].m1 + vetor_deptos[j].m2 + vetor_deptos[j].m3) / 3.0;
            float media2 = (vetor_deptos[j + 1].m1 + vetor_deptos[j + 1].m2 + vetor_deptos[j + 1].m3) / 3.0;

            if (media1 < media2) {
                // Troca os departamentos
                tDepartamento temp = vetor_deptos[j];
                vetor_deptos[j] = vetor_deptos[j + 1];
                vetor_deptos[j + 1] = temp;
            }
        }
    }
}