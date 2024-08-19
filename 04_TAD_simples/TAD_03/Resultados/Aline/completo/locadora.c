#include "locadora.h"

tLocadora criarLocadora (){
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;
    return locadora;
}

int verificaFilmeCadastrado(tLocadora locadora, int codigo) {
    int f;

    for (f = 0; f < locadora.numFilmes; f++) {
        if (obterCodigoFilme(locadora.filme[f]) == codigo) {
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme) {
    if (verificaFilmeCadastrado(locadora, filme.codigo)) {
        printf("Filme ja cadastrado no estoque\n");
    }else {
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes += 1;

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
    int i, j;
    int flag=0, custo=0, alugados=0;
    for(i=0; i<quantidadeCodigos; i++){
        flag=0;
        for(j=0; j<locadora.numFilmes; j++){
            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){
                flag=1;

                if(obterQtdEstoqueFilme(locadora.filme[j])){
                    locadora.filme[j]=alugarFilme(locadora.filme[j]);
                    custo+=obterValorFilme(locadora.filme[j]);
                    alugados++;
                }
                else{
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");                    
                }
                break;
            }
        }
    }
    if(!(flag)){
        printf("Filme %d nao cadastrado.\n", codigos[i]);
    }
    if(alugados){
        printf("Total de filmes alugados: %d com custo de R$%d\n", alugados, custo);
    }
    return locadora;
}


tLocadora lerAluguelLocadora(tLocadora locadora) {
    int codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];

    while(scanf("%d\n", &codigo) == 1) {
        codigosFilmes[qtdCodigos] = codigo;
        qtdCodigos++;
    }
    locadora = alugarFilmesLocadora(locadora, codigosFilmes, qtdCodigos);

    return locadora;
}


tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    int flag=0;
    for(i=0; i<quantidadeCodigos; i++){
        flag=0;
        for(j=0; j<locadora.numFilmes; j++){
            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){
                flag=1;

                if(obterQtdAlugadaFilme(locadora.filme[j])){
                    locadora.filme[j]=devolverFilme(locadora.filme[j]);
                    locadora.lucro+=obterValorFilme(locadora.filme[j]);
                    printf("Filme %d - ", codigos[i]);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" Devolvido!\n");
                }
                else{
                    printf("Nao e possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                }
                break;
            }
        }
        if(!(flag)){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
    return locadora;
}

tLocadora lerDevolucaoLocadora(tLocadora locadora) {
    int codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];

    while(scanf("%d\n", &codigo) == 1) {
        codigosFilmes[qtdCodigos] = codigo;
        qtdCodigos++;
    }
    locadora = devolverFilmesLocadora(locadora, codigosFilmes, qtdCodigos);

    return locadora;
}

tLocadora ordenarFilmesLocadora (tLocadora locadora){
    int i, j;
    tFilme aux;

    for(i=0; i<locadora.numFilmes-1; i++){
        for(j=i+1; j<locadora.numFilmes; j++){
            if(compararNomesFilmes(locadora.filme[i], locadora.filme[j])>0){
                aux=locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j]=aux;
            }
        }
    }
    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora){
    int i, estoque;
    printf("~ESTOQUE~\n");

    for(i=0; i<locadora.numFilmes; i++){
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
        estoque += obterQtdEstoqueFilme(locadora.filme[i]);
    }
}

void consultarLucroLocadora (tLocadora locadora){
    if(locadora.lucro>0){
        printf("\nLucro total R$%d\n", locadora.lucro);
    }
}
