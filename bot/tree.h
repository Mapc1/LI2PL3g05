/**
@file dados.h
Definição de árvore e das funções que a manipulam
*/

#ifndef __RASTROS_TREES_H__
#define __RASTROS_TREES_H__

#include <stdio.h>
#include <stdlib.h>


typedef struct ramo {
    int valor;
    LISTA jogadas_passadas;
    struct ramo *SE;
    struct ramo *SM;
    struct ramo *SD;
    struct ramo *ME;
    struct ramo *MD;
    struct ramo *IE;
    struct ramo *IM;
    struct ramo *ID;
} Ramo, *ARVORE;

typedef struct COORDENADA {
    int v;
    struct COORDENADA *prox;
} COORDENADA, *LISTAC;

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
    int undo;
} ESTADO;


#endif //RASTROS_DADOS_H
