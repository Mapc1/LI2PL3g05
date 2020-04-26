#include "logica.h"
#include "dados.h"
#include "tree.h"

int quem_joga (ESTADO *estado, ARVORE tree){
    int counter = 0;

    while(tree->jogadas_passadas != NULL)
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

int quem_ganha (ESTADO *estado,ARVORE tree) {
    int counter = 0;

    COORDENADA coord = (COORDENADA) {tree->coord.coluna, tree->coord.linha};

    if (obter_casa(estado, coord) == UM) {
        if (estado->bot == 1) {
            if (quem_joga(estado, tree) == estado->bot)
                return 1;
            else return 0;
        } else if (quem_joga(estado, tree) == estado->bot)
            return 0;
        else return -1;
    } else if (obter_casa(estado, coord) == DOIS) {
        if (estado->bot == 2) {
            if (quem_joga(estado, tree) == estado->bot)
                return 1;
            else return 0;
        } else if (quem_joga(estado, tree) == estado->bot)
            return 0;
        else return -1;
    }

    for (int i = -1; i <= 1; i++)
        for (int o = -1; o <= 1; o++)
            if (obter_casa(estado, coord) == PRETA || obter_casa(estado, coord) == BRANCA ||
                ja_percorreu(coord, tree->jogadas_passadas))
                counter++;

    if (counter == 8) {
        if (quem_joga(estado, tree) == estado->bot)
            return 1;
        else return -1;
    }
    else return 0;
}

double valor_jogada (ARVORE tree) {
    tree->SE->valor = 0;
    tree->SM->valor = 0;
    tree->SD->valor = 0;
    tree->ME->valor = 0;
    tree->MD->valor = 0;
    tree->IE->valor = 0;
    tree->IM->valor = 0;
    tree->ID->valor = 0;

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

    return tree->SE->valor + tree->SM->valor + tree->SD->valor + tree->ME->valor + tree->MD->valor + tree->IE->valor + tree->IM->valor + tree->ID->valor;
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

ESTADO *joga(ESTADO *estado,ARVORE tree){
    tree = tsm_Carlo(tree,estado, 10);
//  .
//  .
//  .
    return estado;
}