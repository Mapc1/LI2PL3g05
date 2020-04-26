#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "listas.h"
#include "dados.h"
#include "logica.h"

ARVORE inicializa_raiz (COORDENADA x){
    ARVORE tree = malloc (sizeof(Ramo));
    tree->coord = x;  
    tree->valor = 0;
    tree->passagens = 0;
    tree->fim = 0;
    tree->jogadas_passadas = malloc (sizeof(Nodo));
    tree->jogadas_passadas -> coord=x;
    tree->jogadas_passadas -> prox = NULL;
    tree->SE = NULL;
    tree->SM = NULL;
    tree->SD = NULL;
    tree->ME = NULL;
    tree->MD = NULL;
    tree->IE = NULL;
    tree->IM = NULL;
    tree->ID = NULL;
    return tree;
}

ARVORE inicializa_ramo (ESTADO* estado, COORDENADA x,ARVORE tree){
    ARVORE temp = malloc (sizeof(Ramo));
    temp->coord = x;  
    tree->valor = 0;
    tree->passagens = 0;
    tree->fim = quem_ganha(estado,tree);
    temp->jogadas_passadas = cloneL (tree->jogadas_passadas);
    temp->jogadas_passadas = insere_cabeca(x,temp->jogadas_passadas);
    temp->SE = NULL;
    temp->SM = NULL;
    temp->SD = NULL;
    temp->ME = NULL;
    temp->MD = NULL;
    temp->IE = NULL;
    temp->IM = NULL;
    temp->ID = NULL;
    return temp;
}

int rollout(ARVORE tree,ESTADO *estado){

    COORDENADA coordenada_atual = tree->coord;

    if (coordenadas_iguais (coordenada_atual,(COORDENADA) {.coluna = 7,.linha = 0})||
        coordenadas_iguais (coordenada_atual,(COORDENADA) {.coluna = 0,.linha = 7}))
        return quem_ganha(estado, tree);

    int i,o,posicao,indicernd=0,qualidadedajogada;
    COORDENADA cordNova;
    LISTA coordsrandom = NULL;

    for(i = coordenada_atual.linha - 1,posicao=0; i <= coordenada_atual.linha + 1; i++)
        for(o = coordenada_atual.coluna - 1; o <=coordenada_atual.coluna + 1; o++,posicao++)
            if((estado->tabuleiro[i][o] == VAZIA ||
                estado->tabuleiro[i][o] == UM ||
                estado->tabuleiro[i][o] == DOIS)
                && i<=7 && i>=0 && o<=7 && o>=0){
                
                indicernd++;
                cordNova = (COORDENADA) {.coluna = o,.linha = i};
                if(nao_repete(tree->jogadas_passadas,cordNova)){
                    coordsrandom = insere_cabeca(cordNova,coordsrandom);
                }
            }
    if(indicernd!=0){
        indicernd = rand() % indicernd-1;
        tree -> SE = inicializa_ramo(estado, cordNova,tree);
        qualidadedajogada = rollout(tree->SE,estado);
    }

    return quem_ganha(estado, tree);
}


ARVORE cria_folhas(ESTADO *estado, ARVORE tree){

    COORDENADA coordenada_atual = tree->coord;

    if(tree->fim!=0)
        return tree;

    int i,o,posicao;
    COORDENADA cordNova;

    for(i = coordenada_atual.linha - 1,posicao=0; i <= coordenada_atual.linha + 1; i++)
        for(o = coordenada_atual.coluna - 1; o <=coordenada_atual.coluna + 1; o++,posicao++)
            if((estado->tabuleiro[i][o] == VAZIA ||
                estado->tabuleiro[i][o] == UM ||
                estado->tabuleiro[i][o] == DOIS)
                && i<=7 && i>=0 && o<=7 && o>=0){
                
                cordNova = (COORDENADA) {.coluna = o,.linha = i};
                if(nao_repete(tree->jogadas_passadas,cordNova)){
                    if (posicao==0) tree -> SE = inicializa_ramo(estado, cordNova,tree);
                    if (posicao==1) tree -> SM = inicializa_ramo(estado, cordNova,tree);
                    if (posicao==2) tree -> SD = inicializa_ramo(estado, cordNova,tree);
                    if (posicao==3) tree -> ME = inicializa_ramo(estado, cordNova,tree);
                    if (posicao==4) tree -> MD = inicializa_ramo(estado, cordNova,tree);
                    if (posicao==5) tree -> IE = inicializa_ramo(estado, cordNova,tree);
                    if (posicao==6) tree -> IM = inicializa_ramo(estado, cordNova,tree);
                    if (posicao==7) tree -> ID = inicializa_ramo(estado, cordNova,tree);
                }
            }
    return tree;
}


ARVORE tsm_Carlo(ARVORE tree,ESTADO *estado,int repeticoes){
    if(repeticoes <1){
        return tree;
    }
    int i,j;
    ARVORE temp = tree;
    double value = 0,bestvalue=0;
    tree->passagens++;
    for (i=0,j=0;i<8;i++,temp = tree){
        if (i==0) temp = temp -> SE;
        if (i==1) temp = temp -> SM;
        if (i==2) temp = temp -> SD;
        if (i==3) temp = temp -> ME;
        if (i==4) temp = temp -> MD;
        if (i==5) temp = temp -> IE;
        if (i==6) temp = temp -> IM;
        if (i==7) temp = temp -> ID;
        value = temp->valor + 2*sqrt(log(tree->passagens)/temp->passagens);
        if(value>bestvalue){
            bestvalue = value;
            i = j;
        }
    }
    if (j==1) {
        temp = tree -> SE;
        if (temp->passagens >0){
            if(ramo_esta_vazio(temp)){
                temp = cria_folhas(estado, temp);
                if (ramo_esta_vazio(temp)){
                    temp->passagens++;
                }
                else tsm_Carlo(temp,estado,1);
            }
        }
        else {
            temp->valor = rollout (temp, estado);
            temp->passagens++; 
        }
    }
    melhorjogadarecursiva(tree);
    tsm_Carlo(tree, estado, repeticoes--);
}