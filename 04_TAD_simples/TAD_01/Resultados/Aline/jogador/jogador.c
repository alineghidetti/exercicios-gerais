#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador) {
    tJogador jogador;

    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    tJogada jogada;

    do {
        printf("Jogador %d\n", jogador.id);
        jogada = LeJogada();

        if(!EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));

        } else if(!EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));

        } else {
            printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }
    } while(!FoiJogadaBemSucedida(jogada) || !EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)) || !EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)));


    if(jogador.id == ID_JOGADOR_1) {
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, PECA_1, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    } else {
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, PECA_2, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    }

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int i;

    for (i = 0; i < TAM_TABULEIRO; i++) {
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 0, jogador.id)
        && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 1, jogador.id)
        && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 2, jogador.id)) return 1;

        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, i, jogador.id)
        && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, i, jogador.id)
        && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, i, jogador.id)) return 1;
    }
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador.id)
    && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id)
    && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador.id)) return 1;

    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador.id)
    && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id)
    && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador.id)) return 1;

    return 0;
}