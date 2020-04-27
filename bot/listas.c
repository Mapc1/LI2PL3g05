#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "dados.h"

LISTA insere_cabeca (COORDENADA x, LISTA xs){
    LISTA r = malloc (sizeof (Nodo));
    r->coord = x; r->prox = xs;

    return r;
}

int lista_esta_vazia(LISTA L){
    int x = 0;
    if(L == NULL) x = 1;
    return x;
}

LISTA cloneL (LISTA l) {
    if(!l) return NULL; 
    LISTA new = malloc(sizeof(struct nodo));
    new -> coord = l -> coord;
    new -> prox = cloneL(l->prox);
    return new;
}

int coordenadas_iguais (COORDENADA x,COORDENADA y){
    if (x.coluna == y.coluna &&
        x.linha == y.linha)
        return 1;
    return 0;
}

int nao_repete(LISTA l,COORDENADA x){

for(;l!=NULL;l=l->prox){
    if (coordenadas_iguais(l->coord,x))
      return 0;
  }
  return 1;
}


COORDENADA indice_lista(LISTA lista, int indice){
    int i;
    for(i=0;i<indice;i++) lista=lista->prox;
    COORDENADA coord;
    coord=lista->coord;
    return coord;
}

int tamanhodalista (LISTA lista){
    if (lista == NULL) return 0;
    LISTA temp = lista;
    int tamanho;
    for (tamanho = 0;temp!=NULL;temp = temp->prox,tamanho++);
    return tamanho;
}

COORDENADA devolve_cabeca(LISTA L){
    COORDENADA head;
    head = L -> coord;
    return head;
}

void freeL(LISTA l) {
    while(l) {
        LISTA temp = l;
        l = l->prox;
        free(temp);
    }
}

