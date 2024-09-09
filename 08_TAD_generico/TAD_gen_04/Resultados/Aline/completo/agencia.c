#include <stdio.h>
#include <stdlib.h> 
#include "agencia.h"

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia{
    int id;
    char *nome;
    Vector *clientes;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){
    tAgencia *agencia = (tAgencia*)calloc(1, sizeof(tAgencia));
    if(agencia == NULL){
        exit(1);
    }

    agencia->nome = NULL;
    agencia->clientes = VectorConstruct();

    return agencia;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){
    tAgencia *a = (tAgencia*)agencia;
    if(a!=NULL){
        VectorDestroy(a->clientes, DestroiConta);
        free(a->nome);
        free(a);
    }
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    scanf("%d;%m[^\n]", &agencia->id, &agencia->nome);
}
/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
    VectorPushBack(agencia->clientes, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if(agencia2->id == numAgencia){
        return 1;
    }
    return 0;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia){
    int tam = VectorSize(agencia->clientes);
    float soma=0, media;

    for (int i=0; i<tam; i++){
        tConta* pessoa = VectorGet(agencia->clientes, i);
        soma+=GetSaldoConta(pessoa);
    }
    media=soma/tam;
    return media;
}
/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia){
    printf("\tNome: %s\n", agencia->nome);
    
    printf("\tNumero: %d\n", agencia->id);

    int total = VectorSize(agencia->clientes);
    printf("\tNumero de contas cadastradas: %d\n", total);

    float media = GetSaldoMedioAgencia(agencia);
    printf("\tSaldo médio: R$%.2f\n\n", media);
}
