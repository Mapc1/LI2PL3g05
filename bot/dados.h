/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef BOT_DADOS_H
#define BOT_DADOS_H

/**
\brief Tipo de dados para a casa
*/
typedef enum{
    UM = '1',
    DOIS = '2',
    VAZIA = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct{
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
    CASA tabuleiro[8][8];
    JOGADAS jogadas;
    COORDENADA ultima_jogada;
    int num_jogadas;
    int bot;
} ESTADO;

/**
\brief Tipo de dados para uma lista de coordenadas
*/
typedef struct nodo {
    COORDENADA coord;
    struct nodo *prox;
} Nodo, *LISTA;

/**
\brief Tipo de dados para uma árvore de coordenadas
*/
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

/**
\brief Inicializa a árvore de coordenadas
Cria uma árvore de coordenadas vazia
*/
ESTADO *inicializa_jogadas (ESTADO *estado);

/**
\brief Lê um ficheiro
@param estado Estado do jogo
@param nome Nome do ficheiro
Lê o estado do jogo presente no ficheiro
*/
ESTADO *ler_ficheiro (ESTADO *estado, char *nome);

/**
\brief Guarda estado do jogo
@param estado Estado do jogo
@param nome Nome do ficheiro
Guarda o estado do jogo num ficheiro
*/
void escreve_ficheiro (ESTADO *estado, char *nome);

/**
\brief Devolve casa atual
@param estado Estado do jogo
@param c Coordenada atual
Guarda o estado do jogo num ficheiro
*/
CASA obter_casa (ESTADO *estado, COORDENADA c);

/**
\brief Devolve o número do jogador
@param estado Estado do jogo
Procura no estado qual é o jogador o qual o bot irá jogar
*/
int obter_bot(ESTADO *estado);

/**
\brief Verifica qual foi a ultima jogada
@param estado Estado do jogo
*/
COORDENADA obter_ultima_jogada(ESTADO *estado);

/**
\brief Efetua a jogada
@param estado Estado do jogo
@param coord Nova coordenada
*/
ESTADO *joga(ESTADO *estado, COORDENADA coord);
#endif //BOT_DADOS_H
