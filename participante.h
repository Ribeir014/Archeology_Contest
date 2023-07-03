#ifndef PARTICIAPANTE_H_
#define PARTICIPANTE_H

/* Tipo de dados: participante ---> p[1], p[2], p[3] ....*/
typedef struct _participante *participantes;

/***********************************************
criaParticipante - Criacao da instancia da estrutura associada a um participante.
Parametros:
	nome - nome do participante
Retorno: apontador para a  instancia criada
Pre-condicoes: p != NULL
***********************************************/
participantes criaParticipante(char* nome);

/***********************************************
destroiParticipante - Liberta a memoria ocupada pela instancia da estrutura associada ao participante.
Parametros:
	p - participante a destruir
Retorno:
Pre-condicoes: s != NULL
***********************************************/
void destroiParticipante(participantes p);

/***********************************************
destroiParticipanteGen - Liberta a memoria ocupada pela instancia da estrutura associada ao participante. (Para a sequencia de partcipantes)
Parametros:
	p - participante a destruir
Retorno:
Pre-condicoes: 
***********************************************/
void destroiParticipanteGen(void * p);

/***********************************************
nomeParticipante - Devolve o nome do participante que entra como parametro.
Parametros:
	p - participante a aceder
Retorno: string do nome do participante
Pre-condicoes:
***********************************************/
char *nomeParticipante(participantes p);

/***********************************************
pontosParticipante - Devolve o numero de pontos do participante que entra como parametro.
Parametros:
	p - participante a aceder
Retorno: inteiro numero de pontos do participante
Pre-condicoes:
***********************************************/
int pontosParticipante(participantes p);

/***********************************************
linhaParticipante - Devolve a linha em que o participante esta. 
Parametros:
	p - participante a aceder
Retorno: inteiro linha do participante
Pre-condicoes:
***********************************************/
int linhaParticipante(participantes p);

/***********************************************
colunaParticipante - Devolve a coluna em que o participante esta. 
Parametros:
	p - participante a aceder
Retorno: inteiro coluna do participante
Pre-condicoes:
***********************************************/
int colunaParticipante(participantes p);

/***********************************************
numEscavacoesParticipante - Devolve o numero de escavacoes que o participante ja fez. 
Parametros:
	p - participante a aceder
Retorno: inteiro numero de escavacoes do participante
Pre-condicoes:
***********************************************/
int numEscavacoesParticipante(participantes p);

/***********************************************
incrementoNumEscavacoesParticipante - Incrementa o numero de escavacoes (variavel da estrutura) do participante. 
Parametros:
	p - participante a aceder
Retorno: 
Pre-condicoes:
***********************************************/
void incrementaNumEscavacoesParticipante(participantes p);

/***********************************************
saltoParticipante - Executa o salto do participante, ou seja, se o participante nao estiver desclassificado, soma 
a posicao dele o salto da linha e o salto da coluna. Se o salto for para fora do terreno entao o participante e
desclassificado e a funcao da retorno de 1, se o salto for executado da retorno de -1.
Parametros:
	p - participante a fazer o salto
    salto_x - inteiro salto da linha
    salto_y - inteiro salto da coluna
    c - inteiro numero de colunas do terreno
    l - inteiro numero de linhas do terreno          
Retorno: -1 se o salto for bem executado, 1 se o participante for desclassificado e 0 se o participante for NULL
Pre-condicoes:
***********************************************/
int saltoPartcipante(participantes p, int salto_x, int salto_y, int c, int l);

/***********************************************
seFoiDesclassificado - Devolve o parametro da estrutura partcipante que indica se esta desclassificado ou nao, se for
1 esta desclassificado, se for 0 nao esta. 
Parametros:
	p - participante a aceder
Retorno: inteiro 1 se estiver desclassificao ou 0 se estiver ainda em jogo
Pre-condicoes:
***********************************************/
int seFoiDesclassificado(participantes p);

/***********************************************
desclassificadoParticipante - Verifica se o partcipante vai ser desclassificado. Se o salto for para fora do terreno 
da retorno de 1 se nao da retorno de 0.
Parametros:
	local_x - linha onde o participante fica depois do salto
    local_y - coluna onde o participante fica depois do salto
    l - numero de linhas do terreno
    c - numero de colunas do terreno
Retorno: 1 se for descalssificado ou 0 se nao for desclassificado
Pre-condicoes:
***********************************************/
int desclassificadoParticipante(int local_x, int local_y, int l, int c);

/***********************************************
mudaPosicaoLinha - Coloca no parametro da posicao da linha do partcipante o valor dado. 
Parametros:
	p - participante a aceder
    valor - inteiro linha que se quer mudar
Retorno: 
Pre-condicoes:
***********************************************/
void mudaPosicaoLinha(participantes p, int valor);

/***********************************************
mudaPosicaoColuna - Coloca no parametro da posicao da coluna do partcipante o valor dado. 
Parametros:
	p - participante a aceder
    valor - inteiro coluna que se quer mudar
Retorno: 
Pre-condicoes:
***********************************************/
void mudaPosicaoColuna(participantes p, int valor);

/***********************************************
adicionaPontosParticipante - Adiciona pontos ao participante. 
Parametros:
	p - participante a aceder
    pontos - inteiro pontos a adicionar
Retorno: 
Pre-condicoes:
***********************************************/
void adicionaPontosParticipante(participantes p, int pontos);

/***********************************************
adicionaPenalizacaoParticipante - Adiciona o valor das penalizacoes ao participante. 
Parametros:
	p - participante a aceder
    penalizacao - inteiro penalizacao a adicionar
Retorno: 
Pre-condicoes:
***********************************************/
void adicionaPenalizacaoParticipante(participantes p, int penalizacao);

/***********************************************
incrementaNumPenalizacoes - Incrementa 1 ao numero de penalizacoes do participante. 
Parametros:
	p - participante a aceder
Retorno: 
Pre-condicoes:
***********************************************/
void incrementaNumPenalizacoes(participantes p);

/***********************************************
adicionaPontosParticipante - Acede a estrutura do partcipante e retorna o numero de penalizacoes que este tem.
Parametros:
	p - participante a aceder
Retorno: numero de penalizacoes
Pre-condicoes:
***********************************************/
int numeroPenalizacoes(participantes p);
#endif