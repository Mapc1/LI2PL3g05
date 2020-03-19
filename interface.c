#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    FILE *f = fopen("Rastros", "w+");
    printf("Insira a posicao da sua jogada.\n");
    if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        prompt(e,*col,*lin);
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    //(Adicionar comandos ao interpretador);
    if (strlen(linha) == 1 && linha[0] == 'Q') return 0; //Comando de 'Quit'; Usar return?
    if (strlen(linha) == 2 && linha[0] == 'g' && linha[1] == 'r') escreve_ficheiro(e); //Comando de gravar tabuleiro
    if (strlen(linha) == 3 && linha[0] == 'l' && linha[1] == 'e' && linha[2] == 'r') le_ficheiro(); // não sei bem o que tem que fazer
    escreve_ficheiro(e);
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
                if(i == 0 && j == 7)
                    printf("1 ");
                else if(i == 7 && j == 0)
                    printf("2 ");
                else{
                    c = (COORDENADA){.coluna = j, .linha = i};
                    printf("%c ",(obter_estado_casa(e,c)));
                }
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
    printf ("#Jogada numero %d, PLAYER %d jogou em %c%c \n",njogada,jogador,col,lin);
}
