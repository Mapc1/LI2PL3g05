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

ARVORE inicializa_ramo (ESTADO *estado, COORDENADA x, ARVORE tree);

ARVORE insere_elementos(ARVORE tree,CASA tabuleiro[8][8]);

#endif //RASTROS_DADOS_H
