#include <stdio.h>
#include "dados.h"

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
            if (i == 3 && j == 4)
                estado->tabela[i][j] = BRANCA;
            else
                estado->tabela[i][j] = VAZIA;
        }
}

ESTADO *inicializar_estado() {
    ESTADO *estado = (ESTADO *) malloc(sizeof(ESTADO));

    estado->jogador_atual = 1;
    estado->num_jogadas = 0;
    estado->ultima_jogada = (COORDENADA) { .coluna = 4, .linha = 3 };

    inicializa_jogadas(estado);
    inicializa_tabela(estado);
    return estado;
}

int obter_jogador_atual(ESTADO *estado){
    return estado->jogador_atual;
}

void muda_jogador (ESTADO *estado){
    if(estado->jogador_atual == 1)
        estado->jogador_atual = 2;
    else
        estado->jogador_atual = 1;
}

CASA obter_estado_casa(ESTADO *estado, COORDENADA c) {
    return (estado->tabela[c.linha][c.coluna]);
}

int obter_numero_jogadas(ESTADO *estado){
    return (estado->num_jogadas);
}

void aumentar_numero_jogadas(ESTADO *estado){
    estado->num_jogadas++;
}

int aux_jogar(ESTADO *estado, COORDENADA c){
    estado->tabela[estado->ultima_jogada.linha][estado->ultima_jogada.coluna] = PRETA;
    estado->tabela[c.linha][c.coluna] = BRANCA;
    estado->ultima_jogada = c;
    return 1;
}

void insere_jogada (ESTADO *estado, COORDENADA j1, COORDENADA j2){
    int i = obter_numero_jogadas(estado);
    estado->jogadas[i] = (JOGADA){.jogador1 = j1, .jogador2 = j2};
}

void escreve_ficheiro (ESTADO *estado, char *s){
    FILE *f = fopen(s, "w");
    int i,o;
        for(i = 0; i < 8; i++){
            for(o = 0; o < 8; o++){
                fputc(estado->tabela[i][o], f);
            }
            fputc('\n', f);
        }

    fclose(f);
}

ESTADO *ler_ficheiro (ESTADO *estado, char *s){
    FILE *f;
    char c;
    int i,o;

    f = fopen(s, "r");

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

    fclose(f);
    return estado;
}