#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listapessoas.h"
#include "pessoa.h"

int main() {
    ListaPessoa *lista = criaListaPessoa();
    Pessoa *p;
    
    while (1) {
        printf("Digite o nome (ou -1 para sair): ");
        char nome[TAM_NOME];
        scanf("%s", nome);
        if (strcmp(nome, "-1") == 0) {
            break;
        }

        p = lePessoa();
        // Atualizar nome e CPF da Pessoa com os dados lidos
        strcpy(p->nome, nome);

        adicionaPessoaLista(lista, p);
    }

    printf("\nPessoas cadastradas:\n");
    for (int i = 0; i < lista->qtdDados; i++) {
        imprimePessoa(lista->dados[i]);
        liberaPessoa(lista->dados[i]);
    }

    liberaListaPessoa(lista);

    return 0;
}
