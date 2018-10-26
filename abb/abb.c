#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void inicializar(arvore *raiz) {
	*raiz = NULL; // o ponteiro("variavel de referencia?", raiz, arvore) agora aponta para NULL
}

arvore adicionar(arvore raiz, tipo_de_dado valor) {

	if(raiz == NULL) { // se chegar no "filho" de uma folha
		
		arvore novo = (arvore) malloc(sizeof(struct no_abb));
	
		novo->dado = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		return novo;	
	}

	// se o valor que estah prestes a ser adicionado for menor que a raiz de tal arvore
	if(valor < raiz->dado) { 
		// invoca o metodo adicionar() e agora a raiz eh o filho esquerdo da atual raiz
		raiz->esq = adicionar(raiz->esq, valor); 
	}
	// analogamente...
	else {
		raiz->dir = adicionar(raiz->dir, valor);
	}
	return raiz;

}

tipo_de_dado buscar(arvore raiz, tipo_de_dado valor) { // busca binaria

	if(raiz == NULL) { // caso o valor nao esteja na arvore
		return -1;
	}

	if(raiz->dado == valor) {
		return raiz->dado;
	}

	else {
		
		if(valor < raiz->dado) {
			buscar(raiz->esq, valor);
		}
	
		else {
			buscar(raiz->dir, valor);			
		}
		
	}

}

int altura(arvore raiz) {

	if(raiz == NULL) {
		return -1;
	}

	else {
		return 1 + maior(altura(raiz->esq), altura(raiz->dir)); 
	}
 
}

tipo_de_dado maior(int a, int b) {

	if(a > b) {
		return a;
	}
	return b;
}

tipo_de_dado maior_elemento(arvore raiz) {

	if(raiz->dir == NULL) {
		return raiz->dado;
	}

	else {
		return maior_elemento(raiz->dir);
	}

}

tipo_de_dado menor_elemento(arvore raiz) {

	if(raiz->esq == NULL) {
		return raiz->dado;
	}

	else {
		return menor_elemento(raiz->esq);
	}

}

void pre_order(arvore raiz) {
	
	if(raiz != NULL) {
		imprimir_elemento(raiz);
		pre_order(raiz->esq);
		pre_order(raiz->dir);		
	}
}

void in_order(arvore raiz) {
	
	if(raiz != NULL) {
		in_order(raiz->esq);
		imprimir_elemento(raiz);
		in_order(raiz->dir);		
	}
}

void pos_order(arvore raiz) {
	
	if(raiz != NULL) {
		pos_order(raiz->esq);
		pos_order(raiz->dir);
		imprimir_elemento(raiz);		
	}
}

void imprimir_elemento(arvore raiz) {
		printf("[%d] ", raiz->dado);	
}


