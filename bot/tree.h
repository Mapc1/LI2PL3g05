/**
@file dados.h
Definição de árvore e das funções que a manipulam
*/

#ifndef __RASTROS_TREES_H__
#define __RASTROS_TREES_H__

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "listas.h"


typedef struct ramo {
    COORDENADA valor;
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



ARVORE inicializa_raiz (COORDENADA x);

ARVORE inicializa_ramo (COORDENADA x,ARVORE tree);

ARVORE insere_elementos(ARVORE tree,CASA tabuleiro[8][8]);

#endif //RASTROS_DADOS_H
