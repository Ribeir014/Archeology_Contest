#ifndef TALHAO_H_
#define TALHAO_H_

/* Tipo de dados: talhao ---> t[1], t[2], t[3] ....*/
typedef struct _talhao *talhao;

/***********************************************
criarTalhao - Criacao da instancia da estrutura associada a um talhao.
Parametros:
	tesouro - pontos do talhao
Retorno: apontador para a  instancia criada
Pre-condicoes: t != NULL
***********************************************/
talhao criarTalhao(int tesouro);

/***********************************************
destroiTalhao - Liberta a memoria ocupada pela instancia da estrutura associada a um talhao.
Parametros:
	t - talhao a destruir
Retorno:
Pre-condicoes: t != NULL
***********************************************/
void destroiTalhao(talhao t);

/***********************************************
tesouroTalhao - Devolve o valor do tesouro do talhao.
Parametros:
	t - talhao a aceder
Retorno: inteiro valor do tesouro
Pre-condicoes: 
***********************************************/
int tesouroTalhao(talhao t);

/***********************************************
incrementaNumEscavadosTalhao - Incrementa 1 ao numero de vezes que o talhao foi escavado.
Parametros:
	t - talhao a aceder
Retorno: 
Pre-condicoes: 
***********************************************/
void incrementaNumEscavadosTalhao(talhao t);

/***********************************************
tesouroTalhao - Devolve o numero de vezes que o talhao foi escavado.
Parametros:
	t - talhao a aceder
Retorno: inteiro numero de vezes que o talhao foi escavado
Pre-condicoes: 
***********************************************/
int numVezesEscavadoTesouro(talhao t);

/***********************************************
colocarTesouroTalhaoZero - Coloca o valor do tesouro do talhao a 0.
Parametros:
	t - talhao a aceder
Retorno: 
Pre-condicoes: 
***********************************************/
void colocarTesouroTalhaoZero(talhao t);
#endif