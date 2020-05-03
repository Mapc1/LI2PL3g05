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

/**
\brief Inicializa árvore de coordenadas
@param x Coordenada do jogador
@param tree Árvore de coordenadas
@estado Estado do jogo
Adiciona uma nova coordenada à lista de jogadas passadas e liga o novo ramo à árvore anterior
*/
ARVORE inicializa_ramo (ESTADO *estado, COORDENADA x, ARVORE tree);

/**
\brief Procura a melhor jogada
@param tree Árvore de coordenadas
@estado Estado do jogo
@repeticoes Número de vezes que a função irá ser utilizada recursivamente
Para obter a melhor jogada utiliza a eurística "Tree search Montecarlo"
*/
ARVORE tsm_Carlo(ARVORE tree,ESTADO *estado,int repeticoes);

/**
\brief Procura o melhor ramo para expandir a árvore
@param tree Árvore de coordenadas
@estado Estado do jogo
Procura os ramos com melhores jogadas, e expande a árvore nesse sentido
*/
ARVORE cria_folhas(ESTADO *estado, ARVORE tree);
#endif //RASTROS_DADOS_H
