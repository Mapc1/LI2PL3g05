/**
@file interface.h
Definição do estado e das funções que o manipulam
*/

#ifndef __RASTROS_INTERFACE_H__
#define __RASTROS_INTERFACE_H__
#define BUF_SIZE 1024

/**
\brief Imprime o tabuleiro de jogo
@param e Estado do jogo
*/
void mostrar_tabuleiro(ESTADO *e);

/**
\brief Interpretador de comandos
@param e Estado do jogo
Função que recebe comandos, quer seja para :
-Efetuar jogar (quando recebe uma coordenada)
-Gravar o estado do jogo (gr "Nome_do_documento")
-Ler o estado do jogo (ler "Nome_do_documento")
-Sair (Q) do jogo
*/
int interpretador(ESTADO *e);

/**
\brief Comando que devolve os movimentos dos jogadores
@param estado Estado do jogo
A utilização deste comando devolve todas as movimentações feitas pelos jogadores
*/
int comando_movs(ESTADO *estado);
/**
\brief Função que devolve o comando escrito
@param linha Comando escrito
@param estado Estado do jogo
Esta função le a linha e devolve o seu comando correspondente
*/
int comando(char *linha, ESTADO *estado);
/**
\brief Função utilizada para verificar se o jogo chegou ao fim
@param e Estado do jogo
@param cord Coordenada do jogador
Esta função verifica se o jogo chegou no seu final, e caso isso aconteça, imprime uma mensagem a anunciar o vencedor
*/
int end_game(ESTADO *e, COORDENADA coord);
/**
\brief Função utilizada para descrever a jogada efetuada
@param e Estado do jogo
@param col Coluna do jogador
@param lin Linha do jogador
Esta função verifica da printf do jogador e de onde jogou
*/
void prompt(ESTADO *e,char *col,char *lin);
#endif //RASTROS_INTERFACE_H
