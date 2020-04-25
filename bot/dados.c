#include <stdio.h>
#include "dados.h"

ESTADO *inicializa_jogadas(ESTADO *estado){
    int i;
    for( i = 0; i < 32; i++){
        estado->jogadas[i].jogador1 = (COORDENADA) { .coluna = (-1), .linha = (-1) };
        estado->jogadas[i].jogador2 = (COORDENADA) { .coluna = (-1), .linha = (-1) };
    }
    return estado;
}

COORDENADA str_2_coordenada (char *s){
    COORDENADA c;
    c.coluna = *s - 'a';
    c.linha = '8' - *(s + 1);
    return c;
}

void ler_movs (ESTADO *estado, FILE *f){
    char s1[3], s2[3];
    int i, num = 0, jog_incompleta = 0;
    for(i = 0; num != EOF; i++){
        num = fscanf(f,"%*d: %s %s\n", s1, s2);
        if(num == 2){
            estado->jogadas[i].jogador1 = str_2_coordenada(s1);
            estado->jogadas[i].jogador2 = str_2_coordenada(s2);
        }
        else if(num == 1) {
            estado->jogadas[i].jogador1 = str_2_coordenada(s1);
            jog_incompleta = 1;
        }
    }
    if(jog_incompleta == 1) {
        estado->num_jogadas = i - 2;
        estado->bot = 2;
    }
    else {
        estado->num_jogadas = i - 1;
        estado->bot = 1;
    }
}

void ler_tabuleiro (ESTADO *estado, FILE *f){
    char i,o;
    int c;
    for(i = 0; i < 8; i++)
        for(o = 0; o < 8;){
            c = fgetc(f);

            if (c == '*'){
                estado->tabuleiro[i][o] = c;
                estado->ultima_jogada = (COORDENADA) { .coluna = o, .linha = i };
                o++;
            }
            if(c != '\n') {
                estado->tabuleiro[i][o] = c;
                o++;
            }
        }
}

ESTADO *ler_ficheiro (ESTADO *estado, char *nome){
    FILE *f;

    f = fopen(nome, "r");
    ler_tabuleiro(estado, f);

    fgetc(f);
    fgetc(f);

    ler_movs(estado, f);
    fclose(f);

    return estado;
}

void escreve_tabuleiro (ESTADO *estado, FILE *f){
    int i,o;
    for(i = 0; i < 8; i++){
        for(o = 0; o < 8; o++){
            fputc(estado->tabuleiro[i][o], f);
        }
        fputc('\n', f);
    }
}

void escreve_movs (ESTADO *estado, FILE *f){
    int i, colj1, linj1, colj2, linj2;
    for(i = 0; i < estado->num_jogadas; i++) {
        colj1 = estado->jogadas[i].jogador1.coluna + 'a';
        linj1 = 8 - estado->jogadas[i].jogador1.linha;

        colj2 = estado->jogadas[i].jogador2.coluna + 'a';
        linj2 = 8 - estado->jogadas[i].jogador2.linha;

        fprintf(f, i < 10 ? "0%d: %c%d %c%d\n" : "%d: %c%d %c%d\n", i + 1, colj1, linj1, colj2, linj2);
    }
    if(estado->bot == 1) {
        colj1 = estado->jogadas[i].jogador1.coluna + 'a';
        linj1 = 8 - estado->jogadas[i].jogador1.linha;

        fprintf(f, i < 10 ? "0%d: %c%d\n" : "%d: %c%d \n", i + 1, colj1, linj1);
    }
}

void escreve_ficheiro (ESTADO *estado, char *s){
    FILE *f = fopen(s, "w");
    escreve_tabuleiro(estado, f);
    fputc('\n', f);
    escreve_movs(estado, f);
    fclose(f);
}

int obter_bot (ESTADO *estado){
    return estado->bot;
}

COORDENADA obter_ultima_jogada (ESTADO *estado){
    return estado->ultima_jogada;
}

CASA obter_casa (ESTADO *estado, COORDENADA c){
    return estado->tabuleiro[c.linha][c.coluna];
}