#ifndef EQUIPA_H_
#define EQUIPA_H_
#include "participante.h"

/* Tipo de dados: equipa ---> e[1], e[2], e[3] ....*/
typedef struct _equipa *equipa;

/***********************************************
criaEquipa - Criacao da instancia da estrutura associada a uma equipa.
Parametros:
	tamanho_equipa - numero de elementos dessa equipa
    nome - nome da equipa
Retorno: apontador para a  instancia criada
Pre-condicoes: e != NULL
***********************************************/
equipa criaEquipa(int tamanho_equipa, char* nome);

/***********************************************
destroiEquipa - Liberta a memoria ocupada pela instancia da estrutura associada a equipa.
Parametros:
	e - equipa a destruir
Retorno:
Pre-condicoes: s != NULL
***********************************************/
void destroiEquipa(equipa e);

/***********************************************
tamanhoSequenciaParticipantes - retorna o numero de participantes numa equipa.
Parametros:
	e - equipa que se quer retirar info
Retorno: numero de elementos da equipa
Pre-condicoes: 
***********************************************/
int tamanhoSequenciaParticipantes(equipa e);

/***********************************************
criaParticipantesEquipa - Cria um participante e guarda na sequencia de participantes de uma equipa.
Parametros:
	e - equipa onde coloca o partcipante
    nome - nome do participante
Retorno:
Pre-condicoes: 
***********************************************/
void criaParticipantesEquipa(equipa e, char* nome);

/***********************************************
daParticipante - Devolve o participante que esta na posicao x da equipa y.
Parametros:
	e - equipa onde acede
    posicao - posicao do participante na sequencia de participantes da equipa
Retorno: tipo participante naquela posicao
Pre-condicoes: 
***********************************************/
participantes daParticipante(equipa e, int posicao);

/***********************************************
nomeEquipa - Devolve o nome da equipa x.
Parametros:
	e - equipa a aceder
Retorno: nome da equipa x
Pre-condicoes: 
***********************************************/
char *nomeEquipa(equipa e);

/***********************************************
EquipaDesclassificada - Acede a equipa e verifica na estrutura se esta desclassificada.
Parametros:
	e - equipa a aceder
Retorno: 1 se estiver desclassificado e 0 se estiver classificado
Pre-condicoes: 
***********************************************/
int EquipaDesclassificada(equipa e);

/***********************************************
DesclassificaEquipa - Verifica se a equipa esta desclassificada, se estiver coloca no parametro equipa_descf igual a 1.
Parametros:
	e - equipa que vai ser desclassificada ou nao
Retorno: 1 se tiver desclassificada e 0 se estiver classificada
Pre-condicoes: 
***********************************************/
int DesclassificaEquipa(equipa e);

/***********************************************
numPessoaEscavarEquipa - Acede a equipa e retorna o numero da posicao da pessoa proxima pessoa a escavar.
Parametros:
	e - equipa a jogar
Retorno: posicao da proxima pessoa a escavar
Pre-condicoes: 
***********************************************/
int numPessoaEscavarEquipa(equipa e);

/***********************************************
incrementaProximaPessoaEscavarEquipa - Adiciona 1 a posicao da proxima pessoa a escavar na equipa
Parametros:
	e - equipa a aceder
Retorno: 
Pre-condicoes: 
***********************************************/
void incrementaProximaPessoaEscavarEquipa(equipa e);

/***********************************************
estrelaEquipa - Recebe uma equipa e compara todos os partcipantes, o que tiver maior pontuacao e a estrela. Se 
tiverem a mesma pontuacao a estrela e quem tem menos penalizacoes. Se tiverem a mesma pontuacao e mesmo numero de
penalizacoes a estrela e quem tiver o nome alfabeticamente mais pequeno. 
Parametros:
	e - equipa a aceder
Retorno: nome da estrela da equipa x
Pre-condicoes: 
***********************************************/
char *estrelaEquipa(equipa e);

/***********************************************
pontuacaoEquipa - Percorre a sequencia de participantes de uma equipa, se este nao estiver desclassificado, soma a sua
 pontuacao. No final retorna a pontuacao total da equipa.
Parametros:
	e - equipa a aceder
Retorno: inteiro pontuacao total da equipa
Pre-condicoes: 
***********************************************/
int pontuacaoEquipa(equipa e);

/***********************************************
numParticipantesExpulsos - Percorre a sequencia de participantes de uma equipa, se este estiver desclassificado, 
adiciona a conta de participantes expulsos. No final retorna essa conta.
Parametros:
	e - equipa a aceder
Retorno: inteiro numero de participantes expulsos
Pre-condicoes: 
***********************************************/
int numParticipantesExpulsos(equipa e);

/***********************************************
numParticipantesComLicenca - Percorre a sequencia de participantes de uma equipa, se este nao estiver desclassificado, 
adiciona a conta de participantes com licenca. No final retorna essa conta.
Parametros:
	e - equipa a aceder
Retorno: inteiro numero de participantes com licenca
Pre-condicoes: 
***********************************************/
int numParticipantesComLicenca(equipa e);

/***********************************************
comparaEquipas - 
Parametros:
	e1 - equipa 1 a comparar
	e2 - equipa 2 a comparar
Retorno: retorna 1 se a equipa 1 estiver a frente da equipa 2, retorna 0 se a equipa 2 estiver a frente da equipa 1 ou retorna -1 se forem iguais
Pre-condicoes: 
***********************************************/
int comparaEquipas(equipa e1, equipa e2);

/***********************************************
verificaNomeParticipanteEquipa - Percorre a sequencia de participantes de uma equipa e compara cada nome dos participntes com o nome
que entra como parametro, se esse nome existir retorna 1, se nao existir retorna 0.
Parametros:
	e - equipa a aceder
	nome participante - apontador para a string, nome do participante a verificar
Retorno: retorna 1 se o nome do participante ja existe e 0 se nao existe
Pre-condicoes: 
***********************************************/
int verificaNomeParticipanteEquipa(equipa e, char *nome_participante);

/***********************************************
adicionaMembroEquipa - Adiciona a variavel num_membros (numero de membros) do apontador da estrutura da equipa o valor inteiro 1, ou seja, incrementa o tamanho da equipa.
Parametros:
	e - equipa a aceder
Retorno: 
Pre-condicoes: 
***********************************************/
void adicionaMembroEquipa(equipa e);
#endif