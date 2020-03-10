#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "interface.h"


int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
return 1;
}


void mostrar_tabuleiro(ESTADO *e) {
    int i,j;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++) {
            printf("%c",e->tabela[i][j]);
        }
        printf("\n");
    }
}