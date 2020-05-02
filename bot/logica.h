/**
@file logica.h
Funções auxiliares à jogada do bot
*/

#ifndef BOT_LOGICA_H
#define BOT_LOGICA_H
#include "tree.h"
#include "dados.h"

/**
\brief Verifica se algum dos jogadores ganhou
@param estado Estado do jogo
@param jogadas_passadas Lista de jogadas passadas
Devolve um double que atribui valor a essa jogada
*/
double quem_ganha (ESTADO *estado, LISTA jogadas_passadas);

/**
\brief Escolhe a melhor jogada
@param estado Estado do jogo
@param tree Árvore de coordenadas
Efetua a jogada com melhor valor
*/
ESTADO *escolhe_coord(ESTADO *estado, ARVORE tree);

/**
\brief Atribui um valor à jogada
@param tree Árvore de coordenadas
*/
double valor_jogada(ARVORE tree);

#endif //BOT_LOGICA_H
