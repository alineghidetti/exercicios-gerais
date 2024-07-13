#include <stdio.h>
#include "lesao.h"

tLesao le_lesao(){
    tLesao lesao;
    scanf("%d", &lesao.cartao_sus);
    scanf("%s", lesao.diagnostico);
    scanf("%s", lesao.regiao_corpo);
    scanf("%f", &lesao.malignidade);
    return lesao;
}
