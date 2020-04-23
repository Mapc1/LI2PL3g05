/**
@file dados.h
Definição de árvore e das funções que a manipulam
*/

#ifndef __RASTROS_TREES_H__
#define __RASTROS_TREES_H__

#include <stdio.h>
#include <stdlib.h>


typedef struct ramo {
    int valor;
    LISTA jogadas_passadas;
    struct ramo *SE;
    struct ramo *SM;
    struct ramo *SD;
    struct ramo *ME;
    struct ramo *MD;
    struct ramo *IE;
    struct ramo *IM;
    struct ramo *ID;
} Ramo, *ARVORE;

typedef struct COORDENADA {
    int v;
    struct COORDENADA *prox;
} COORDENADA, *LISTAC;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna, linha;
} COORDENADA;

LISTA cloneL (LISTA l);

ARVORE inicializa_raiz (int x);

ARVORE inicializa_ramo (int x,ARVORE tree);

ARVORE insere_elementos(ARVORE tree,COORDENADA coordenada_atual);

#endif //RASTROS_DADOS_H
