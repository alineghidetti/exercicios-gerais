#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

tBiblioteca inicializarBiblioteca(){
    tBiblioteca biblioteca;
    biblioteca.tamanho = 0;
    return biblioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro){
    if(biblioteca.tamanho<MAX_LIVROS){
        biblioteca.livros[biblioteca.tamanho]=livro;
        biblioteca.tamanho++;
        printf("Livro adicionado com sucesso!\n");

    }else{
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }

    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo){
    return(strcmp(livro.titulo, titulo));
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo){
    int i=0, flag=0, j;
    for(i; i<biblioteca.tamanho; i++){
        if(verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo)==0){
            flag=1;
            break;
        }
    }
    if(flag){
        printf("Livro removido com sucesso!\n");
        biblioteca.tamanho--;
        for(j=i; j<biblioteca.tamanho; j++){
            biblioteca.livros[j]=biblioteca.livros[j+1];
        }
    }
    else{
        printf("Livro nao encontrado na biblioteca.\n");
    }
    return biblioteca;
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca){
    int i=0;
    if(biblioteca.tamanho==0){
        printf("A biblioteca esta vazia!\n");
    }else{
        printf("\nLista de Livros na Biblioteca:\n");
        for(i=0; i<biblioteca.tamanho; i++){
            imprimeLivro(biblioteca.livros[i]);
            
        }
    }
}