/**
@file listas.h
Definição das listas e das funções que as alteram
*/

#ifndef RASTROS_LISTAS_H
#define RASTROS_LISTAS_H
#include "listas.h"
#include "dados.h"

/**
\brief Tipo de dados para as listas
*/
typedef struct nodo {
    COORDENADA v;
    struct nodo *prox;
} Nodo, *LISTA;

/**
\brief Insere uma nova cabeça na lista
@param x nova cabeça da lista
@param xs lista
*/
LISTA insere_cabeca (COORDENADA x, LISTA xs);


/**
\brief Verifica se a lista está vazia
@param L Lista
Devolve verdadeiro (1) se estiver vazia
*/
int lista_esta_vazia(LISTA L);


LISTA cloneL (LISTA l);
int coordenadas_iguais (COORDENADA x,COORDENADA y);
int nao_repete(LISTA l,COORDENADA x);
#endif //RASTROS_LISTAS_H
