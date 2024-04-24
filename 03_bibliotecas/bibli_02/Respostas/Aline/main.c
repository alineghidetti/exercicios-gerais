#include "matrix_utils.h"
#include <stdio.h>

int main(){
    int i, j, k, rows1, cols1, rows2, cols2, op=0;
    
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    while(op!=6){
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf("%d", &op);
        if(op==6){
            break;
        }
        if(op==1){
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
                int res1[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, res1);
                matrix_print(rows1, cols1, res1);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        else if(op==2){
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
                int res2[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, res2);
                matrix_print(rows1, cols1, res2);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        else if(op==3){
            if(possible_matrix_multiply(cols1, rows2)){
                int res3[rows1][cols2];
                 matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, res3);
                matrix_print(rows1, cols2, res3);
            }
            else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }
        else if(op==4){
            int escalar, m;
            scanf("%d", &escalar);
            scanf("%d", &m);
            if(m==1){
                scalar_multiply(rows1, cols1, matrix1, escalar);
                matrix_print(rows1, cols1, matrix1);
            }
            else if(m==2){
                scalar_multiply(rows2, cols2, matrix2, escalar);
                matrix_print(rows2, cols2, matrix2);
            }
        }
        else if(op==5){
            int res51[rows1][cols1], res52[rows2][cols2];
            transpose_matrix(rows1, cols1, matrix1, res51);
            matrix_print(cols1, rows1, res51);
            transpose_matrix(rows2, cols2, matrix2, res52);
            matrix_print(cols2, rows2, res52);
        }
    }
    
    return 0;
}