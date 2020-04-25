#include "logica.h"
#include "dados.h"
#include "listas.h"
#include "tree.h"

int quem_joga (ESTADO *estado, Ramo R){
    int counter = 0;

    while(R.jogadas_passadas != NULL)
        counter++;

    if(counter % 2 == 0)
        return obter_bot(estado);

    else if(obter_bot(estado) == 1)
        return 2;

    else return 1;
}

int ja_percorreu (COORDENADA coord, LISTA jogadas_passadas){
    while(jogadas_passadas->prox != NULL)
        if(coord.linha == jogadas_passadas->coord.linha &&
           coord.coluna == jogadas_passadas->coord.coluna)
            return 1;
    return 0;
}

int quem_ganha (ESTADO *estado,Ramo R){
    int counter = 0;
    if(obter_casa(estado, R.valor) == UM) {
        if (obter_bot(estado) == 1)
            return 1;
        else return -1;
    }
    else if(obter_casa(estado, R.valor) == DOIS) {
        if (obter_bot(estado) == 2)
            return 1;
        else return -1;
    }

    else if (quem_joga(estado, R) == obter_bot(estado))
        return -1;

    else return 1;
}

ESTADO *joga(ESTADO *estado){
    COORDENADA c = obter_ultima_jogada(estado);

    if(obter_bot(estado) == 1) {
        estado->tabuleiro[c.linha][c.coluna] = PRETA;
        estado->tabuleiro[c.linha + 1][c.coluna - 1] = BRANCA;
        estado->jogadas[estado->num_jogadas].jogador1 = (COORDENADA) { c.coluna, c.linha };
    }
    else{
        estado->tabuleiro[c.linha][c.coluna] = PRETA;
        estado->tabuleiro[c.linha - 1][c.coluna + 1] = BRANCA;
        estado->jogadas[estado->num_jogadas].jogador2 = (COORDENADA) { c.coluna, c.linha };
    }
    return estado;
}