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
    COORDENADA jogador1, jogador2;
} JOGADA;

/**
\brief Tipo de dados para as listas
*/
typedef struct nodo {
    COORDENADA coord;
    struct nodo *prox;
} Nodo, *LISTA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tabuleiro[8][8];
    JOGADAS jogadas;
    COORDENADA ultima_jogada;
    int num_jogadas, bot;
} ESTADO;

typedef struct ramo {
    COORDENADA valor;
    LISTA jogadas_passadas;
    struct ramo *SE, *SM, *SD,
                *ME,      *MD,
                *IE, *IM, *ID;
} Ramo, *ARVORE;


ESTADO *inicializa_jogadas (ESTADO *estado);

ESTADO *ler_ficheiro (ESTADO *estado, char *nome);

void escreve_ficheiro (ESTADO *estado, char *nome);

CASA obter_casa (ESTADO *estado, COORDENADA c);

int obter_bot (ESTADO *estado);

COORDENADA obter_ultima_jogada (ESTADO *estado);
#endif //BOT_DADOS_H
