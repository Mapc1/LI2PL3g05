#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <string.h>

//será possível dividir esta função em outras mais pequenas?
int comando(char *linha, ESTADO *estado){
    char *s;
    int bool = 0;
    JOGADA jogada;
    COORDENADA c1, c2;
    s = strtok(linha, " \n");
//    gr_movs(s); ------> dados.c (rascunhos)
    if(strcmp(s, "q") == 0)  exit(0);
    else if(strcmp(s, "gr") == 0) {
        s = strtok(NULL, "\n");
        if (s != NULL) {
            escreve_ficheiro(estado, s);
            printf("\nEstado do jogo guardado em %s\n", s);
            bool = 1;
        }
        else
            printf("Ficheiro Invalido\n");
    }
    else if(strcmp(s, "ler") == 0) {
        s = strtok(NULL, "\n");
        if(s != NULL) {
            ler_ficheiro(estado, s);
            printf("\n%s importado.\n", s);
            mostrar_tabuleiro(estado);
            bool = 1;
        }
        else
            printf("Ficheiro invalido\n");
    }
    else if(strcmp(s, "movs") == 0){
        int i;
        for(i = 0; i < obter_numero_jogadas(estado); i++) {
            jogada = obter_movs(estado, i);

            c1 = jogada.jogador1;
            c2 = jogada.jogador2;

            printf("%d: %c%d %c%d\n", i + 1, c1.coluna + 'A', c1.linha + 1, c2.coluna + 'A', c2.linha + 1);
        }
        if(estado->jogador_atual == 2){
            jogada = obter_movs(estado, i);
            c1 = jogada.jogador1;
            printf("%d: %c%d\n",i + 1, c1.coluna + 'A', c1.linha + 1);
        }
    }
    return bool;
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    while (1){
        if (jogada_impossivel(e)) {
            return 0;
        }
        printf("Insira a posicao da sua jogada.\n");

        if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
        int w;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            prompt(e,*col,*lin);
            jogar(e, coord);
            mostrar_tabuleiro(e);
            if (fim_do_jogo(e, coord)) {
            return 0;
            }
        }
        else{
        w = comando(linha, e);
        printf("%d", w);
        }
    }
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
                    c = (COORDENADA) { .coluna = j, .linha = i };
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
    if (jogador == 1) {
            printf ("#Jogada numero %d, PLAYER 1 jogou em %c%c\n",njogada,col,lin);
    }
    else{
        printf ("#Jogada numero %d, PLAYER 2 jogou em %c%c\n",njogada,col,lin);
    }
}
