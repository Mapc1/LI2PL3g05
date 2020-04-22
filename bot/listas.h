/**
@file listas.h
Definição das listas e das funções que as alteram
*/

#ifndef RASTROS_LISTAS_H
#define RASTROS_LISTAS_H
#include "listas.h"

/**
\brief Tipo de dados para as listas
*/
typedef struct nodo {
    void *v;
    struct nodo *prox;
} Nodo, *LISTA;

typedef struct ramo {
    int valor;
    struct ramo *SE;
    struct ramo *SM;
    struct ramo *SD;
    struct ramo *ME;
    struct ramo *MD;
    struct ramo *IE;
    struct ramo *IM;
    struct ramo *ID;
} Ramo, *ARVORE;
/**
\brief Insere uma nova cabeça na lista
@param x nova cabeça da lista
@param xs lista
*/
LISTA insere_cabeca (void *x, LISTA xs);

/**
\brief Transforma um array numa lista
@param v Array a ser transformado
@param N Tamanho do array
*/
LISTA fromArray (void *v[], int N, int tamcel);

/**
\brief Cria uma lista vazia
*/
LISTA criar_lista();

/**
\brief Devolve a cabeça de uma lista
@param L Lista
*/
void *devolve_cabeca(LISTA L);

/**
\brief Devolve a cauda de uma lista
@param L Lista
*/
LISTA proximo(LISTA L);


/**
\brief Remove a cabeça da lista e devolve a cauda
@param L Lista
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Verifica se a lista está vazia
@param L Lista
Devolve verdadeiro (1) se estiver vazia
*/
int lista_esta_vazia(LISTA L);

#endif //RASTROS_LISTAS_H
