#include <stdio.h>
#include "livro.h"
#include "biblioteca.h"

int main(){
    int n, opc, i=0;
    tBiblioteca biblioteca;
    tLivros livro;
    char titulo[100];

    scanf("%d", &n);
    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");
    biblioteca = inicializarBiblioteca();

    for(i=0; i<n; i++){
        scanf("%d", &opc);

        if(opc == 1){
            livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
        }
        else if(opc == 2){
            scanf("%s", titulo);
            biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
        }
        else if(opc == 3){
            listarLivrosDaBiblioteca(biblioteca);
        }
        else{
            printf("\nOperacao invalida!\n");
            return 1;
        }
    }
    return 0;
}