#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "dados.h"

LISTA insere_cabeca (void *x, LISTA xs){
    LISTA r = malloc (sizeof (Nodo));
    r->v = x; r->prox = xs;

    return r;
}
LISTA fromArray (void *v[], int N, int tamcel) {
    int i; LISTA r = NULL;

    for (i=N-1; i>=0; i--){
        void *cel = malloc(tamcel);
        memcpy(cel,v[i],tamcel);
        r = insere_cabeca (cel, r);
    }
    return r;
}

LISTA criar_lista(){
    LISTA l = NULL;
}

void *devolve_cabeca(LISTA L){
    void *head;
    head = L -> v;
    return head;
}

LISTA proximo(LISTA L){
    LISTA r = L -> prox;
    return r;
}

LISTA remove_cabeca(LISTA L){
    LISTA r = L -> prox;
    free(L);
    return r;
}


int lista_esta_vazia(LISTA L){
    int x = 0;
    if(L == NULL) x = 1;
    return x;
}

ARVORE inicializa_ramo (int x){
    ARVORE tree = malloc (sizeof(Nodo));
    tree->valor = x;
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

ARVORE insere_elementos(ARVORE tree,int coordenadas[8]){
    int i;

    for (i=0;i<8;i++){
        if (1){
            if (i==0)
                tree->SE = inicializa_ramo(coordenadas[i]);
            if (i==1)
                tree->SM = inicializa_ramo(coordenadas[i]);
            if (i==2)
                tree->SD = inicializa_ramo(coordenadas[i]);
            if (i==3)
                tree->ME = inicializa_ramo(coordenadas[i]);
            if (i==4)
                tree->MD = inicializa_ramo(coordenadas[i]);
            if (i==5)
                tree->IE = inicializa_ramo(coordenadas[i]);
            if (i==6)
                tree->IM = inicializa_ramo(coordenadas[i]);
            if (i==7)
                tree->ID = inicializa_ramo(coordenadas[i]);
            }
        }
    return tree;
}

LISTA insere_cabeca (void *x, LISTA xs){
    LISTA r = malloc (sizeof (Nodo));
    r->v = x; r->prox = xs;

    return r;
}

int coordenada_valida (COORDENADA x){
    return 1;
}