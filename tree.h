/**
@file tree.h
Funções que manipulam a árvore
*/

#ifndef __RASTROS_TREES_H__
#define __RASTROS_TREES_H__

#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/**
\brief Inicializa árvore de coordenadas
@param x Coordenada atual
Insere a coordenada atual na lista de jogadas passadas, e inicializa os restantes parâmetros com NULL
*/
ARVORE inicializa_raiz (COORDENADA x);

/**
\brief Verifica se a Árvore está vazia
*/
int ramo_esta_vazio(ARVORE tree);
int nao_repete(ARVORE tree,COORDENADA x);
/**
\brief Inicializa árvore de coordenadas
@param x Coordenada atual
Insere a coordenada atual na lista de jogadas passadas, e inicializa os restantes parâmetros com NULL
*/
ARVORE inicializa_ramo (ESTADO *estado, COORDENADA x, ARVORE tree);

ARVORE tsm_Carlo(ARVORE tree,ESTADO *estado,int repeticoes);

ARVORE cria_folhas(ESTADO *estado, ARVORE tree);
#endif //RASTROS_DADOS_H
