#include <stdio.h>
#include "dados.h"
#include <math.h>
#include "bot.h"
#include "listas.h"
#include "logica.h"

double calcula_distancia (COORDENADA c,COORDENADA d){
    double distancia = sqrt( pow((c.linha-d.linha),2) + pow((c.coluna-d.coluna),2));
    return distancia;
}

double valor_da_peca (ESTADO *estado, COORDENADA c){
    double valor=0;
    if (end_game (estado,c)) printf ("Vai ganhar\n");
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
int comando_jog (ESTADO *estado){
    int i,o,tam=0;
    double melhorValor,valorAtual;
    COORDENADA c = estado -> ultima_jogada,melhorJogada,jogadaAtual,jogadas[8];

    for(i = c.linha - 1; i <= c.linha + 1; i++)
        for(o = c.coluna - 1; o <=c.coluna + 1; o++)
            if((estado->tabela[i][o] == VAZIA ||
                estado->tabela[i][o] == UM ||
                estado->tabela[i][o] == DOIS) 
                && i<=7 && i>=0 && o<=7 && o>=0){
                jogadas[tam] = (COORDENADA) {.coluna = o,.linha = i};
                tam++;
            }
    melhorJogada = jogadas[0];
    melhorValor = valor_da_peca (estado,melhorJogada);
    for(i=1;i<tam;i++){
        printf("Melhor valor %f\n",melhorValor);
        jogadaAtual = jogadas[i];
        valorAtual = valor_da_peca (estado,jogadaAtual);
        if (valorAtual<melhorValor){
            melhorValor = valorAtual;
            melhorJogada = jogadaAtual;
        }
    }
    jogar(estado,melhorJogada);
    mostrar_tabuleiro(estado);
    return end_game(estado,melhorJogada);
}


