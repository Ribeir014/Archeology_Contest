#include <stdlib.h>
#include <string.h>
#include "equipa.h"
#include "participante.h"
#include "terreno.h"

struct _terreno{
    talhao **matriz_terreno;
    int tesouro_total;
    int tesouro_atual;
    int linhas;
    int colunas;
};

terreno criaTerreno(terreno ter, int l, int c){
    int i;

    ter = (terreno)malloc(sizeof(struct _terreno));

    ter->matriz_terreno = (talhao**)malloc (l * sizeof (talhao));

    for (i=0; i < l; i++)
        ter->matriz_terreno[i] = (talhao*)malloc (c * sizeof (talhao));

    ter->colunas = c;
    ter->linhas = l;
    ter->tesouro_atual = 0;
    ter->tesouro_total = 0;

    return ter;
}

void destroiTerreno(terreno ter){

    for(int i = 0; i<ter->linhas ; i++){
        for(int j = 0; j<ter->colunas; j++){
            destroiTalhao(ter->matriz_terreno[i][j]);
        }
    }

    free(ter);
}

void preenchePosicaoTalhao(terreno t, int linha, int coluna, int tesouro){
    t->matriz_terreno[linha][coluna]=criarTalhao(tesouro);
}

talhao  preencheTalhao(int tesouro){
    talhao t = criarTalhao(tesouro);
    return t;
}

int escreverMatrizComSinais(terreno ter, int l, int c){ 
    if(tesouroTalhao(ter->matriz_terreno[l][c]) > 0)
        return 1; 
    else
        return 0; 
}

void riquezaTotal(terreno ter){
    int tesouroTotal = 0;

    for(int i=0;i<ter->linhas;i++){
        for(int j=0;j<(ter->colunas);j++){
            tesouroTotal = tesouroTotal + tesouroTalhao(ter->matriz_terreno[i][j]);
        }
    }
    ter->tesouro_total = tesouroTotal;
}

void riquezaTotalParaRiquezaAtual(terreno ter){
    ter->tesouro_atual = ter->tesouro_total;
}

void retiraRiquezaTerreno(terreno ter, int tesouroRetirado){
    ter->tesouro_atual = ter->tesouro_atual - tesouroRetirado;
}

int daRiquezaAtual(terreno ter){
    return ter->tesouro_atual;
}

int linhasTerreno(terreno ter){
    return ter->linhas;
}                                                                                        

int colunasTerreno(terreno ter){
    return ter->colunas;
}

int valorTesouroTalhao(terreno ter, int linha, int coluna){
    return tesouroTalhao(ter->matriz_terreno[linha][coluna]);
}

talhao daTalhaoDoTerreno(terreno ter, int linha, int coluna){
    return ter->matriz_terreno[linha][coluna];
}
                                                                                                