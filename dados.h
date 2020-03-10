#ifndef __RASTROS_DADOS_H__
#define __RASTROS_DADOS_H__
typedef enum {VAZIA, BRANCA, PRETA} CASA;

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

int jogar(ESTADO *e, COORDENADA c);

int obter_numero_jogadas(ESTADO *estado);

CASA obter_estado_casa(ESTADO *e, COORDENADA c);
#endif //RASTROS_DADOS_H
