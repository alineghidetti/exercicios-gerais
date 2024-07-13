#include "livro.h"
#include <stdio.h>

tLivros lerLivro(){
    tLivros livro;
    scanf("%s", livro.titulo);
    scanf("%s", livro.autor);
    scanf("%d", &livro.anoPublicacao);
    return livro;
}

void imprimeLivro(tLivros livro){
    printf("Titulo: %s\nAutor: %s\nAno de Publicacao: %d\n", livro.titulo, livro.autor, livro.anoPublicacao);
}