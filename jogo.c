#include <stdlib.h>
#include <string.h>
#include "iterador.h"
#include "sequencia.h"
#include "participante.h"
#include "equipa.h"
#include "talhao.h"
#include "terreno.h"
#include "jogo.h"
#include "dicionario.h"

struct _jogo{
    equipa *equipas;
    dicionario equipas_jogo;
    int numTotalEquipas;
};

jogo criaJogo(int num_equipas){
    jogo j = (jogo) malloc(sizeof(struct _jogo));
    if (j == NULL){
        return NULL;
    }
    j->equipas = (equipa*)malloc(sizeof(equipa)*num_equipas);
    j->equipas_jogo = criaDicionario(2000,1);
    return j;
}

void destroiJogo(jogo j){
    for(int i=1 ; i <= j->numTotalEquipas ; i++){
        destroiEquipa(j->equipas[i]);
    }
    destroiDicionario(j->equipas_jogo);
    free(j);
}

void criaEquipaJogo(jogo j, int posicao, int tamanho, char *nome){
    j->equipas[posicao] = criaEquipa(tamanho, nome);
}

void guardaNumTotalEquipas(int numTotalEquipas, jogo j){
    j->numTotalEquipas = numTotalEquipas;
}

int escreveNumTotalEquipas(jogo j){
    return j->numTotalEquipas;
}

equipa daEquipaFicheiro(jogo j, int posicao){
    return j->equipas[posicao];
}

int numeroEquipasJogo(jogo j){
    return tamanhoDicionario(j->equipas_jogo);
}

equipa devolveEquipaJogo(jogo j, char * nome){
    return (equipa)elementoDicionario(j->equipas_jogo, nome);
}

void guardaEquipaJogo(jogo j, char* nome, equipa e){
    adicionaElemDicionario(j->equipas_jogo, nome, e);
}

int numPalavra(char *string){
    int wrd = 1, i=0;

    while(string[i] != '\0'){
        //verifica se existe um espaco em branco ou uma nova linha ou um tab
        if(string[i]==' ' || string[i]=='\n' || string[i]=='\t')
            wrd++;
        i++;
    }
    return wrd;
}

int verificaEquipa(jogo j, char *nome_equipa){    
    return existeElemDicionario(j->equipas_jogo, nome_equipa);
}

int posicaoEquipa(jogo j, char *nome_equipa){
    int i = 0;

    for(i=1;i<j->numTotalEquipas;i++){
        if(!(strcmp(nome_equipa, nomeEquipa(j->equipas[i])))){
            break;
        }
    }
    return i;
}

int escavacaoEquipa(jogo j, char *nome_equipa, int salto_linha, int salto_coluna, terreno ter){
    int posicaoDaEquipa = 0, posicaoDoParticipante =1, salto = 0, linha = 0, coluna = 0, tesouro = 0, penalizacao = 0;
    equipa e;
	participantes p;

    posicaoDaEquipa = posicaoEquipa(j, nome_equipa);
    e = daEquipaFicheiro(j, posicaoDaEquipa);
    posicaoDoParticipante = numPessoaEscavarEquipa(e);
    while(seFoiDesclassificado(daParticipante(e, posicaoDoParticipante)) == 1){
        incrementaProximaPessoaEscavarEquipa(e);
        posicaoDoParticipante = numPessoaEscavarEquipa(e);
    }
    p = daParticipante(e, posicaoDoParticipante);
    if(seFoiDesclassificado(p) == 0){
        posicaoDoParticipante = numPessoaEscavarEquipa(e);
        if(linhaParticipante(p) == 0 && numEscavacoesParticipante(p) == 0){
            mudaPosicaoLinha(p, -1);
        }
        if(colunaParticipante(p) == 0 && numEscavacoesParticipante(p) == 0){
            mudaPosicaoColuna(p, -1);
        }
        salto = saltoPartcipante(p, salto_linha, salto_coluna, colunasTerreno(ter), linhasTerreno(ter));
        // se o salto for -1 significa que foi feito
        if(salto == -1){
            linha = linhaParticipante(p);
            coluna = colunaParticipante(p);
            if(numVezesEscavadoTesouro(daTalhaoDoTerreno(ter, linha, coluna)) == 0){
                tesouro = valorTesouroTalhao(ter, linha, coluna);
                retiraRiquezaTerreno(ter, tesouro);
                adicionaPontosParticipante(p, tesouro);
                incrementaNumEscavadosTalhao(daTalhaoDoTerreno(ter, linha, coluna));
                colocarTesouroTalhaoZero(daTalhaoDoTerreno(ter, linha, coluna));
            }
            else{
                incrementaNumEscavacoesParticipante(p);
                penalizacao = numVezesEscavadoTesouro(daTalhaoDoTerreno(ter, linha, coluna)) * 10;
                adicionaPenalizacaoParticipante(p, penalizacao);
                adicionaPontosParticipante(p, -1*penalizacao);
                incrementaNumEscavadosTalhao(daTalhaoDoTerreno(ter, linha, coluna));
            }
        }
        incrementaProximaPessoaEscavarEquipa(e);
        incrementaNumEscavacoesParticipante(p);
    }
    if(DesclassificaEquipa(e)==1)
        return 1;
    return 0;    
}

int seEquipasTodasDesqualificadas(jogo j){
    int dim = 0, count  = 0;
    equipa e;
    dim = numeroEquipasJogo(j);

    iterador it = iteradorDicionario(j->equipas_jogo);

    while(temSeguinteIterador(it)){
        e = (equipa)seguinteIterador(it);
        if(EquipaDesclassificada(e) == 1){ 
            count++;
        }
    }

    destroiIterador(it);

    if(count == dim){
        return 1;
    }
    return 0;
}

void troca(void ** x, void ** y){
    void * aux = *x;
    *x=*y;
    *y=aux;
}

void quickSort(void * v[],int esq,int dir,int (*comparaEquipas)(equipa,equipa)){
    int i = esq;
    int j = dir;
    void * p = v[(i+j) / 2]; //pivot é o ponto médio
    do {
        while (comparaEquipas((equipa)v[i],(equipa)p) == 1) // v[i]<p
            i++;
        while (comparaEquipas((equipa)p,(equipa)v[j]) == 1) // p<v[j]
            j--;
        if (i <= j)
            troca(&v[i++],&v[j--]);  // troca
    } while (i<=j);
    if (esq<j)
        quickSort(v,esq,j, comparaEquipas);
    if (i<dir)
        quickSort(v,i,dir,comparaEquipas);
}

iterador organizaEquipas(jogo j){
    iterador it = iteradorDicionario(j->equipas_jogo);
    quickSort(devolveVetorIterador(it), 0, tamanhoDicionario(j->equipas_jogo)-1, comparaEquipas);
    return it;
}