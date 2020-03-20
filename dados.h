#ifndef __RASTROS_DADOS_H__
#define __RASTROS_DADOS_H__
#include <stdio.h>
typedef enum {
    VAZIA = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

typedef struct {
    int coluna, linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tabela [8] [8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

ESTADO *inicializar_estado();

int obter_jogador_atual(ESTADO *estado);

int obter_numero_jogadas(ESTADO *estado);

void aumentar_numero_jogadas(ESTADO *estado);

int aux_jogar(ESTADO *estado, COORDENADA c);

CASA obter_estado_casa(ESTADO *e, COORDENADA c);


void muda_jogador(ESTADO *estado);

void insere_jogada (ESTADO *estado, COORDENADA j1, COORDENADA j2);

ESTADO *ler_ficheiro (ESTADO *estado, char *s);

void escreve_ficheiro (ESTADO *estado, char  *s);
#endif //RASTROS_DADOS_H
