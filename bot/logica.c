#include "logica.h"
#include "dados.h"
#include "tree.h"
#include <stdarg.h>

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

int ja_percorreu (COORDENADA coord, LISTA jogadas_passadas){
    while(jogadas_passadas->prox != NULL)
        if(coord.linha == jogadas_passadas->coord.linha &&
           coord.coluna == jogadas_passadas->coord.coluna)
            return 1;
    return 0;
}

double quem_ganha (ESTADO *estado,LISTA jogadas_passadas) {
    int counter = 0;

    COORDENADA coord = devolve_cabeca(jogadas_passadas);
    COORDENADA coordNova
    ;
    double valor_da_jogada = 63 / tamanhodalista(jogadas_passadas);
    int i, o;
    if (obter_casa(estado, coord) == UM) {
        if (estado->bot == 1) return valor_da_jogada;
        else return (valor_da_jogada * (-1));
    }
    if (obter_casa(estado, coord) == DOIS) {
        if (estado->bot == 2) return valor_da_jogada;
        else return (valor_da_jogada * (-1));
    }


    for(i = coord.linha - 1; i <= coord.linha + 1; i++)
        for(o = coord.coluna - 1; o <= coord.coluna + 1; o++) {
            coordNova = (COORDENADA) {.coluna = i, .linha = o};
            if (
                    estado->tabuleiro[coordNova.linha][coordNova.coluna] == PRETA ||
                    estado->tabuleiro[coordNova.linha][coordNova.coluna] == BRANCA ||
                    nao_repete(jogadas_passadas, coordNova) ||
                    i > 7 || o > 7 ||
                    i < 0 || o < 0
                    )
                counter++;
        }

    if (counter == 8) {
        if (quem_joga(estado, jogadas_passadas) == estado->bot)
            return valor_da_jogada;
        else return valor_da_jogada;
    }
    else return 0;
}

double max (int num_count, ...){
    double num, max;
    va_list va;
    va_start(va, num_count);

    max = va_arg(va, double);

    for(int i = 0; i <= num_count; i++){
        num = va_arg(va, double);
        if(num > max)
            max = num;
    }

    return max;
}

double valor_jogada (ARVORE tree) {
    int vse, vsm, vsd, vme, vmd, vie, vim, vid;

    vse = 0;
    vsm = 0;
    vsd = 0;
    vme = 0;
    vmd = 0;
    vie = 0;
    vim = 0;
    vid = 0;

    if(tree->SE != NULL) vse = tree->SE->valor;
    if(tree->SM != NULL) vse = tree->SM->valor;
    if(tree->SD != NULL) vse = tree->SD->valor;
    if(tree->ME != NULL) vse = tree->ME->valor;
    if(tree->MD != NULL) vse = tree->MD->valor;
    if(tree->IE != NULL) vse = tree->IE->valor;
    if(tree->IM != NULL) vse = tree->IM->valor;
    if(tree->ID != NULL) vse = tree->ID->valor;

    if (tree == NULL)
        return 0;

    if (tree->ID == NULL && tree->IE == NULL && tree->IM == NULL && tree->MD == NULL && tree->ME == NULL &&
        tree->SD == NULL && tree->SE == NULL && tree->SM == NULL)
        return tree->valor;

    if (tree->SE != NULL)tree->SE->valor += valor_jogada(tree->SE);
    if (tree->SM != NULL)tree->SM->valor += valor_jogada(tree->SM);
    if (tree->SD != NULL)tree->SD->valor += valor_jogada(tree->SD);
    if (tree->ME != NULL)tree->ME->valor += valor_jogada(tree->ME);
    if (tree->MD != NULL)tree->MD->valor += valor_jogada(tree->MD);
    if (tree->IE != NULL)tree->IE->valor += valor_jogada(tree->IE);
    if (tree->ID != NULL)tree->ID->valor += valor_jogada(tree->ID);
    if (tree->IM != NULL)tree->IM->valor += valor_jogada(tree->IM);

    return vse + vsm + vsd + vme + vmd + vie + vim + vid;
}

ARVORE valor_jogada_recursiva (ARVORE tree){
    if(tree != NULL) {
        valor_jogada_recursiva(tree->SE);
        valor_jogada_recursiva(tree->SM);
        valor_jogada_recursiva(tree->SD);
        valor_jogada_recursiva(tree->ME);
        valor_jogada_recursiva(tree->MD);
        valor_jogada_recursiva(tree->IE);
        valor_jogada_recursiva(tree->IM);
        valor_jogada_recursiva(tree->ID);

        tree->valor = valor_jogada(tree);
    }
    return tree;
}

ESTADO *escolhe_coord(ESTADO *estado,ARVORE tree){
    double maior_valor;
    tree = tsm_Carlo(tree,estado, 4);

    maior_valor = max(8, tree->SE->valor,
                                   tree->SM->valor,
                                   tree->SD->valor,
                                   tree->ME->valor,
                                   tree->MD->valor,
                                   tree->IE->valor,
                                   tree->IM->valor,
                                   tree->ID->valor);

    if(maior_valor == tree->SE->valor) joga(estado, tree->SE->coord);
    else if(maior_valor == tree->SM->valor) joga(estado, tree->SM->coord);
    else if(maior_valor == tree->SD->valor) joga(estado, tree->SD->coord);
    else if(maior_valor == tree->ME->valor) joga(estado, tree->ME->coord);
    else if(maior_valor == tree->MD->valor) joga(estado, tree->MD->coord);
    else if(maior_valor == tree->IE->valor) joga(estado, tree->IE->coord);
    else if(maior_valor == tree->IM->valor) joga(estado, tree->IM->coord);
    else if(maior_valor == tree->ID->valor) joga(estado, tree->ID->coord);

    return estado;
}