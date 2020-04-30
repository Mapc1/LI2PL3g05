/**
@file dados.h
Definição de árvore e das funções que a manipulam
*/

#ifndef __RASTROS_TREES_H__
#define __RASTROS_TREES_H__

#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

ARVORE inicializa_raiz (COORDENADA x);

int ramo_esta_vazio(ARVORE tree);

ARVORE inicializa_ramo (ESTADO *estado, COORDENADA x, ARVORE tree);

ARVORE tsm_Carlo(ARVORE tree,ESTADO *estado,int repeticoes);

ARVORE cria_folhas(ESTADO *estado, ARVORE tree);
#endif //RASTROS_DADOS_H
