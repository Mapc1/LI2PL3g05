#include <stdio.h>
#include <stdlib.h>
#include "trees.h"
#include "listas.h"

LISTA cloneL (LISTA l) {
    if(!l) return NULL; 
    LISTA new = malloc(sizeof(struct nodo));
    new -> v = l -> v;
    new -> prox = cloneL(l->prox);
    return new;
}


ARVORE inicializa_raiz (int x){
    ARVORE tree = malloc (sizeof(Ramo));
    tree->valor = x;  
    tree->jogadas_passadas = malloc (sizeof(Nodo));
    tree->jogadas_passadas -> v=x;
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

ARVORE inicializa_ramo (int x,ARVORE tree){
    ARVORE temp = malloc (sizeof(Ramo));
    temp->valor = x;  
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

ARVORE insere_elementos(ARVORE tree,COORDENADA coordenada_atual){
    int i;

            i = compara_coordenada(coordenadas_atual);
            if (i==0)
                tree -> SE = inicializa_ramo(coordenada_atual,tree);
            if (i==1)
                tree -> SM = inicializa_ramo(coordenada_atual,tree);
            if (i==2)
                tree -> SD = inicializa_ramo(coordenada_atual,tree);
            if (i==3)
                tree -> ME = inicializa_ramo(coordenada_atual,tree);
            if (i==4)
                tree -> MD = inicializa_ramo(coordenada_atual,tree);
            if (i==5)
                tree -> IE = inicializa_ramo(coordenada_atual,tree);
            if (i==6)
                tree -> IM = inicializa_ramo(coordenada_atual,tree);
            if (i==7)
                tree -> ID = inicializa_ramo(coordenada_atual,tree);

    return tree;
}

// OU

ARVORE insere_elementos(ARVORE tree,LISTA coordenadas){

            int i = compara_coordenada(coordenadas->v);

            if (i==0){
                tree -> SE = inicializa_ramo(coordenadas,tree);
                insere_elementos(tree->SE,coordenadas->prox);
            }
            if (i==1){
                tree -> SM = inicializa_ramo(coordenadas,tree);
                insere_elementos(tree->SM,coordenadas->prox);
            }
            if (i==2){
                tree -> SD = inicializa_ramo(coordenadas,tree);
                insere_elementos(tree->SD,coordenadas->prox);
            }
            if (i==3){
                tree -> ME = inicializa_ramo(coordenadas,tree);
                insere_elementos(tree->ME,coordenadas->prox);
            }
            if (i==4){
                tree -> MD = inicializa_ramo(coordenadas,tree);
                insere_elementos(tree->MD,coordenadas->prox);
            }
            if (i==5){
                tree -> IE = inicializa_ramo(coordenadas,tree);
                insere_elementos(tree->IE,coordenadas->prox);
            }
            if (i==6){
                tree -> IM = inicializa_ramo(coordenadas,tree);
                insere_elementos(tree->IM,coordenadas->prox);
            }
            if (i==7){
                tree -> ID = inicializa_ramo(coordenadas,tree);
                insere_elementos(tree->ID,coordenadas->prox);
            }
    return tree;
}

int compara_coordenada(COORDENADA coordenada){
    ...
}
