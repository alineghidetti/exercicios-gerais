#include "lesao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tLesao* CriaLesao(){
    tLesao *lesao;
    lesao = (tLesao*)calloc(1, sizeof(tLesao));
    if(lesao == NULL){
        exit(1);
    }

    //alocando memoria para strings
    lesao->id = (char*)calloc(TAM_ID, sizeof(char));
    lesao->diagnostico = (char*)calloc(TAM_DIAG, sizeof(char));
    lesao->regiao_corpo = (char*)calloc(TAM_REG, sizeof(char));
    lesao->chance_malignidade = 0;
    return lesao;
}

void LeLesao(tLesao* l){
    if (l == NULL) {
        printf("Ponteiro para lesão é nulo.\n");
        return;
    }
    scanf("%[^\n\n]", l->id);  
    scanf("%*c"); 
    scanf("%[^\n\n]", l->diagnostico);
    scanf("%*c");

    scanf("%[^\n\n]", l->regiao_corpo);
    scanf("%*c");

    scanf("%d", &l->chance_malignidade);
    scanf("%*c");

}

void LiberaLesao(tLesao* l){
    if(l!=NULL){
        free(l->id);
        free(l->diagnostico);
        free(l->regiao_corpo);
        free(l);
    }
}

char* GetIdLesao(tLesao* l){
    return l->id;
}

int PrecisaCirurgiaLesao(tLesao* l) {
    if (l == NULL) {
        // Se o ponteiro é nulo, não podemos determinar se precisa de cirurgia
        return 0;
    }

    // Defina o limiar de chance de malignidade para cirurgia
    const int LIMIAR_MALIGNIDADE = 50; // Exemplo de limiar; ajuste conforme necessário

    // Retorna 1 se a chance de malignidade for maior ou igual ao limiar, caso contrário, retorna 0
    return l->chance_malignidade >= LIMIAR_MALIGNIDADE;
}
