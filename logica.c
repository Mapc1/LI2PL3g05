#include "logica.h"
#include "dados.h"

int valida_jogada (ESTADO *estado, COORDENADA c){
    int bool = 1;
    COORDENADA a = obter_casa_atual(estado);
    putchar('\n');
    printf("%d %d\n",a.coluna, a.linha);
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
    }
    printf("jogar %d %d\n", c.coluna, c.linha);
    return bool;
}
