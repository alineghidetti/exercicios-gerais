#include "string_utils.h"
#include <stdio.h>

int string_length(char *str){
    int i;
    for(i=0; i<1000; i++){
        if(str[i] == '\0'){
            i++;
            break;
        }
    }
    return i;
}

void string_copy(char *src, char *dest){
    int i=0, tam;
    tam=string_length(src);
    for(i=0; i<tam; i++){
        dest[i]=src[i];
    }
}

void string_upper(char *str){
    int i, tam;
    tam=string_length(str);
    for(i=0; i<tam; i++){
        if(str[i]>='a'&& str[i]<='z'){
            str[i]-=32;
        }
    }
}

void string_lower(char *str){
    int i, tam;
    tam=string_length(str);
    for(i=0; i<tam; i++){
        if(str[i]>='A'&& str[i]<='Z'){
            str[i]+=32;
        }
    }
}

void string_reverse(char *str){
    int i, j, tam;
    tam = string_length(str);
    char reverse[tam];
    string_copy(str, reverse);
    for(i=tam-2, j=0; i>=0; i--, j++){
        str[j]=reverse[i];
    }
}
