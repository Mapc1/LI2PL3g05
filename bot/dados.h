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
    COORDENADA ultima_jogada;
    int num_jogadas;
    int bot;
} ESTADO;

typedef struct nodo {
    COORDENADA coord;
    struct nodo *prox;
} Nodo, *LISTA;

typedef struct ramo {
    COORDENADA coord;
    LISTA jogadas_passadas;
    double valor;
    double passagens;
    struct ramo *SE;
    struct ramo *SM;
    struct ramo *SD;
    struct ramo *ME;
    struct ramo *MD;
    struct ramo *IE;
    struct ramo *IM;
    struct ramo *ID;
} Ramo, *ARVORE;

ESTADO *inicializa_jogadas (ESTADO *estado);

ESTADO *ler_ficheiro (ESTADO *estado, char *nome);

void escreve_ficheiro (ESTADO *estado, char *nome);

CASA obter_casa (ESTADO *estado, COORDENADA c);

int obter_bot(ESTADO *estado);

COORDENADA obter_ultima_jogada(ESTADO *estado);

ESTADO *joga(ESTADO *estado, COORDENADA coord);
#endif //BOT_DADOS_H
