#include "filme.h"
#include "locadora.h"

tLocadora criarLocadora (){
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;
    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    int i=0;
    for(i=0; i<locadora.numFilmes; i++){
        if(locadora.filme[i].codigo == codigo){
            return 1;
        }
        return 0;
    }
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    if(verificarFilmeCadastrado(locadora, filme.codigo)){
        printf("Filme ja cadastrado no estoque\n");    
    }
    else{
        locadora.filme[locadora.numFilmes]=filme;
        locadora.numFilmes++;

        printf("Filme cadastrado %d - %s\n", filme.codigo, filme.nome);
    }
    return locadora;
}

tLocadora lerCadastroLocadora(tLocadora locadora) {
    int codigo;
    tFilme filme;

    while(scanf("%d,", &codigo) == 1) {

        filme = leFilme(codigo);

        locadora = cadastrarFilmeLocadora(locadora, filme);
    }

    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i=0, j=0;
    for(i=0; i<quantidadeCodigos; i++){
        if(verificarFilmeCadastrado(locadora, codigos[i])){
            for(j=0; j<locadora.numFilmes; j++){
                if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){
                    alugarFilme(locadora.filme[j]);
                }
            }
        }
    }
    return locadora;
}
