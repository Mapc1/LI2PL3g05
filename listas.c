#include <stdio.h>
#include <stdlib.h>

LISTA insere_cabeca (void *x, LISTA xs){
    LISTA r = malloc (sizeof (Nodo));
    r->v = x; r->prox = xs;

    return r;
}
LISTA fromArray (int v[], int N) {
    int i; LISTA r = NULL;

    for (i=N-1; i>=0; i--)
        r = insere_cabeca (v[i], r);
    return r;
}

LISTA criar_lista(){
    LISTA l = NULL;
}

void *devolve_cabeca(LISTA L){
    int head;
    head = L -> v;
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
    if(L -> v == NULL) x = 1;
    return x;
}
