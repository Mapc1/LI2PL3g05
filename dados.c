#include <stdio.h>
#include "dados.h"

////////////////////////////INICIALIZAÇÃO DO JOGO/////////////////////////////
void inicializa_jogadas(ESTADO *estado){
    int i;
    for( i = 0; i < 32; i++){
        estado->jogadas[i].jogador1 = (COORDENADA) { .coluna = (-1), .linha = (-1) };
        estado->jogadas[i].jogador2 = (COORDENADA) { .coluna = (-1), .linha = (-1) };
    }
}

void inicializa_tabela(ESTADO *estado){
    int i,j;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++) {
            if(i == 0 && j == 7)
                estado->tabela[i][j] = DOIS;
            else if(i == 7 && j == 0)
                estado->tabela[i][j] = UM;
            else if(i == 3 && j == 4)
                estado->tabela[i][j] = BRANCA;
            else
                estado->tabela[i][j] = VAZIA;
        }
}

ESTADO *inicializar_estado(ESTADO *estado) {
    estado->jogador_atual = 1;
    estado->num_jogadas = 0;
    estado->ultima_jogada = (COORDENADA) { .coluna = 4, .linha = 3 };
    estado->undo = (-1);

    inicializa_jogadas(estado);
    inicializa_tabela(estado);
    return estado;
}
///////////////////////////////////////////////////////////////7///////////////////

////////////////////////////OBTENÇÃO DE VALORES////////////////////////////////////
int obter_jogador_atual(ESTADO *estado){
    return estado->jogador_atual;
}

CASA obter_estado_casa(ESTADO *estado, COORDENADA c) {
    return (estado->tabela[c.linha][c.coluna]);
}

int obter_numero_jogadas(ESTADO *estado){
    return (estado->num_jogadas);
}

JOGADA obter_movs (ESTADO *estado, int i){
    JOGADA j = (JOGADA) { .jogador1 = estado->jogadas[i].jogador1, .jogador2 = estado->jogadas[i].jogador2};
    return j;
}
///////////////////////////////////////////////////////////////////////////////////

////////////////////////////ALTERAÇÃO DO ESTADO///////////////////////////////////
void muda_jogador (ESTADO *estado){
    if(estado->jogador_atual == 1)
        estado->jogador_atual = 2;
    else
        estado->jogador_atual = 1;
}

void aumentar_numero_jogadas(ESTADO *estado){
    estado->num_jogadas++;
}

int aux_jogar(ESTADO *estado, COORDENADA c, CASA casa1, CASA casa2){
    estado->tabela[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = casa2;
    estado->tabela[c.linha][c.coluna] = casa1;
    estado->ultima_jogada = c;
    return 1;
}

void insere_jogada (ESTADO *estado, COORDENADA j){
    int i = obter_numero_jogadas(estado);
    if(estado->jogador_atual == 1)
        estado->jogadas[i].jogador1 = j;
    else
        estado->jogadas[i].jogador2 = j;
}
///////////////////////////////////////////////////////////////////////////////////

//////////////////////////LEITURA E ESCRITA DE FICHEIROS///////////////////////////
//////ESCRITA//////
void escreve_tabuleiro (ESTADO *estado, FILE *f){
    int i,o;
    for(i = 0; i < 8; i++){
        for(o = 0; o < 8; o++){
            fputc(estado->tabela[i][o], f);
        }
        fputc('\n', f);
    }
}

void escreve_movs (ESTADO *estado, FILE *f){
    int i, colj1, linj1, colj2, linj2;
    for(i = 0; i < estado->num_jogadas; i++) {
        colj1 = estado->jogadas[i].jogador1.coluna + 'a';
        linj1 = estado->jogadas[i].jogador1.linha + 1;

        colj2 = estado->jogadas[i].jogador2.coluna + 'a';
        linj2 = estado->jogadas[i].jogador2.linha + 1;

        fprintf(f, i < 10 ? "0%d: %c%d %c%d\n" : "%d: %c%d %c%d\n", i + 1, colj1, linj1, colj2, linj2);
    }
    if(estado->jogador_atual == 2) {
        colj1 = estado->jogadas[i].jogador1.coluna + 'a';
        linj1 = estado->jogadas[i].jogador1.linha + 1;

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

//////LEITURA//////
COORDENADA str_2_coordenada (char *s){
    COORDENADA c;
    c.coluna = *s - 'A';
    c.linha = *(s + 1) -'1';
    return c;
}

void ler_movs (ESTADO *estado, FILE *f){
    char s1[2], s2[2];
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
        estado->jogador_atual = 2;
    }
    else {
        estado->num_jogadas = i - 1;
        estado->jogador_atual = 1;
    }
}

void ler_tabuleiro (ESTADO *estado, FILE *f){
    char c,i,o;
    for(i = 0; i < 8; i++)
        for(o = 0; o < 8;){
            c = fgetc(f);

            if(c == '*'){
                estado->ultima_jogada = (COORDENADA) { .coluna = o, .linha = i };
                estado->tabela[i][o] = c;
                o++;
            }

            else if(c != '\n') {
                estado->tabela[i][o] = c;
                o++;
            }
        }
}

ESTADO *ler_ficheiro (ESTADO *estado, char *s){
    FILE *f;

    f = fopen(s, "r");
    ler_tabuleiro(estado, f);

    fgetc(f);
    fgetc(f);

    ler_movs(estado, f);
    fclose(f);

    return estado;
}

void reverte_estado (ESTADO *estado){
    int i;

    for(i = estado->num_jogadas; i > estado->undo - 1; i--){
        if (estado->jogadas[i].jogador2.linha != (-1))
            aux_jogar(estado, estado->jogadas[i].jogador2, BRANCA, VAZIA);

        aux_jogar(estado, estado->jogadas[i].jogador1, BRANCA, VAZIA);

        estado->jogadas[i].jogador1 = (COORDENADA) { .coluna = (-1), .linha = (-1) };
        estado->jogadas[i].jogador2 = (COORDENADA) { .coluna = (-1), .linha = (-1) };
    }

    aux_jogar(estado, estado->jogadas[i].jogador2, BRANCA, VAZIA);
    estado->ultima_jogada = estado->jogadas[i].jogador2;
    estado->num_jogadas = estado->undo;
    estado->jogador_atual = 1;
    estado->undo = (-1);
}