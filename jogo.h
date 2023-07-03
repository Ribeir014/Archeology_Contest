#ifndef JOGO_H_
#define JOGO_H_
#include "participante.h"
#include "equipa.h"
#include "terreno.h"

/* Tipo de dados: jogo ---> j[1] so existe um jogo*/
typedef struct _jogo *jogo;

/***********************************************
criaJogo - Criacao da instancia da estrutura associada a um jogo.
Parametros:
	num_equipas
Retorno: apontador para a  instancia criada
Pre-condicoes: j != NULL
***********************************************/
jogo criaJogo(int num_equipas);

/***********************************************
destroiJogo - Liberta a memoria ocupada pela instancia da estrutura associada ao jogo.
Parametros:
	j - jogo a destruir
Retorno: 
Pre-condicoes: j != NULL
***********************************************/
void destroiJogo(jogo j);

/***********************************************
criaEquipaJogo - Cria equipa na instancia da estrutura associada ao jogo.
Parametros:
	j - jogo a aceder
    posicao - posicao da equipa
    tamanho - tamanho da equipa
    nome - nome da equipa
Retorno: 
Pre-condicoes: 
***********************************************/
void criaEquipaJogo(jogo j, int posicao, int tamanho, char *nome);

/***********************************************
guardaNumTotalEquipas - Guarda o inteiro que indica o numero total de equipas no jogo na estrutura jogo.
Parametros:
	j - jogo a aceder
    numTotalEquipas - numero de equipas no ficheiro
Retorno: 
Pre-condicoes: 
***********************************************/
void guardaNumTotalEquipas(int numTotalEquipas, jogo j);

/***********************************************
escreveNumTotalEquipas - Retorna o numero total de equipas associado a estrutura do jogo.
Parametros:
	j - jogo a aceder
Retorno: numero total de equipas no jogo
Pre-condicoes: 
***********************************************/
int escreveNumTotalEquipas(jogo j);

/***********************************************
daEquipaFicheiro - Retorna a equipa que esta naquela posicao do jogo.
Parametros:
	j - jogo a aceder
	posicao - posicao da equipa no jogo
Retorno: equipa da posicao x do jogo
Pre-condicoes: 
***********************************************/
equipa daEquipaFicheiro(jogo j, int posicao);

/***********************************************
numeroEquipasJogo - Retorna o numero total de equipas presentes no dicionario, ou seja, o numero de equipas que vao a jogo
Parametros:
	j - jogo a aceder
Retorno: numero total de equipas no dicionario (equipas em jogo)
Pre-condicoes: 
***********************************************/
int numeroEquipasJogo(jogo j);

/***********************************************
devolveEquipaJogo - Retorna a equipa que com o nome x.
Parametros:
	j - jogo a aceder
	nome - nome da equipa
Retorno: equipa com o nome x
Pre-condicoes: 
***********************************************/
equipa devolveEquipaJogo(jogo j, char * nome);

/***********************************************
guardaEquipaJogo - Guarda uma nova equipa na posicao seguinte do dicionario de equipas.
Parametros:
	j - jogo a aceder
	nome - nome da nova equipa
	e - nova equipa
Retorno: 
Pre-condicoes: 
***********************************************/
void guardaEquipaJogo(jogo j, char* nome, equipa e);

/***********************************************
numPalavra - Retorna o numero de palavras numa frase qualquer.
Parametros:
	string - frase usada
Retorno: numero de palavras da string.
Pre-condicoes: 
***********************************************/
int numPalavra(char *string);

/***********************************************
verificaEquipa - Verifica se a equipa com aquele nome esta em jogo, ou seja, se esta no dicionario. Consulta o dicionario com a 
chave igual ao nome da equipa, se a equipa existir retorna 1, se nao existir retorna 0;
Parametros:
	j - jogo a aceder
	nome - nome da equipa
Retorno: inteiro 1 se exisitr a equipa no jogo, 0 se nao existir
Pre-condicoes: 
***********************************************/
int verificaEquipa(jogo j, char *nome);

