#ifndef ABB_H
#define ABB_H

typedef int tipo_de_dado; // o tipo de dado (int, char*, struct) que o no vai armazenar


typedef struct no_abb { // estrutura no (para arvore de busca binaria)
	tipo_de_dado dado;
	struct no_abb *esq, *dir;
} no_abb;

typedef struct no_abb *arvore; // definicao de uma "variavel de referencia?" para a estrutura

/*funcoes*/

void inicializar(arvore *raiz);
arvore adicionar(arvore raiz, tipo_de_dado dado);
tipo_de_dado buscar(arvore raiz, tipo_de_dado valor);
int altura(arvore raiz);
tipo_de_dado maior(tipo_de_dado a, tipo_de_dado b);
tipo_de_dado maior_elemento(arvore raiz);
tipo_de_dado menor_elemento(arvore raiz);
void pre_order(arvore raiz);
void in_order(arvore raiz);
void pos_order(arvore raiz);
void imprimir_elemento(arvore raiz);

#endif
