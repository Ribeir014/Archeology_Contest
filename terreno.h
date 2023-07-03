#ifndef TERRENO_H_
#define TERRENO_H_
#include "talhao.h" //porque ha uma funcao que devolve um tipo talhao

/* Tipo de dados: terreno ---> ter[1], ter[2], ter[3] ....*/
typedef struct _terreno *terreno;

/***********************************************
criaTerreno - Criacao da instancia da estrutura associada a uma terreno.
Parametros:
	ter - terreno a que se vai reservar espaco na memoria
    l - numero de linhas do terreno
    c - numero de colunas do terreno
Retorno: apontador para a  instancia criada
Pre-condicoes: ter != NULL
***********************************************/
terreno criaTerreno(terreno ter, int l, int c);

/***********************************************
destroiTerreno - Liberta a memoria ocupada pela instancia da estrutura associada ao terreno.
Parametros:
	ter - terreno a destruir
Retorno:
Pre-condicoes: 
***********************************************/
void destroiTerreno(terreno ter);

/***********************************************
preenchePosicaoTalhao - Cria um talhao e coloca na posicao da matriz do terreno.
Parametros:
	t - terreno a aceder
    linha - posicao da linha da matriz terreno
    coluna - posicao da coluna da matriz terreno
    tesouro - tesouro a colocar no talhao
Retorno:
Pre-condicoes: 
***********************************************/
void preenchePosicaoTalhao(terreno t, int linha, int coluna, int tesouro);

/***********************************************
preencheTalhao - Criacao da instancia da estrutura associada ao talhao.
Parametros:
	tesouro - tesouro a guardar no talhao
Retorno: apontador para a  instancia criada
Pre-condicoes: 
***********************************************/
talhao preencheTalhao(int tesouro);

/***********************************************
escreverMatrizSinais - Devolve 1 se o talhao da matriz terreno tiver tesouro ou 0 se nao tiver tesouro.
Parametros:
	ter - terreno a aceder
    l - linha do tesouro
    c - coluna do tesouro
Retorno: 1 se houver tesouro ou 0 se nao houver
Pre-condicoes: 
***********************************************/
int escreverMatrizComSinais(terreno ter, int l, int c);

/***********************************************
riquezaTotal - Soma todos os tesouros da matriz terreno e guarda na variavel do tesouro total do terreno.
Parametros:
	ter - terreno a aceder
Retorno: 
Pre-condicoes: 
***********************************************/
void riquezaTotal(terreno ter);

/***********************************************
riquezaTotalParaRiquezaAtual - Passa o tesouro total para o tesouro atual nas variaveis da estrutura terreno.
Parametros:
	ter - terreno a aceder
Retorno:
Pre-condicoes: 
***********************************************/
void riquezaTotalParaRiquezaAtual(terreno ter);

/***********************************************
retiraRiquezaTerreno - Retira o tesouro da riqueza atual.
Parametros:
	ter - terreno a aceder
    tesouroRetirado - tesouro que foi escavado e vai ser retirado do terreno
Retorno:
Pre-condicoes: 
***********************************************/
void retiraRiquezaTerreno(terreno ter, int tesouroRetirado);

/***********************************************
daRiquezaAtual - Retorna a variavel riqueza atual do terreno.
Parametros:
	ter - terreno a aceder
Retorno: inteiro riqueza atual do terreno
Pre-condicoes: 
***********************************************/
int daRiquezaAtual(terreno ter);

/***********************************************
linhasTerreno - Retorna a variavel linhas do terreno.
Parametros:
	ter - terreno a aceder
Retorno: inteiro linhas do terreno
Pre-condicoes: 
***********************************************/
int linhasTerreno(terreno ter);

/***********************************************
linhasTerreno - Retorna a variavel colunas do terreno.
Parametros:
	ter - terreno a aceder
Retorno: inteiro colunas do terreno
Pre-condicoes: 
***********************************************/
int colunasTerreno(terreno ter);

/***********************************************
valorTesouroTalhao - Retorna a variavel tesouro, que esta no talhao da matriz do terreno.
Parametros:
	ter - terreno a aceder
    linha - posicao da linha do tesouro na matriz terreno.
    coluna - posicao da coluna do tesouro na matriz terreno.
Retorno: inteiro tesouro na talhao do terreno
Pre-condicoes: 
***********************************************/
int valorTesouroTalhao(terreno ter, int linha, int coluna);

/***********************************************
daTalhaoDoTerreno - Retorna o talhao da matriz terreno na posicao (linha, coluna).
Parametros:
	ter - terreno a aceder
    linha - posicao da linha na matriz terreno.
    coluna - posicao da coluna na matriz terreno.
Retorno: apontador para o talhao de posicao (linha, coluna)
Pre-condicoes: 
***********************************************/
talhao daTalhaoDoTerreno(terreno ter, int linha, int coluna);
#endif