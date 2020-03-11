#include "logica.h"
#include "dados.h"




//Substitui a peça BRANCA com uma peça PRETA
void substitui_peca_branca(ESTADO *estado){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(estado->tabela[i][j] == BRANCA){
                estado->tabela[i][j] = PRETA;
                return;
            }
}


int jogar(ESTADO *estado, COORDENADA c){
    int bool = 0;
    if(estado->tabela[c.linha][c.coluna] == VAZIA &&
       c.linha >= 0   &&
       c.linha <= 7   &&
       c.coluna >= 0  &&
       c.coluna <= 7){
        substitui_peca_branca(estado);
        estado->tabela[c.linha][c.coluna] = BRANCA;
        bool = 1;
    }
    printf("jogar %d %d\n", c.coluna, c.linha);
    return bool;
}
