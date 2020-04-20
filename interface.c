#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <string.h>
#include "bot.h"

int comando_movs (ESTADO *estado){
    int i;
    JOGADA jogada;
    COORDENADA c1, c2;
    for(i = 0; i < obter_numero_jogadas(estado); i++) {
        jogada = obter_movs(estado, i);

        c1 = jogada.jogador1;
        c2 = jogada.jogador2;

        printf("%d: %c%d %c%d\n", i + 1, c1.coluna + 'A', 8 - c1.linha,c2.coluna + 'A', 8 - c2.linha);
    }

    if(estado->jogador_atual == 2){
        jogada = obter_movs(estado, i);
        c1 = jogada.jogador1;
        printf("%d: %c%d\n",i + 1, c1.coluna + 'A', 8 - c1.linha);
    }
    return 1;
}

int comando(char *linha, ESTADO *estado){
    char *s;
    int bool = 0, comando = 0;

    s = strtok(linha, " \n");
    comando = compara_comando(s);
    s = strtok(NULL, "\n");

    switch(comando){
        case (1): exit(0);
        case (2): bool = comando_gr(estado, s); break;
        case (3): bool = comando_ler(estado, s); break;
        case (4): bool = comando_movs(estado); break;
        case (5): bool = comando_pos(estado, s); break;
        case (6): bool = comando_jog(estado); break;
    }

    if(bool == 0)
        printf("Tente outra vez.\n");
    return bool;
}

int end_game(ESTADO *e, COORDENADA coord){
    if (fim_do_jogo(e, coord)) {
        printf("O jogador %d ganhou!!!\n",fim_do_jogo(e, coord));
        return fim_do_jogo(e, coord);
        }
    printf("%c%d\n",coord.coluna + 'A',8 - coord.linha);
    printf("%d\n",jogada_impossivel(e,coord));
    if (jogada_impossivel(e, coord)) {
        printf("O jogador %d ganhou por empancamento!!!\n",jogada_impossivel(e,coord));
        return jogada_impossivel(e,coord);
        }
    return 0;
}
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    while (2){
        printf("JOGADOR %d: Insira a posicao da sua jogada.\n", obter_jogador_atual(e));

        if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
        int w;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8' -*lin};
            prompt(e,*col,*lin);
            jogar(e, coord);
            mostrar_tabuleiro(e);
            if(end_game(e,coord)) return 2;
        }
        else{
        w = comando(linha, e);
        if (w==2) return 2;
        }
    }
}



void mostrar_tabuleiro(ESTADO *e) {
    int i,j,lin=9;
    COORDENADA c;
    for (i = -1; i < 8; i++,lin--){
        if (i==(-1)){
                printf("   ");
                for (j = 0; j < 8; j++)
                    printf ("%c ",(j + 'A'));
                putchar('\n');
        }
        else {
            printf("%d  ",(lin));
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
