#include <stdio.h>
#include "string_utils.h"
#define MAX 1000

int main(){
    char string[MAX], copy[MAX];
    scanf("%[^\n]%*c", string);
    int op=0, tam;
    
    while(op!=6){
        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf("%d", &op);
        
        if(op==1){
            tam = string_length(string);
            printf("Tamanho da string: %d\n\n", tam+1);
        }
        else if(op==2){
            string_copy(string, copy);
            printf("String copiada: %s\n\n", copy);

        }
        else if(op==3){
            string_upper(string);
            printf("String convertida para maiusculas: %s\n\n", string);
        }
        else if(op==4){
            string_lower(string);
            printf("String convertida para minusculas: %s\n\n", string);
        }
        else if(op==5){
            string_reverse(string);
            printf("String invertida: %s\n\n", string);
        }
    }
    return 0;
}