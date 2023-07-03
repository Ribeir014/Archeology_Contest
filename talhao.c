#include <stdlib.h>
#include <string.h>
#include "terreno.h"
#include "talhao.h"

struct _talhao{
    int num_escavados;
    int valor_tesouro;
};

talhao criarTalhao(int tesouro){
    talhao t;
    t = (talhao)malloc(sizeof(struct _talhao));
    if(t == NULL)
        return NULL;
    t->num_escavados = 0;
    t->valor_tesouro = tesouro;
    return t;
}

void destroiTalhao(talhao t){
    free(t);
}

int tesouroTalhao(talhao t){
    return t->valor_tesouro;
}

void incrementaNumEscavadosTalhao(talhao t){
    t->num_escavados = t->num_escavados + 1;
}

int numVezesEscavadoTesouro(talhao t){
    return t->num_escavados;
}

void colocarTesouroTalhaoZero(talhao t){
    t->valor_tesouro = 0;
}

