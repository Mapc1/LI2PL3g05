#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "listas.h"
#include "dados.h"

ARVORE inicializa_raiz (COORDENADA x){
    ARVORE tree = malloc (sizeof(Ramo));
    tree->valor = x;  
    tree->jogadas_passadas = malloc (sizeof(Nodo));
    tree->jogadas_passadas->coord = x;
    tree->jogadas_passadas->prox = NULL;

    tree->SE = tree->SM = tree->SD =
    tree->ME =            tree->MD =
    tree->IE = tree->IM = tree->ID = NULL;

    return tree;
}

ARVORE inicializa_ramo (COORDENADA x,ARVORE tree){
    ARVORE temp = malloc (sizeof(Ramo));
    temp->valor = x;  
    temp->jogadas_passadas = cloneL (tree->jogadas_passadas);
    temp->jogadas_passadas = insere_cabeca(x,temp->jogadas_passadas);

    temp->SE = temp->SM = temp->SD =
    temp->ME =            temp->MD =
    temp->IE = temp->IM = temp->ID = NULL;

    return temp;
}

ARVORE insere_elementos(ARVORE tree,CASA tabuleiro[8][8]){

    COORDENADA coordenada_atual = tree->valor;

    if (coordenadas_iguais (coordenada_atual,(COORDENADA) {.coluna = 7,.linha = 0})||
        coordenadas_iguais (coordenada_atual,(COORDENADA) {.coluna = 0,.linha = 7}))
        return tree;

    int i,o,posicao;
    COORDENADA cordNova;

    for(i = coordenada_atual.linha - 1,posicao=0; i <= coordenada_atual.linha + 1; i++)
        for(o = coordenada_atual.coluna - 1; o <=coordenada_atual.coluna + 1; o++,posicao++)
            if((tabuleiro[i][o] == VAZIA ||
                tabuleiro[i][o] == UM ||
                tabuleiro[i][o] == DOIS)
                && i<=7 && i>=0 && o<=7 && o>=0){
                
                cordNova = (COORDENADA) {.coluna = o,.linha = i};
                if(nao_repete(tree->jogadas_passadas,cordNova)){

                    if (posicao==0){
                        tree -> SE = inicializa_ramo(cordNova,tree);
                        insere_elementos(tree->SE,tabuleiro);
                    }
                    if (posicao==1){
                        tree -> SM = inicializa_ramo(cordNova,tree);
                        insere_elementos(tree->SM,tabuleiro);
                    }
                    if (posicao==2){
                        tree -> SD = inicializa_ramo(cordNova,tree);
                        insere_elementos(tree->SD,tabuleiro);
                    }
                    if (posicao==3){
                        tree -> ME = inicializa_ramo(cordNova,tree);
                        insere_elementos(tree->ME,tabuleiro);
                    }
                    if (posicao==4){
                        tree -> MD = inicializa_ramo(cordNova,tree);
                        insere_elementos(tree->MD,tabuleiro);
                    }
                    if (posicao==5){
                        tree -> IE = inicializa_ramo(cordNova,tree);
                        insere_elementos(tree->IE,tabuleiro);
                    }
                    if (posicao==6){
                        tree -> IM = inicializa_ramo(cordNova,tree);
                        insere_elementos(tree->IM,tabuleiro);
                    }
                    if (posicao==7){
                        tree -> ID = inicializa_ramo(cordNova,tree);
                        insere_elementos(tree->ID,tabuleiro);
                    }
                }
            }
    return tree;
}
