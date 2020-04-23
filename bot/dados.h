#ifndef BOT_DADOS_H
#define BOT_DADOS_H

typedef enum{
    UM = '1',
    DOIS = '2',
    VAZIA = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

typedef struct{
    int coluna, linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tabuleiro[8][8];
    JOGADAS jogadas;
    int num_jogadas;
    int jogador;
} ESTADO;

ESTADO *inicializa_jogadas (ESTADO *estado);

ESTADO *ler_ficheiro (ESTADO *estado, char *nome);

void escreve_ficheiro (ESTADO *estado, char *nome);

CASA obter_casa (ESTADO *estado, COORDENADA c);
#endif //BOT_DADOS_H
