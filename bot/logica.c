#include "logica.h"
#include "dados.h"
#include "listas.h"
#include "tree.h"

int quem_joga (ESTADO *estado, Ramo R){
    int counter = 0;

    while(R.jogadas_passadas != NULL)
        counter++;

    if(counter % 2 == 0)
        return estado->jogador;

    else if(estado->jogador == 1)
        return 2;

    else return 1;
}

int ja_percorreu (COORDENADA coord, LISTA jogadas_passadas){
    while(jogadas_passadas->prox != NULL)
        if(coord.linha == jogadas_passadas->v.linha &&
           coord.coluna == jogadas_passadas->v.coluna)
            return 1;
    return 0;
}

int quem_ganha (ESTADO *estado,Ramo R){
    int counter = 0;
    for(int i = -1; i <= 1; i++)
        for(int o = -1; o<= 1; o++){
            COORDENADA coord = (COORDENADA) { R.valor.coluna, R.valor.linha };

            if(obter_casa(estado, coord) == UM) {
                if (estado->jogador == 1) {
                    if (quem_joga(estado, R) == estado->jogador)
                        return 1;
                    else return 0;
                }
                else if (quem_joga(estado, R) == estado->jogador)
                    return 0;
                else return -1;
            }

            else if(obter_casa(estado, coord) == DOIS) {
                if (estado->jogador == 2) {
                    if (quem_joga(estado, R) == estado->jogador)
                        return 1;
                    else return 0;
                }
                else if (quem_joga(estado, R) == estado->jogador)
                    return 0;
                else return -1;
            }
            else if(obter_casa(estado, coord) == PRETA || obter_casa(estado, coord) == BRANCA || ja_percorreu(coord, R.jogadas_passadas))
                counter++;
        }
    if (counter == 8){
        if(quem_joga(estado, R) == estado->jogador)
            return 1;
        else return -1;
    }
}