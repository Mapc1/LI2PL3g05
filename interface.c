#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <string.h>

//Verifica se o input e um comando
void comando(char linha[BUF_SIZE], ESTADO *estado){
    if(strcmp(linha,"Q\n") == 0)  exit(0);

    if(strcmp(linha,"GR\n") == 0) {
        escreve_ficheiro(estado);
        printf("\nEstado do jogo guardado em 'Rastros.txt'\n\n");
    }

    if(strcmp(linha, "LER\n") == 0) {
        ler_ficheiro();
        printf("\nRastros.txt importado.\n\n");
    }
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    printf("Insira a posicao da sua jogada.\n");

    //Recebe o input e verifica se e uma jogada
    if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        prompt(e,*col,*lin);
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }

    comando(linha, e);
    interpretador(e);
return 1;
}

void mostrar_tabuleiro(ESTADO *e) {
    int i,j;
    COORDENADA c;
    for (i = -1; i < 8; i++){
        if (i==(-1)){
                printf("   ");
                for (j = 0; j < 8; j++)
                    printf ("%c ",(j + 'A'));
                putchar('\n');
        }
        else {
            printf("%d  ",(i+1));
            for (j = 0; j < 8; j++) {
                    c = (COORDENADA){.coluna = j, .linha = i};
                    printf("%c ",(obter_estado_casa(e,c)));
            }
            putchar('\n');
        }
    }
    printf("\n");
}


void prompt(ESTADO *e,char *col,char *lin){
    int njogada,jogador;
    njogada = obter_numero_jogadas(e);
    jogador = obter_jogador_atual(e);
    printf ("#Jogada numero %d, PLAYER %d jogou em %c%c\n",njogada,jogador,col,lin);
}
