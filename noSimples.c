
//noSimples.c

#include <stdlib.h>

//TADs usadas
#include "noSimples.h"

//Estrutura do tipo TAD noSimples
struct _noSimples{
	void * elem;
	struct _noSimples * seguinte;
};

noSimples criaNoSimples(void * e, noSimples seg){
	noSimples aux = (noSimples) malloc(sizeof(struct _noSimples));
	if (aux == NULL)
		return NULL;
	aux->elem = e;
	aux-> seguinte = seg;
	return aux;
}

void destroiNoSimples(noSimples n){
	free(n);
}

void destroiElemENoSimples(noSimples n, void (*destroi)(void *)){
	destroi(n->elem);
	free(n);
}

void atribuiElemNoSimples(noSimples n, void * e){
	n->elem = e;
}

void atribuiSegNoSimples(noSimples n, noSimples seg){
	n->seguinte = seg;
}

void * elemNoSimples(noSimples n){
	return n->elem;
}

noSimples segNoSimples(noSimples n){
	return n->seguinte;
}
