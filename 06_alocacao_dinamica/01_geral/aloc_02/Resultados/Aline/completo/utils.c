#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int **CriaMatriz(int linhas, int colunas) {
    int **mat =(int**) calloc(linhas, sizeof(int*));
    int i;
    for (i = 0; i < linhas; i++) {
        mat[i] = calloc(colunas, sizeof(int));
    }
    if (mat == NULL) {
        exit(1);
    }
    return mat;
}

void LiberaMatriz(int **matriz, int linhas){
    int i;
    for(i=0; i<linhas; i++){
        free(matriz[i]);
    }

    free(matriz);
}

void LeMatriz(int **matriz, int linhas, int colunas){
    int i, j;
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas){
    int i, j;
    for(j=0; j<colunas; j++){
        for(i=0; i<linhas; i++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}