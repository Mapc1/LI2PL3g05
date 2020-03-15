#include "logica.h"
#include "dados.h"

int jogar(ESTADO *estado, COORDENADA c){
    int bool = 0;
    if(estado->tabela[c.linha][c.coluna] == VAZIA &&
       c.linha >= 0   && c.linha <= 7 &&
       c.coluna >= 0  && c.coluna <= 7)
        bool = aux_jogar(estado,c);
    printf("jogar %d %d\n", c.coluna, c.linha);
    return bool;
}
