#include "dados.h"

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->tabela[8][8];
    e->jogadas[32];
    e->ultima_jogada.coluna = (-1);
    e->ultima_jogada.linha = (-1);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (i == 3 && j == 4)
                e->tabela[i][j] = BRANCA;
            else
                e->tabela[i][j] = VAZIA;
        }
    return e;
}

int obter_jogador_atual(ESTADO *estado){
    //Eu não sei se esta função é suposto mudar o jogador atual ou simplesmente devolver o atual
    if(estado->jogador_atual == 1)
        estado->jogador_atual = 2;
    else
        estado->jogador_atual = 1;
    return estado->jogador_atual;
}

CASA obter_estado_casa(ESTADO *estado, COORDENADA c){
    return (estado->tabela[c.linha][c.coluna]);
}

int jogar(ESTADO *e, COORDENADA c) {
    //Ainda não faz nada
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;}