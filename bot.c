#include <stdio.h>
#include "dados.h"
#include <math.h>
#include "bot.h"
#include "listas.h"
#include "logica.h"

int vai_ganhar (ESTADO *estado, COORDENADA c){
    int bool = 0;
    if (fim_do_jogo (estado, c)) {
        bool = 1;
    }
    if (jogada_impossivel (estado,c)){
        bool = 1;
    }
    return bool;
}

double calcula_distancia (COORDENADA c,COORDENADA d){
    double distancia = sqrt( pow((c.linha-d.linha),2) + pow((c.coluna-d.coluna),2));
    return distancia;
}

double valor_da_peca (ESTADO *estado, COORDENADA c){
    double valor=0;
    if (vai_ganhar (estado,c));
    else{
        int jogador = obter_jogador_atual (estado);
        COORDENADA d;
        if (jogador == 1){
            d = (COORDENADA) { .coluna = (0), .linha = (7) };
        }
        else d = (COORDENADA) { .coluna = (7), .linha = (0) };
        valor = calcula_distancia (c,d);
    }
    return valor;
}

COORDENADA *copiar_coord(COORDENADA c){
    COORDENADA *  copia = (COORDENADA * ) malloc(sizeof(COORDENADA));
    *copia = c;
    return copia;
}

LISTA jogadas_possiveis (ESTADO *estado, COORDENADA c){
    int i,o;
    LISTA jogadas;
    COORDENADA X;

    for(i = c.linha - 1; i <= c.linha + 1; i++)
        for(o = c.coluna - 1; o <=c.coluna + 1; o++)
            if(estado->tabela[i][o] == VAZIA){
                X = (COORDENADA) {.coluna = o,.linha = i};
                jogadas = insere_cabeca (copiar_coord(X), jogadas);
            }
    return jogadas;
}

int comando_jog(ESTADO *estado){
    double melhorValor,valorAtual;
    COORDENADA c = estado -> ultima_jogada,melhorJogada,jogadaAtual;
    LISTA jogadas = jogadas_possiveis (estado,c);
    melhorJogada = *(COORDENADA *) devolve_cabeca(jogadas);
    melhorValor = valor_da_peca (estado,melhorJogada);
    jogadas = remove_cabeca (jogadas);
    while (lista_esta_vazia==0){
        jogadaAtual = * (COORDENADA *) devolve_cabeca(jogadas);
        valorAtual = valor_da_peca (estado,jogadaAtual);
        if (valorAtual<melhorValor){
            melhorValor = valorAtual;
            melhorJogada = jogadaAtual;
        }
        jogadas = remove_cabeca (jogadas);
    }
    jogar(estado,melhorJogada);
    return 1;
}


