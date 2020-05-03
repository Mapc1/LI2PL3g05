#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "listas.h"
#include "dados.h"
#include "logica.h"
#include "limits.h"
#include "float.h"

ARVORE inicializa_raiz (COORDENADA x){
    ARVORE tree = malloc (sizeof(Ramo));
    tree->coord = x;  
    tree->valor = 0;
    tree->passagens = 0;
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

double rollout(LISTA jogadas_passadas,ESTADO *estado){

    COORDENADA coordenada_atual = devolve_cabeca(jogadas_passadas);

    if (quem_ganha(estado,jogadas_passadas) != 0)
        return quem_ganha(estado,jogadas_passadas);

    int i,o,indicernd=0;
    COORDENADA cordNova;

    LISTA coordsrandom = NULL,listaclone = cloneL(jogadas_passadas);

    while (quem_ganha(estado,listaclone)==0){
        for(i = coordenada_atual.linha - 1,indicernd=0; i <= coordenada_atual.linha + 1; i++)
            for(o = coordenada_atual.coluna - 1; o <=coordenada_atual.coluna + 1; o++)
                if((estado->tabuleiro[i][o] == VAZIA ||
                    estado->tabuleiro[i][o] == UM ||
                    estado->tabuleiro[i][o] == DOIS)
                   && i<=7 && i>=0 && o<=7 && o>=0){

                    cordNova = (COORDENADA) {.coluna = o,.linha = i};
                    if(nao_repete(listaclone,cordNova) == 1){
                        coordsrandom = insere_cabeca(cordNova,coordsrandom);
                        indicernd++;
                    }
                }
        if(indicernd == 0)
            printf("deu merda\n");
        if(indicernd == 1){
            cordNova = indice_lista(coordsrandom, 0);
            listaclone = insere_cabeca(cordNova,listaclone);
        }
        else if(indicernd!=0){
            indicernd = rand() % (indicernd-1);
            cordNova = indice_lista(coordsrandom, indicernd);
            listaclone = insere_cabeca(cordNova,listaclone);
        }
        coordsrandom = freeL(coordsrandom);
        coordenada_atual = cordNova;
    }

    int valor_da_jogada = quem_ganha(estado, listaclone);
    listaclone = freeL(listaclone);
    return valor_da_jogada;
}


ARVORE cria_folhas(ESTADO *estado, ARVORE tree){

    COORDENADA coordenada_atual = tree->coord;

    if (coordenadas_iguais (coordenada_atual,(COORDENADA) {.coluna = 7,.linha = 0})||
        coordenadas_iguais (coordenada_atual,(COORDENADA) {.coluna = 0,.linha = 7}))
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
                    else if (posicao==1) tree -> SM = inicializa_ramo(estado, cordNova,tree);
                    else if (posicao==2) tree -> SD = inicializa_ramo(estado, cordNova,tree);
                    else if (posicao==3) tree -> ME = inicializa_ramo(estado, cordNova,tree);
                    else if (posicao==5) tree -> MD = inicializa_ramo(estado, cordNova,tree);
                    else if (posicao==6) tree -> IE = inicializa_ramo(estado, cordNova,tree);
                    else if (posicao==7) tree -> IM = inicializa_ramo(estado, cordNova,tree);
                    else if (posicao==8) tree -> ID = inicializa_ramo(estado, cordNova,tree);
                }
            }
    return tree;
}

int ramo_esta_vazio(ARVORE tree){
    int bool=0;
    if (tree->SE == NULL &&
        tree->SM == NULL &&
        tree->SD == NULL &&
        tree->ME == NULL &&
        tree->MD == NULL &&
        tree->IE == NULL &&
        tree->IM == NULL &&
        tree->ID == NULL) bool = 1;

    return bool;
}

ARVORE tsm_Carlo(ARVORE tree,ESTADO *estado,int repeticoes){
    int i,j;
    ARVORE temp = tree;
    double value = -DBL_MAX, bestvalue = -DBL_MAX;
    tree->passagens++;
    for (i = 0, j = 0; i < 8; i++, temp = tree){
        if (i==0) temp = tree -> SE;
        else if (i==1) temp = tree -> SM;
        else if (i==2) temp = tree -> SD;
        else if (i==3) temp = tree -> ME;
        else if (i==4) temp = tree -> MD;
        else if (i==5) temp = tree -> IE;
        else if (i==6) temp = tree -> IM;
        else if (i==7) temp = tree -> ID;
        if (temp!=NULL){
            if (temp->passagens == 0)
                value = DBL_MAX;
            else value = temp->valor + 2*sqrt(log(tree->passagens)/temp->passagens);

            if(value>bestvalue){
                bestvalue = value;
                j = i;
            }
        }
    }
    if      (j==0) temp = tree -> SE;
    else if (j==1) temp = tree -> SM;
    else if (j==2) temp = tree -> SD;
    else if (j==3) temp = tree -> ME;
    else if (j==4) temp = tree -> MD;
    else if (j==5) temp = tree -> IE;
    else if (j==6) temp = tree -> IM;
    else if (j==7) temp = tree -> ID;
    if (temp->passagens > 0){
        if(ramo_esta_vazio(temp)){
            temp = cria_folhas(estado, temp);
            if (ramo_esta_vazio(temp)) {
                temp->passagens++;
                temp->valor *= 2;
            }
            else temp = tsm_Carlo(temp,estado,-1);
        }
        else temp = tsm_Carlo(temp, estado, -1);
    }
    else {
        temp->valor = rollout (temp->jogadas_passadas, estado);
    }
    if(repeticoes != -1)
        valor_jogada(tree);

    if(repeticoes != 1 && repeticoes != -1)
        tree = tsm_Carlo(tree, estado, --repeticoes);

    return tree;
}
