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
    COORDENADA c;
    for (i = -1; i < 8; i++){
        //Imprime a linha com as letras
        if (i==(-1)){
                printf("   ");
                for (j = 0; j < 8; j++)
                    printf ("%c ",(j + 'A'));
                putchar('\n');
        }
        else {
            //Imprime os números à esquerda
            printf("%d  ",(i+1));
            //Imprime o tabuleiro
            for (j = 0; j < 8; j++) {
                if(i == 0 && j == 7)
                    printf("1 ");
                else if(i == 7 && j == 0)
                    printf("2 ");
                else{
                    c = (COORDENADA){.coluna = j, .linha = i};
                    printf((obter_estado_casa(e, c) == VAZIA) ? ". " : (obter_estado_casa(e, c) == BRANCA) ? "* " : "# " );
                }
            }
            putchar('\n');
        }
    }
    printf("\n");
}

