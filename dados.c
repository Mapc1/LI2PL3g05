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
            if(i == 0 && j == 7)
                estado->tabela[i][j] = UM;
            else if(i == 7 && j == 0)
                estado->tabela[i][j] = DOIS;
            else if(i == 4 && j == 4)
                estado->tabela[i][j] = BRANCA;
            else
                estado->tabela[i][j] = VAZIA;
        }
}

ESTADO *inicializar_estado() {
    ESTADO *estado = (ESTADO *) malloc(sizeof(ESTADO));

    estado->jogador_atual = 1;
    estado->num_jogadas = 0;
    estado->ultima_jogada = (COORDENADA) { .coluna = 4, .linha = 4 };

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

void insere_jogada (ESTADO *estado, COORDENADA j){
    int i = obter_numero_jogadas(estado);
    if(estado->jogador_atual == 1)
        estado->jogadas[i].jogador1 = j;
    else
        estado->jogadas[i].jogador2 = j;
}

void escreve_ficheiro (ESTADO *estado, char *s){
    FILE *f = fopen(s, "w");
    int i,o,j;
    char linhamovs[128];
        for(i = 0; i < 8; i++){
            for(o = 0; o < 8; o++){
                fputc(estado->tabela[i][o], f);
            }
            fputc('\n', f);
        }
        for(i = 0,o=0; i<32; i++) {
            for (j = 1; j <= 2; j++,o=o+2) {
                COORDENADA c = obter_movs(estado, i, j);
                if (c.linha != (-1)){
                    linhamovs[o] = (c.coluna +'0');
                    linhamovs[o+1] = (c.linha+'0');
                }
                else {
                    linhamovs[o] = '9';
                    linhamovs[o+1] = '9';
                }
            }
        }
        for(i=0;i<128;i++) (fputc(linhamovs[i], f));
    fclose(f);
}

ESTADO *ler_ficheiro (ESTADO *estado, char *s){
    FILE *f;
    char c,l;
    int i,o,j;
    f = fopen(s, "r");
    estado->num_jogadas=0;
    for(i = 0; i < 8; i++){
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
    fgetc(f);
    for(i=0;i<32;i++){
        for (j = 1; j <= 2; j++){
            c = fgetc(f);
            l = fgetc(f);
            if(c== ' ' && j==1 ) {
                estado->jogadas[i].jogador1 = (COORDENADA) { .coluna = (-1), .linha = (-1)};
            }
            else if(c==' '){
                estado->jogadas[i].jogador2 = (COORDENADA) { .coluna = (-1), .linha = (-1)};
            }
            else if(j==1){
               estado->jogadas[i].jogador1 = (COORDENADA) { .coluna = atoi(c), .linha = atoi(l)};
            }
            else {
               estado->jogadas[i].jogador2 = (COORDENADA) { .coluna = atoi(c), .linha = atoi(l)};
               aumentar_numero_jogadas;
           }
        }
    }
    fclose(f);
    return estado;
}

COORDENADA obter_movs (ESTADO *estado, int i, int j){
    if(j == 1)
        return estado->jogadas[i].jogador1;
    else
        return estado->jogadas[i].jogador2;
}

/*
//Guarda os movimentos executados
void gr_movs(char *s){
    char *l;
    if(strcmp(s, "movs") == 0){ // se o comando for movs, encerra a gravação e chama a impr_movs, caso não seja nem o movs nem uma coordenada ignora
        if
    }
}

//Imprime os movimentos anteriores
void impr_movs(){
    //...
    for(int i=1;i<=l;i++){
        if (l<10) printf("0%d:%c",i,s); // imprime as sucessivas linhas dos movs, caso a linha seja menor que 10 adiciona um 0 antes para ter 2 algarismos
        else printf("%d:%c",l,s);
    }
}
 */