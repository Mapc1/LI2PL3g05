#include "dados.h"

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->tabela[8][8];
    e->jogadas[32];
    e->ultima_jogada.coluna = 0;
    e->ultima_jogada.linha = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (i == 3 && j == 4)
                e->tabela[i][j] = BRANCA;
            else
                e->tabela[i][j] = VAZIA;
        }
    return e;
}

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;}