/***********************************************
posicaoEquipa - Consulta as equipas, por ordem, na instancia da estrutura jogo e retorna o valor da posicao do vetor de equipas 
onde essa equipa esta.
Parametros:
	j - jogo a aceder
	nome_equipa - nome da equipa
Retorno: inteiro da posicao da equipa de nome x.
Pre-condicoes: 
***********************************************/
int posicaoEquipa(jogo j, char *nome_equipa);

/***********************************************
escavacaoEquipa - Se a equipa nao estiver desclassificada, esta funcao vai procurar na equipa com o nome 'nome_equipa' qual 
o participante dessa equipa a jogar, ou seja, se a pessoa que for escavar estiver desclassificada incrementa-se para a
proxima até encontrar uma que tenha licenca para escavar e guarda-se a posicao desse participante para quando essa equipa 
voltar a escavar ser o proximo participante com licenca. Se nao houver mais ninguem na equipa que tenha licenca para escavar 
a equipa e desclassificada e da-se retorno de 1, se a escavacao for efectuada com sucesso da-se retorno de 0. Quando se 
encontra um participante, faz-se o salto, se o SALTO FOR FORA DO TERRENO, esse participante e desclassificado e incrementa-se 
a posicao da proxima pessoa a escavar. Se o SALTO FOR POSSIVEL E O TESOURO AINDA NAO FOI ESCAVADO, entao o participante ganha 
os pontos do tesouro. Se o SALTO FOR POSSIVEL, MAS O TESOURO JA FOI ESCAVADO, entao o participante sofre uma penalizacao. 
No final incrementa o numero do proximo participante a escavar. 
Parametros:
	j - jogo a aceder
	nome_equipa - nome da equipa
	salto_linha - salto do participante na linha
	salto_coluna - salto do participante na coluna
	ter - terreno onde estao os talhoes com os tesouros
Retorno: 1 se a equipa for desclassificada, 0 se o salto for executado 
Pre-condicoes: equipa nao pode estar desclassificada, o salto nao pode ser nulo (0,0)
***********************************************/
int escavacaoEquipa(jogo j, char *nome_equipa, int salto_linha, int salto_coluna, terreno ter);

/***********************************************
seEquipasTodasDesqualificadas - Verifica se todas as equipas estao desclassificadas. Faz um ciclo pelas equipas em jogo no dicionario e conta 
o numero de equipas desclassificadas, se for igual ao numero total de equipas em jogo, entao estao todas desclassificadas.
Parametros:
	j - jogo a aceder
Retorno: 1 se as equipas estiverem todas desclassificadas, 0 pelo contrario
Pre-condicoes: 
***********************************************/
int seEquipasTodasDesqualificadas(jogo j);

/***********************************************
troca - Coloca o apontador do x no y e o y no x.
Parametros:
	x - primeiro apontador para um vetor para trocar
	y - segundo apontador para um vetor para trocar
Retorno: 
Pre-condicoes: 
***********************************************/
void troca(void ** x, void ** y);

/***********************************************
quickSort - Organiza o vetor com um algoritmo de quick sort. Esse algoritmo vai buscar o elemento do meio e compara com os elementos 
da equerda e da direita, na funcao comparaEquipas, e vai trocando.
Parametros:
	v - vetor a organizar
	esq - primeiro elemento
	dir - ultimo elemento
	comparaEquipas - funcao em equipa.h
Retorno: 
Pre-condicoes: 
***********************************************/
void quickSort(void * v[], int esq, int dir, int (*comparaEquipas)(equipa, equipa));

/***********************************************
organizaEquipas - Executa a funcao quick sort no vetor do iterador.
Parametros:
	j - jogo a aceder
Retorno: retorna o iterador organizado
Pre-condicoes: 
***********************************************/
iterador organizaEquipas(jogo j);
#endif