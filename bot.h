/**
@file bot.h
Definição do bot
*/

#ifndef RASTROS_BOT_H
#define RASTROS_BOT_H
#include "bot.h"

/**
\brief Calcula a distância até à meta
@param d Coordenada da meta
@param c Coordenada do jogador
Calcula a distância até ao destino
*/
double calcula_distancia (COORDENADA c,COORDENADA d);

/**
\brief Verifica qual é a melhor peça para efetuar a jogada
@param estado Estado do jogo
@param c Coordenada do jogador
Comparando as distâncias das jogadas possíveis até ao destino, devolve a mais curta
*/
double valor_da_peca (ESTADO *estado, COORDENADA c);

/**
\brief Efetua a jogada do jogador
@param estado Estado do jogo
*/
int comando_jog(ESTADO *estado);

#endif //RASTROS_BOT_H
