#include "logica.h"
#include "dados.h"

int jogada_impossivel (ESTADO *estado){
    int bool = 0;
    COORDENADA a = estado->ultima_jogada;
    COORDENADA cima=a, baixo=a, esquerda=a, direita=a;
    cima.linha = (a.linha +1);
    baixo.linha = (a.linha +1);
    esquerda.coluna = (a.coluna -1);
    direita.coluna = (a.coluna +1);
    if ( obter_estado_casa(estado, cima) != VAZIA &&
         obter_estado_casa(estado, baixo) != VAZIA && 
         obter_estado_casa(estado, esquerda) != VAZIA &&
         obter_estado_casa(estado, direita) != VAZIA){
        int jogador;
        jogador = obter_jogador_atual(estado);
        if (jogador == 1) {
            printf ("O jogador 2 ganhou por empancamento");
        }
        else{
            printf ("O jogador 1 ganhou por empancamento");
        }
        bool = 1;
    }
    return bool;
}

int valida_jogada (ESTADO *estado, COORDENADA c){
    int bool = 1;
    COORDENADA a = estado->ultima_jogada;
    if(
       abs (a.linha - c.linha) > 1 || abs (a.coluna - c.coluna) > 1 ||
       obter_estado_casa(estado, c) != VAZIA
       )
        bool = 0;
    return bool;
}

int jogar(ESTADO *estado, COORDENADA c){
    int bool = 0;
    if(valida_jogada(estado, c) == 1) {
        bool = aux_jogar(estado, c);
        muda_jogador(estado);
        aumentar_numero_jogadas(estado);
    }
    return bool;
}

int fim_do_jogo (COORDENADA c){
    int bool = 0;
    if (c.linha == 0 && c.coluna == 7){ 
        printf ("O jogador 1 ganhou!!!\n");
        bool = 1;
        }
    if (c.linha == 7 && c.coluna == 0){ 
        printf ("O jogador 2 ganhou!!!\n");
        bool = 1;
        }
    return bool;
}