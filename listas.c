#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

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
    return &head;
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
    if(L  == NULL) x = 1;
    return x;
}
