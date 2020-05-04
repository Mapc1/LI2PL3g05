/**
@file bot.h
Definição do bot
*/

#ifndef RASTROS_BOT_H
#define RASTROS_BOT_H
#include "bot.h"
#include "listas.h"

/**
\brief Verifica se alguma das jogadas possíveis resultam em vitória
@param estado Estado do jogo
@param c Coordenada de uma possível jogada
*/
int vai_ganhar (ESTADO *estado, COORDENADA c);

/**
\brief Calcula a distância de uma peça, até à peça final
@param d Coordenada final
@param c Coordenada de uma possível jogada
*/
double calcula_distancia (COORDENADA c,COORDENADA d);

/**
\brief Atribui valores a cada peça
@param estado Estado do jogo
@param c Coordenada de uma possível jogada
Os valores são atribuídos em função à distância da peça final, ou em função de uma possível vitória ou derrota
*/
double valor_da_peca (ESTADO *estado, COORDENADA c);

/**
\brief Copia uma coordenada
@param c Coordenada que se deseja copiar
A coordenada é copiada ocupando mais espaço de memoria
*/
COORDENADA *copiar_coord(COORDENADA c);

/**
\brief Cria a lista das jogadas possiveis
@param estado Estado atual
@param c Coordenada da ultima jogada
Da return da lista de todas as jogadas possiveis a volta da coordenada
*/
LISTA jogadas_possiveis (ESTADO *estado, COORDENADA c)
/**
 * 
\brief Comando que efetua uma jogada
@param estado Estado do jogo
Efetua jogada em função da menor distância para a vitória
*/
int comando_jog(ESTADO *estado);

#endif //RASTROS_BOT_H
