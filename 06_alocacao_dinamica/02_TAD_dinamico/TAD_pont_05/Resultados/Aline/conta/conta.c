#include "conta.h"
#include <stdlib.h>
#include <stdio.h>

tConta *CriaConta(){
    tConta *conta;
    conta = (tConta*)calloc(1, sizeof(tConta));
    if(conta == NULL){
        exit(1);
    }
    return conta;
}

void DestroiConta(tConta *conta){
    DestroiUsuario(conta->user);
    free(conta);
}

void LeConta(tConta *conta) {
    // Verifica se já existe um usuário alocado e o destrói antes de ler um novo
    if (conta->user != NULL) {
        DestroiUsuario(conta->user);  // Libera a memória do usuário anterior
    }

    tUsuario *user = CriaUsuario();
    LeUsuario(user);
    conta->user = user;  // Associa o novo usuário à conta
    
    scanf("%d", &conta->numero);
}

void ImprimeConta(tConta *conta) {
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero) {
    if (conta->numero == numero){
        return 1;
    }
    return 0;
}

void SaqueConta(tConta *conta, float valor) {
    conta->saldo -= valor;
}

void DepositoConta(tConta *conta, float valor)  {
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    origem->saldo -= valor;
    destino->saldo += valor;
}