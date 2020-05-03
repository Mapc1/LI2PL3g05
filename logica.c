#include "logica.h"
#include "dados.h"
#include "tree.h"
#include <stdarg.h>
#include "limits.h"

int quem_joga (ESTADO *estado, LISTA jogadas_passadas){
    int counter = 0;

    while(jogadas_passadas != NULL) {
        counter++;
        jogadas_passadas = jogadas_passadas->prox;
    }

    if(counter % 2 == 0)
        return obter_bot(estado);

    else if(obter_bot(estado) == 1)
        return 2;

    else return 1;
}

double quem_ganha (ESTADO *estado,LISTA jogadas_passadas) {
    int counter = 0, i, o;

    COORDENADA coord = devolve_cabeca(jogadas_passadas);
    COORDENADA coordNova;

    if (obter_casa(estado, coord) == UM) {
        if (estado->bot == 1) return 1;
        else return 0;
    }
    if (obter_casa(estado, coord) == DOIS) {
        if (estado->bot == 2) return 1;
        else return 0;
    }

    LISTA coordsrandom = NULL, listaclone = cloneL(jogadas_passadas);

    for (i = coord.linha - 1; i <= coord.linha + 1; i++)
        for (o = coord.coluna - 1; o <= coord.coluna + 1; o++)
            if ((estado->tabuleiro[i][o] == VAZIA ||
                 estado->tabuleiro[i][o] == UM    ||
                 estado->tabuleiro[i][o] == DOIS) &&
                i<=7 && i>=0 && o<=7 && o>=0
                    ) {
                coordNova = (COORDENADA) {.coluna = o, .linha = i};
                if (nao_repeteLista(listaclone, coordNova)) {
                    return -1;
                }
            }
    if (quem_joga(estado, jogadas_passadas) == estado->bot)
        return 1;
    else return 0;
}

double max (int num_count, ...){
    double num, max;
    va_list va;
    va_start(va, num_count);

    max = va_arg(va, double);

    for(int i = 2; i <= num_count; i++){
        num = va_arg(va, double);
        if(num > max)
            max = num;
    }

    return max;
}

void valor_jogada (ARVORE tree){
    tree=tree->passadas;
    while (tree!=NULL){
        tree->valor++;
        tree=tree->passadas;
    }
}

ESTADO *escolhe_coord(ESTADO *estado,ARVORE tree){
    double maior_valor, vse, vsm, vsd, vme, vmd, vie, vim, vid;
    tree = tsm_Carlo(tree,estado,20000);

    if(tree->SE == NULL) vse = LONG_MIN; else vse = tree->SE->valor;
    if(tree->SM == NULL) vsm = LONG_MIN; else vsm = tree->SM->valor;
    if(tree->SD == NULL) vsd = LONG_MIN; else vsd = tree->SD->valor;
    if(tree->ME == NULL) vme = LONG_MIN; else vme = tree->ME->valor;
    if(tree->MD == NULL) vmd = LONG_MIN; else vmd = tree->MD->valor;
    if(tree->IE == NULL) vie = LONG_MIN; else vie = tree->IE->valor;
    if(tree->IM == NULL) vim = LONG_MIN; else vim = tree->IM->valor;
    if(tree->ID == NULL) vid = LONG_MIN; else vid = tree->ID->valor;

    maior_valor = max(8, vse, vsm, vsd, vme, vmd, vie, vim, vid);

    if(maior_valor == vse) joga(estado, tree->SE->coord);
    else if(maior_valor == vsm) joga(estado, tree->SM->coord);
    else if(maior_valor == vsd) joga(estado, tree->SD->coord);
    else if(maior_valor == vme) joga(estado, tree->ME->coord);
    else if(maior_valor == vmd) joga(estado, tree->MD->coord);
    else if(maior_valor == vie) joga(estado, tree->IE->coord);
    else if(maior_valor == vim) joga(estado, tree->IM->coord);
    else if(maior_valor == vid) joga(estado, tree->ID->coord);

    return estado;
}