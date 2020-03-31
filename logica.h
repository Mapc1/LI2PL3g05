/**
@file logica.h
Definição do estado e das funções que o manipulam
*/

#ifndef RASTROS_LOGICA_H
#define RASTROS_LOGICA_H
#include "dados.h"

/**
\brief Verifica a possibilidade de jogadas válidas
@param estado Estado do jogo
verifica a possibilidade de jogadas válidas que cada jogador tem, caso um deles não possua uma jogada valida, declara a vitoria do outro 
(verifica primeiro o jogador 1, ou seja, caso nenhum tenha jogadas possiveis, a vitória é atribuida ao jogador 2)
*/
int jogada_impossivel (ESTADO *estado); 

/**
\brief Verifica se a jogada é válida
@param estado estado do jogo
@param c Coordenada de um jogador
*/
int valida_jogada (ESTADO *estado, COORDENADA c); 

/**
\brief Efetua a jogada
@param e estado do jogo
@param c Coordenada de um jogador
Com auxilio da "valida_jogada" verifica se a jogada é válida e caso seja, utiliza a "aux_jogar" e a "muda_jogador" para alterar o estado do jogo
*/
int jogar (ESTADO *e, COORDENADA c);

/**
\brief Anuncia vencedor
@param c Coordenada de um jogador
Verifica se algum dos jogadores ganhou, e imprime a mensagem a anunciar o vencedor
*/
int fim_do_jogo (ESTADO *estado, COORDENADA c);

int comando_gr (ESTADO *estado, char *linha);

int comando_ler (ESTADO *estado, char *linha);

int compara_comando (char *s);
#endif //RASTROS_LOGICA_H
