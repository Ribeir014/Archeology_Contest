#include <stdlib.h>
#include <string.h>
#include "equipa.h"
#include "participante.h"

struct _participante{
    char nome[40];
    int pontos;
    int penalizacoes;
    int posicao_x;
    int posicao_y;
    int descf;
    int numEscavacoes;
    int numPenalizacoes;
};

participantes criaParticipante(char *nome){
    participantes p;
    p = (participantes) malloc(sizeof(struct _participante));
    if(p == NULL) 
        return NULL;
    p->pontos=0;
    p->penalizacoes=0;
    p->posicao_x=0; // A posicao de cada participante fica a (0,0)
    p->posicao_y=0;
    p->descf=0; // Se descf for 0, ele continua em jogo, 1 e desclassificado
    p->numEscavacoes = 0;
    p->numPenalizacoes = 0;
    strcpy(p->nome, nome);
    return p;
}

void destroiParticipante(participantes p){
    if(p!=NULL) 
        free(p);
}

void destroiParticipanteGen(void * p){
    destroiParticipante((participantes) p);
}

char *nomeParticipante(participantes p){
    return p->nome;
}

int pontosParticipante(participantes p){
    return p->pontos;
}

int linhaParticipante(participantes p){
    return p->posicao_x;
}

int colunaParticipante(participantes p){
    return p->posicao_y;
}

int numEscavacoesParticipante(participantes p){
    return p->numEscavacoes;
}

void incrementaNumEscavacoesParticipante(participantes p){
    p->numEscavacoes = p->numEscavacoes + 1;
}

int saltoPartcipante(participantes p, int salto_x, int salto_y, int c, int l){
    if(p != NULL){
        if(p->descf != 1){ //Se foi ou nao desclassificado
            p->posicao_x += salto_x;
            p->posicao_y += salto_y;
            if(desclassificadoParticipante(p->posicao_x, p->posicao_y, l-1, c-1) == 1){
                p->descf = 1;
                return 1;
            }
            else 
                return -1;
        }
    }
    return 0;
}
int seFoiDesclassificado(participantes p){
    return p->descf;
}

int desclassificadoParticipante(int local_x, int local_y, int l, int c){
    if(local_x<0 || local_x>l || local_y<0 || local_y>c) 
		return 1;
    else 
		return 0;    
}

void mudaPosicaoLinha(participantes p, int valor){
    p->posicao_x = valor;
}

void mudaPosicaoColuna(participantes p, int valor){
    p->posicao_y = valor;
}

void adicionaPontosParticipante(participantes p, int pontos){
    p->pontos = p->pontos + pontos;         
}

void adicionaPenalizacaoParticipante(participantes p, int penalizacao){
    // a penalizacao tem de ser um numero POSITIVO
    p->penalizacoes = p->penalizacoes + penalizacao;
}

void incrementaNumPenalizacoes(participantes p){
    p->numPenalizacoes = p->numPenalizacoes + 1;
}

int numeroPenalizacoes(participantes p){
    return p->numPenalizacoes;
}