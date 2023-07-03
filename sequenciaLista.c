
//sequenciaLista.c

#include <stdlib.h>

//TADs usadas
#include "iterador.h"
#include "sequencia.h"
#include "noSimples.h"

//Estrutura do tipo TAD sequencia
struct  _sequencia{
         noSimples cabeca;
         noSimples cauda; 	
         int nroElem;
};

sequencia criaSequencia(int cap){
	sequencia s = (sequencia) malloc(sizeof(struct _sequencia));
	if ( s == NULL) return NULL;
	s->cabeca = NULL;
	s->cauda = NULL;
	s->nroElem = 0;
	return s;
}

void destroiSequencia (sequencia s ){
	noSimples  aux = s->cabeca;
	while (aux != NULL){
		s->cabeca = segNoSimples(aux);
		destroiNoSimples(aux);
		aux = s->cabeca;
	}
	free(s);
}

void destroiSeqElems(sequencia s, void (*destroi)(void *) ){
	noSimples  aux = s->cabeca;
	while (aux != NULL){
		s->cabeca = segNoSimples(aux);
		destroiElemENoSimples(aux,destroi);
		aux = s->cabeca;
	}
	free(s);
}

int vaziaSequencia(sequencia s){
	if (s->nroElem == 0)
		return 1;
	return 0;
}


int tamanhoSequencia(sequencia s){
	return s->nroElem;
}

void * elementoPosSequencia(sequencia s, int i){
	int j = 1;
	noSimples aux = s->cabeca;
	if (i == s->nroElem)
		return elemNoSimples(s->cauda);
	for(; j < i;j++)
		aux = segNoSimples(aux);
	return elemNoSimples(aux);
}

void adCabeca(sequencia s, void * e){
	noSimples aux = criaNoSimples(e,s->cabeca);
	s->cabeca = aux;
	if (s->nroElem == 0) 
		s->cauda = aux;
	s->nroElem++;
}

void adCauda(sequencia s, void * e){
	noSimples aux = criaNoSimples(e,NULL);
	atribuiSegNoSimples(s->cauda,aux);
	s->cauda = aux;
	s->nroElem++;
}

void adMeio (sequencia s, void * e, int i){
	int j;
	noSimples auxAntes = s->cabeca;
	noSimples auxDepois, novoNo;
	for(j=1 ; j<i-1 ; j++)
		auxAntes = segNoSimples(auxAntes);	
	auxDepois = segNoSimples(auxAntes);
	novoNo = criaNoSimples(e, auxDepois);
	atribuiSegNoSimples(auxAntes, novoNo);
	s->nroElem++;
}

void adicionaPosSequencia(sequencia s, void * elem, int i){
	if (i == 1)
		adCabeca(s, elem);
	else
		if (i == s->nroElem + 1)
			adCauda(s,elem);
		else
			adMeio(s,elem,i);
}

void * rmCabeca(sequencia s){
	noSimples aux = s->cabeca;
	void * elem;
	s->cabeca = segNoSimples(aux);
	if (s->nroElem == 1)
		s->cauda = NULL;
	s->nroElem--;
	elem = elemNoSimples(aux);
	destroiNoSimples (aux);
	return elem;
}

void * rmPos(sequencia s, int i){
	int j;
	noSimples auxAntes = s->cabeca;
	noSimples auxRm, auxDepois;
	void * elem;
	for(j=1 ; j<i-1 ; j++)
		auxAntes = segNoSimples(auxAntes);
	auxDepois = segNoSimples(auxAntes);	
	auxRm = criaNoSimples(NULL, auxDepois);
	atribuiSegNoSimples(auxAntes, segNoSimples(auxDepois));
	s->nroElem--;
	elem =elemNoSimples(auxDepois);
	destroiNoSimples(auxRm);
	return elem;
}

void * removePosSequencia(sequencia s, int i){
	if (i == 1)
		return rmCabeca(s);
	return rmPos(s,i);
}

iterador iteradorSequencia(sequencia s){
	iterador it;
	int i;
	noSimples aux = s->cabeca;
	void ** vec;

	vec = (void**)malloc(sizeof(void*) * s->nroElem);
	vec[0] = elemNoSimples(aux);
	for(i=1 ; i<s->nroElem ; i++){
		aux = segNoSimples(aux);
		vec[i] = elemNoSimples(aux);
	}
	it = criaIterador(vec, s->nroElem);
	return it;
}