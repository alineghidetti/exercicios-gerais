#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro(){
	int i, j;
	tTabuleiro tab;
	tab.peca1 = 'X';
	tab.peca2 = '0';
	tab.pecaVazio = '-';
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			tab.posicoes[i][j] = tab.pecaVazio;
		}
	}
	return tab;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
	if(peca == 1){
		tabuleiro.posicoes[x][y] = tabuleiro.peca1;
	}
	else if(peca == 2){
		tabuleiro.posicoes[x][y] = tabuleiro.peca2;
	}
	return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
				return 1;
			}
		}
	}
	return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
	if(peca == 1){
		if(tabuleiro.posicoes[x][y] == tabuleiro.peca1){
			return 1;
		}
	}
	else if(peca == 2){
		if(tabuleiro.posicoes[x][y] == tabuleiro.peca2){
			return 1;
		}
	}
	return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
	if(tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio){
		return 1;
	}
	return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y){
	if(x<3 && x>=0 && y<3 && y>=0){
		return 1;
	}
	return 0;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
	int i, j;
	for(i=0; i<3; i++){
		printf("\t");
		for(j=0; j<3; j++){
			printf("%c", tabuleiro.posicoes[i][j]);
		}
		printf("\n");
	}
}