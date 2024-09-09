#include "relatorio.h"
#include "vector.h"
#include "aluno.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos){
    // Media das notas: 7.05
    // Porcentagem de alunos aprovados: 75.00%
    // Porcentagem de cada genero:
    // Masculino: 25.00%
    // Feminino: 25.00%
    // Outro: 50.00%
    int total = VectorSize(alunos);
    float media=0, fem=0, mas=0, outro=0, soma=0, aprov=0;

    for(int i=0; i<total; i++){
        tAluno *aluno = (tAluno*)VectorGet(alunos, i);
        soma += GetNotaAluno(aluno);

        if (GetGeneroAluno(aluno)=='F'){
            fem++;
        }
        else if (GetGeneroAluno(aluno)=='M'){
            mas++;
        }
        else{
            outro++;
        }
        if(GetNotaAluno(aluno)>=6){
            aprov++;
        }
}
    media = soma/total;
        // Imprime o relatório
    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (aprov/total)*100);  // Função que calcula a porcentagem de aprovados
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", (mas / total) * 100);
    printf("Feminino: %.2f%%\n", (fem / total) * 100);
    printf("Outro: %.2f%%\n", (outro / total) * 100);
}
