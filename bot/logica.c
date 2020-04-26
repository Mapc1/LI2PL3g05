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

    COORDENADA coord = (COORDENADA) { R.valor.coluna, R.valor.linha };

    if(obter_casa(estado, coord) == UM) {
        if (estado->bot == 1) {
            if (quem_joga(estado, R) == estado->bot)
                return 1;
            else return 0;
        }
        else if (quem_joga(estado, R) == estado->bot)
            return 0;
        else return -1;
    }

    else if(obter_casa(estado, coord) == DOIS) {
        if (estado->bot == 2) {
            if (quem_joga(estado, R) == estado->bot)
                return 1;
            else return 0;
        }
        else if (quem_joga(estado, R) == estado->bot)
            return 0;
        else return -1;
    }
    for(int i = -1; i <= 1; i++)
        for(int o = -1; o<= 1; o++){
            else if(obter_casa(estado, coord) == PRETA || obter_casa(estado, coord) == BRANCA || ja_percorreu(coord, R.jogadas_passadas))
                counter++;
        }
    if (counter == 8){
        if(quem_joga(estado, R) == estado->bot)
            return 1;
        else return -1;
    }
} 

int max(int vse, int vsm, int vsd, int vme, int vmd, int vie, int vim, int vid){
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

int melhor_jogada (ARVORE tree) {
    int vse, vsm, vsd, vme, vmd, vie, vim, vid;
    vse = vsm = vsd = vme = vmd = vie = vim = vid = 0;

    if (tree == NULL)
        return 0;
    if (tree->ID == NULL && tree->IE == NULL && tree->IM == NULL && tree->MD == NULL && tree->ME == NULL &&
        tree->SD == NULL && tree->SE == NULL && tree->SM == NULL)
        return tree->valor.coluna - 7 + tree->valor.linha;

    if (tree->SE != NULL)vse = melhor_jogada(tree->SE);
    if (tree->SM != NULL)vsm = melhor_jogada(tree->SM);
    if (tree->SD != NULL)vsd = melhor_jogada(tree->SD);
    if (tree->ME != NULL)vme = melhor_jogada(tree->ME);
    if (tree->MD != NULL)vmd = melhor_jogada(tree->MD);
    if (tree->IE != NULL)vie = melhor_jogada(tree->IE);
    if (tree->ID != NULL)vid = melhor_jogada(tree->ID);
    if (tree->IM != NULL)vim = melhor_jogada(tree->IM);

    return vse + vsm + vsd + vme + vmd + vie + vim + vid;
}

ESTADO *joga(ESTADO *estado,ARVORE tree){
    int vse, vsm, vsd, vme, vmd, vie, vim, vid;
    ARVORE tree = inicializa_raiz(obter_ultima_jogada(estado));

    tree = insere_elementos(tree, estado->tabuleiro, 0);

    vse = melhor_jogada(tree->SE);
    vsm = melhor_jogada(tree->SM);
    vsd = melhor_jogada(tree->SD);
    vme = melhor_jogada(tree->ME);
    vmd = melhor_jogada(tree->MD);
    vie = melhor_jogada(tree->IE);
    vid = melhor_jogada(tree->ID);
    vim = melhor_jogada(tree->IM);

    if(vse == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->SE->valor.linha][tree->SE->valor.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vsm == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->SM->valor.linha][tree->SM->valor.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vsd == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->SD->valor.linha][tree->SD->valor.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vie == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->IE->valor.linha][tree->IE->valor.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vim == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->IM->valor.linha][tree->IM->valor.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vid == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->ID->valor.linha][tree->ID->valor.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vme == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->ME->valor.linha][tree->ME->valor.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    if(vmd == max(vse, vsm, vsd, vme, vmd, vie, vim, vid)){
        estado->tabuleiro[tree->MD->valor.linha][tree->MD->valor.coluna] = BRANCA;
        estado->tabuleiro[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    }
    return estado;
}