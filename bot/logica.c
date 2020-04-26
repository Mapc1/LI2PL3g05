#include "logica.h"
#include "dados.h"
#include "listas.h"
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


double max(double vse, double vsm, double vsd, double vme, double vmd, double vie,double vim, double vid){
    if(vse > vsm && vse > vsd && vse > vme && vse > vmd && vse > vie && vse > vim && vse > vid){
        return vse;
    }

    else if(vsd> vsm && vsd > vse && vsd > vme && vsd > vmd && vsd > vie && vsd > vim && vsd > vid){
        return vsd;
    }
    else if(vsm > vse && vsm > vsd && vsm > vme && vsm > vmd && vsm > vie && vsm > vim && vsm > vid){
        return vsm;
    }

    else if(vme > vsm && vme > vsd && vme > vse && vme > vmd && vme > vie && vme > vim && vme > vid){
        return vme;
    }
    else if(vmd > vsm && vmd > vsd && vmd > vme && vmd > vse && vse > vie && vmd > vim && vmd > vid){
        return vmd;
    }
    else if(vie > vsm && vie > vsd && vie > vme && vie > vmd && vie > vse && vse > vim && vie > vid){
        return vie;
    }

    else if(vim > vsm && vim > vsd && vim > vme && vim > vmd && vim > vie && vim > vse && vim > vid){
        return vim;
    }
    else if(vid > vsm && vid > vsd && vid > vme && vid > vmd && vid > vie && vid > vim && vid > vse){
        return vid;
    }
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

ESTADO *joga(ESTADO *estado,ARVORE tree){
    double vse, vsm, vsd, vme, vmd, vie, vim, vid;
    tree = inicializa_raiz(obter_ultima_jogada(estado));

    tree = insere_elementos(tree, estado->tabuleiro);

    vse = valor_jogada(tree->SE);
    vsm = valor_jogada(tree->SM);
    vsd = valor_jogada(tree->SD);
    vme = valor_jogada(tree->ME);
    vmd = valor_jogada(tree->MD);
    vie = valor_jogada(tree->IE);
    vid = valor_jogada(tree->ID);
    vim = valor_jogada(tree->IM);

    if(vse == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->SE->coord.linha][tree->SE->coord.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vsm == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->SM->coord.linha][tree->SM->coord.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vsd == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->SD->coord.linha][tree->SD->coord.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vie == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->IE->coord.linha][tree->IE->coord.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vim == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->IM->coord.linha][tree->IM->coord.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vid == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->ID->coord.linha][tree->ID->coord.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vme == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->ME->coord.linha][tree->ME->coord.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vmd == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->MD->coord.linha][tree->MD->coord.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    return estado;
}