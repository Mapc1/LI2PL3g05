#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int v;
    struct nodo *prox;
} Nodo, *LISTA;


////////Funções para transformar arrays em listas/////
LISTA fromArray (int v[], int N) {
    int i; LISTA r = NULL;

    for (i=N-1; i>=0; i--)
        r = insere_cabeca (r, v[i]);
    return r;
}

LISTA cons (int x, LISTA xs){
    LISTA r = malloc (sizeof (Nodo));
    r->v = x; r->prox = xs;

    return r;
}

//////////LISTAS///////
// Cria uma lista vazia
LISTA criar_lista(){
    LISTA l;
    l -> v = NULL;
}

// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor){
    LISTA r = malloc (sizeof (Nodo));
    r -> v = valor; r -> prox = L;
    return r;
}

// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L){
    int head;
    head = L -> v;
}

// Devolve a cauda da lista
LISTA proximo(LISTA L){
    LISTA r = L -> prox;
    return r;
}
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L){
    LISTA r = L -> prox;
    free(L);
    return r;
}

// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L){
    int x = 0;
    if(L -> v == NULL) x = 1;
    return x;
}