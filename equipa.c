#include <stdlib.h>
#include <string.h>
#include "iterador.h"
#include "sequencia.h"
#include "equipa.h"
#include "participante.h"

struct _equipa{
    sequencia participante;
    char nome[40];
    int pessoa_escavar; 
    int num_membros;
    int equipa_descf;
};

equipa criaEquipa(int tamanho_equipa, char* nome){
    equipa e;
    e = (equipa) malloc(sizeof(struct _equipa));
    if (e==NULL){
        return NULL;
    }
    e->participante = criaSequencia(30);
    e->num_membros = tamanho_equipa;
    e->pessoa_escavar = 1;
    e->equipa_descf = 0;
    strcpy(e->nome, nome);
    return e;
}

void destroiEquipa(equipa e){
    destroiSeqElems(e->participante, destroiParticipanteGen);
    free(e);
}

int tamanhoSequenciaParticipantes(equipa e){
    return tamanhoSequencia(e->participante);
}

void criaParticipantesEquipa(equipa e, char* nome){
    adicionaPosSequencia(e->participante, (char*)criaParticipante(nome), tamanhoSequencia(e->participante)+1);
}

participantes daParticipante(equipa e, int posicao){
    return (participantes)elementoPosSequencia(e->participante, posicao);
}

char *nomeEquipa(equipa e){
    return e->nome;
}

int EquipaDesclassificada(equipa e){
    return e->equipa_descf;
}

int DesclassificaEquipa(equipa e){
    int y = 0;
    for(int x=1;x<tamanhoSequencia(e->participante)+1;x++){
        if(seFoiDesclassificado(daParticipante(e, x))==1)
            y++;
    }
    if(y==tamanhoSequencia(e->participante)){
        e->equipa_descf = 1;
        return 1; 
    }
    return 0;    
}

int numPessoaEscavarEquipa(equipa e){
    return e->pessoa_escavar;
}

void incrementaProximaPessoaEscavarEquipa(equipa e){
    if(e->pessoa_escavar == e->num_membros)
        e->pessoa_escavar = 1;
    else{
        e->pessoa_escavar = e->pessoa_escavar + 1;
    }
}

char *estrelaEquipa(equipa e){
    char *nome = (char*)malloc(sizeof(char)*40);
    int tamanho_equipa = 0, i = 0, j = 0, pontuacao_maxima = 0, penalizacoes = 0;
    participantes p;
    tamanho_equipa = tamanhoSequenciaParticipantes(e);
    for(i=1;i<=tamanho_equipa;i++){
        p = daParticipante(e,i);
        if(seFoiDesclassificado(p) != 1)
            break;
    }
    strcpy(nome, nomeParticipante(p));
    pontuacao_maxima=pontosParticipante(p);
    penalizacoes = numeroPenalizacoes(p);

    for(j=i+1;j<=tamanho_equipa;j++){
        p = daParticipante(e,j);
        if(seFoiDesclassificado(p) == 1){
            continue;
        }
        if(pontosParticipante(p) > pontuacao_maxima){
            pontuacao_maxima=pontosParticipante(p);
            strcpy(nome, nomeParticipante(p));
            penalizacoes = numeroPenalizacoes(p);
        }
        else{
            if(pontosParticipante(p) == pontuacao_maxima){
                if(numeroPenalizacoes(p) < penalizacoes){
                    strcpy(nome, nomeParticipante(p));
                    penalizacoes = numeroPenalizacoes(p);
                }
                else{
                    if(numeroPenalizacoes(p) == penalizacoes){
                        if(strcmp(nomeParticipante(p),nome) < 0){
                            strcpy(nome, nomeParticipante(p));
                        }
                    }
                }
            }
        }
    }
    return nome;
}

int pontuacaoEquipa(equipa e){
    int dim = 0, pontuacao = 0;

    dim = tamanhoSequencia(e->participante);
    for(int i=1;i<=dim;i++){
        if(seFoiDesclassificado(daParticipante(e, i)) == 0)
            pontuacao = pontuacao + pontosParticipante(daParticipante(e, i));
    }
    if(EquipaDesclassificada(e) == 1)
        pontuacao = 0;
    return pontuacao;
}

int numParticipantesExpulsos(equipa e){
    int dim = 0, count = 0;

    dim = tamanhoSequencia(e->participante);
    for(int i=1;i<=dim;i++){
        if(seFoiDesclassificado(daParticipante(e, i)) == 1)
            count++;
    }
    return count;
}

int numParticipantesComLicenca(equipa e){
    int dim = 0, count = 0;

    dim = tamanhoSequencia(e->participante);
    for(int i=1;i<=dim;i++){
        if(seFoiDesclassificado(daParticipante(e, i)) == 0)
            count++;
    }
    return count;
}

int comparaEquipas(equipa e1, equipa e2){
    //compara pontuacao (se a equipa 1 tiver mais pontuacao da retorno de 1)
    if(pontuacaoEquipa(e1) > pontuacaoEquipa(e2)){
        return 1;
    }
    else if(pontuacaoEquipa(e1) < pontuacaoEquipa(e2)){
        return 0;
    }
    else{
        //compara numero de arqueologos expulsos (se a equipa 1 tiver menos arqueologos expulsos da retorno de 1)
        if(numParticipantesExpulsos(e1) < numParticipantesExpulsos(e2)){
            return 1;
        }
        else if(numParticipantesExpulsos(e1) > numParticipantesExpulsos(e2)){
            return 0;
        }
        else{
            //compara numero de arqueologos com licenca (se a equipa 1 tiver mais licencas de escavacao da retorno de 1)
            if(numParticipantesComLicenca(e1) < numParticipantesComLicenca(e2)){
                return 1;
            }
            else if(numParticipantesComLicenca(e1) > numParticipantesComLicenca(e2)){
                return 0;
            }
            else{
                //compara o nome das equipas (se a equipa 1 for menor alfabeticamente da retorno de 1)
                if(strcmp(nomeEquipa(e1), nomeEquipa(e2)) == -1){
                    return 1;
                }
                else if(strcmp(nomeEquipa(e1), nomeEquipa(e2)) == 1){
                    return 0;
                }
                else{
                    return -1;
                }
            }
        }
    }
}

int verificaNomeParticipanteEquipa(equipa e, char *nome_participante){
    int dim = 0, count = 0;

    dim = tamanhoSequenciaParticipantes(e);
    for(int i=1;i<=dim;i++){
        if(strcmp(nome_participante, nomeParticipante(daParticipante(e, i))) == 0){
            count = 1;
            break;
        }
    }
    return count;
}

void adicionaMembroEquipa(equipa e){
    e->num_membros = e->num_membros + 1;
}
