/**
@file logica.h
Definição do estado e das funções que o manipulam
*/

#ifndef RASTROS_LOGICA_H
#define RASTROS_LOGICA_H
#include "dados.h"

/**
\brief Comando que permite voltar para uma jogada anterior
@param estado Estado do jogo
@param arg Número da jogada a que queremos voltar
A utilização deste comando permite que o jogador volte para o número da jogada pertendida
*/
int comando_pos (ESTADO *estado, char *arg);

/**
\brief Verifica a possibilidade de jogadas válidas
@param estado Estado do jogo
verifica a possibilidade de jogadas válidas que cada jogador tem, caso um deles não possua uma jogada valida, declara a vitoria do outro 
(verifica primeiro o jogador 1, ou seja, caso nenhum tenha jogadas possiveis, a vitória é atribuida ao jogador 2)
*/
int jogada_impossivel (ESTADO *estado, COORDENADA a);

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

/**
\brief Guarda o tabuleiro atual
@param estado Estado do jogo
@param linha Nome do ficheiro
*/
int comando_gr (ESTADO *estado, char *linha);

/**
\brief Lê o tabuleiro escolhido
@param estado Estado do jogo
@param linha Nome do ficheiro
*/
int comando_ler (ESTADO *estado, char *linha);

/**
\brief Lê o comando a executar
@param s Comando
Dado uma string, esta função indica qual será o comando a utilizar
*/
int compara_comando (char *s);

#endif //RASTROS_LOGICA_H
