#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"
#include <stdio.h>

tEleicao InicializaEleicao(){
	tEleicao eleicao;
	tCandidato cand;
	int totalc, i, p=0, g=0;
	eleicao.totalPresidentes = 0;
	eleicao.totalGovernadores = 0;
	eleicao.votosBrancosPresidente = 0;
	eleicao.votosNulosPresidente = 0;
	eleicao.votosBrancosGovernador = 0;
	eleicao.votosNulosGovernador = 0;
	scanf("%d", &totalc);
	for(i=0; i<totalc; i++){
		cand = LeCandidato();
		if(ObtemCargo(cand) == 'P'){
			eleicao.totalPresidentes++;
			eleicao.presidentes[p] = cand;
			p++;
		}
		else if(ObtemCargo(cand) == 'G'){
			eleicao.totalGovernadores++;
			eleicao.governadores[g] = cand;
			g++;
		}
	}
	return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
	int i, p, g, j;
	tEleitor eleitor;
	scanf("%d", &eleicao.totalEleitores);
	for(i=0; i<eleicao.totalEleitores; i++){
		eleicao.eleitores[i] = LeEleitor();
		p = ObtemVotoPresidente(eleicao.eleitores[i]);
		g = ObtemVotoGovernador(eleicao.eleitores[i]);
		for(j=0; j<eleicao.totalPresidentes; j++){
			if(VerificaIdCandidato(eleicao.presidentes[j], p)){
				eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
				break;
			}
			if(j == eleicao.totalPresidentes-1){
				if(p == 0){
					eleicao.votosBrancosPresidente++;
				}else{
					eleicao.votosNulosPresidente++;
				}
			}
		}
		for(j=0; j<eleicao.totalGovernadores; j++){
			if(VerificaIdCandidato(eleicao.governadores[j], g)){
				eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
				break;
			}
			if(j == eleicao.totalGovernadores-1){
				if(g == 0){
					eleicao.votosBrancosGovernador++;
				}else{
					eleicao.votosNulosGovernador++;
				}
			}
		}
	}
    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao){
    int i, j, maiorp=0, maiorip=-1, maiorg=0, maiorig=-1, empatep = 0, empateg = 0, anulada = 0;
    for(i=0; i<eleicao.totalEleitores; i++){
        for(j=i+1; j<eleicao.totalEleitores; j++){
            if(EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])){
                anulada = 1;
            }
        }
    }
    if(eleicao.totalEleitores>10){
        anulada = 1;
    }
    if(eleicao.totalPresidentes>3){
        anulada = 1;
    }
    if(eleicao.totalGovernadores>3){
        anulada = 1;
    }
    if(anulada == 1){
        printf("ELEICAO ANULADA\n");
    }
    else{
        for(i=0; i<eleicao.totalPresidentes; i++){
            if(ObtemVotos(eleicao.presidentes[i]) > maiorp){
                maiorp =ObtemVotos(eleicao.presidentes[i]);
                maiorip = i;
            }
        }
        for(i=0; i<eleicao.totalPresidentes; i++){
            if(ObtemVotos(eleicao.presidentes[i]) == maiorp){
                if(EhMesmoCandidato(eleicao.presidentes[maiorip], eleicao.presidentes[i])==0){
                    empatep = 1;
                }
            }
        }
        for(i=0; i<eleicao.totalGovernadores; i++){
            if(ObtemVotos(eleicao.governadores[i]) > maiorg){
                maiorg =ObtemVotos(eleicao.governadores[i]);
                maiorig = i;
            }
        }
        for(i=0; i<eleicao.totalGovernadores; i++){
            if(ObtemVotos(eleicao.governadores[i]) == maiorg){
                if(EhMesmoCandidato(eleicao.governadores[maiorig], eleicao.governadores[i])==0){
                    empateg = 1;
                }
            }
        }
        printf("- PRESIDENTE ELEITO: ");
        if(empatep == 1){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
        else if(maiorp < (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)){
            printf("SEM DECISAO\n");
        }
        else{
            float perc;
            int totalp;
            totalp = eleicao.totalEleitores;
            perc = CalculaPercentualVotos(eleicao.presidentes[maiorip], totalp);
            ImprimeCandidato(eleicao.presidentes[maiorip], perc);
        }
        printf("- GOVERNADOR ELEITO: ");
        if(empateg == 1){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
        else if(maiorg < (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)){
            printf("SEM DECISAO\n");
        }
        else{
            float perc;
            int totalg;
            totalg = eleicao.totalEleitores;
            perc = CalculaPercentualVotos(eleicao.governadores[maiorig], totalg);
            ImprimeCandidato(eleicao.governadores[maiorig], perc);
        }
        int tnulo, tbranco;
        tnulo = eleicao.votosNulosGovernador + eleicao.votosNulosPresidente;
        tbranco = eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente;
        printf("- NULOS E BRANCOS: %d, %d", tnulo, tbranco);
    }
}