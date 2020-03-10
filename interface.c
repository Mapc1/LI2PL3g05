#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"


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
    char col;
    for (i = -1; i < 8; i++){
        if (i==(-1)){
                printf("   ");
                for (j=0,col='A';j<8;j++,col++) printf ("%c ",col);
        }
        else {
            printf("%d  ",(i+1));
            for (j = 0; j < 8; j++) {
                switch (e->tabela[i][j]){
                case VAZIA: printf(". ");break;
                case BRANCA: printf("B ");break;
                case PRETA: printf("P ");break;
                }
            }
        }
        printf("\n");
    }
}
