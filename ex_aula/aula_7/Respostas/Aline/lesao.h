#ifndef _LESAO_H
#define _LESAO_H

#define MAX_CARTAO_SUS_LESAO 100
#define MAX_DIAGNOSTICO_LESAO 100
#define MAX_REGIAO_LESAO 100
#define MAX_MALIGNIDADE_LESAO 100

typedef struct{
    int cartao_sus[MAX_CARTAO_SUS_LESAO];
    char diagnostico[MAX_DIAGNOSTICO_LESAO];
    char regiao_corpo[MAX_REGIAO_LESAO];
    float malignidade[MAX_MALIGNIDADE_LESAO];
}tLesao;

tLesao le_lesao();

#endif