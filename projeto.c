#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"

void lgen_insere(ListaGen* l, void* p){
	
	ListaGenNo* n = (ListaGenNo*) malloc( sizeof(ListaGenNo));
	n->info = p;
	n->prox = l->prim;
	l->prim =  n;
}

void lgen_percorre(ListaGen* l, void (*cb)(void*)){
	
	for(ListaGenNo* p = l->prim; p != NULL; p = p->prox){
		
		cb(p->info);
	}
}

void lgen_percorre2(ListaGen* l, void(*cb)(void*, int), int dado){
	
	for(ListaGenNo* p = l->prim; p != NULL; p = p->prox)
		cb(p->info, dado);
}

void lgen_remove(ListaGen* l, int(*cb)(void*, int), int dado){
	
	ListaGenNo* ant = NULL;
	ListaGenNo* n = l->prim;
	
	int r = cb(n->info, dado);
	
	while(n != NULL && r != dado){
		
		ant = n;
		n = n->prox;
		
		if(n == NULL) return;
		r = cb(n->info, dado);
	}
	
	if(n != NULL){
		if(ant == NULL){
			
			l->prim = n->prox;
		}else{
			
			ant->prox = n->prox;
		}
		
		free(n);
	}
}

void lgen_libera(ListaGen* l){
	
	ListaGenNo* p = l->prim;
	while(p != NULL){
		
		ListaGenNo* t = p->prox;
		free(p);
		p = t;
	}
	
	free(l);
}

int lgen_vazia(ListaGen* l){
	
	return(l->prim == NULL);
}