#include "usuario.h"
#include <stdio.h>

tUsuario* CriaUsuario(){
    tUsuario *user;
    user = (tUsuario*)calloc(1, sizeof(tUsuario));
    if (user == NULL) {
        printf("Alocacao impropria em usuario.c\n");
        exit(1);
    }
    return user;    
}

void DestroiUsuario(tUsuario *user){
    free(user);
}

void LeUsuario(tUsuario *user){
    scanf("%s", user->nome);
    scanf("%s", user->cpf);
}

void ImprimeUsuario(tUsuario *user) {
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n\n", user->cpf);
}