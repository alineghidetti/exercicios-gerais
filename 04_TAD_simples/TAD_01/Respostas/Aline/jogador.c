#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jofador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    int flag = 1;

    do{
        printf("Jogador %d\n", jogador.id);
        jogada = LeJogada();
    }

}