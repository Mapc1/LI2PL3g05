/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef __RASTROS_DADOS_H__
#define __RASTROS_DADOS_H__
#include <stdio.h>

/**
\brief Tipo de dados para a casa
*/
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIA = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna, linha;
} COORDENADA;

/**
\brief Tipo de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado
*/
typedef struct {
    CASA tabela[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

/**
\brief Inicializa o estado do jogo
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
*/
ESTADO *inicializar_estado();

/**
\brief Devolve o estado de um jogador
@param estado Estado do jogo
*/
int obter_jogador_atual(ESTADO *estado);

/**
\brief Devolve o número de jogadas
@param estado do jogo
*/
int obter_numero_jogadas(ESTADO *estado);
/**
\brief Aumenta em um, o numero de jogadas
@param estado Estado do jogo
*/
void aumentar_numero_jogadas(ESTADO *estado);

/**
\brief 
@param estado Estado do jogo
@para c Coordenada atual do jogador
*/
int aux_jogar(ESTADO *estado, COORDENADA c);

/**
\brief Verifica se a casa está ocupada ou vazia
@param e Estado do jogo
@param c Coordenada da casa
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

/**
\brief Muda o jogador de casa
@param estado Estado do jogo
*/
void muda_jogador(ESTADO *estado);

/**
\brief Atualiza a posição dos jogadores
@param estado Estado do jogo
@param j1 Coordenada da casa do jogador 1
@param j2 Coordenada da casa do jogador 2
*/
void insere_jogada (ESTADO *estado, COORDENADA j1, COORDENADA j2);

/**
\brief Lê um ficheiro
@param estado Estado do jogo
@param s Nome do ficheiro
Lê o estado do jogo presente no ficheiro
*/
ESTADO *ler_ficheiro (ESTADO *estado, char *s);

/**
\brief Guarda estado do jogo
@param estado Estado do jogo
@param s Nome do ficheiro
Guarda o estado do jjogo num ficheiro
*/
void escreve_ficheiro (ESTADO *estado, char  *s);
#endif //RASTROS_DADOS_H
