#include "logica.h"
#include "dados.h"

int compara_comando (char *s){
    int comando;

    if (strcmp(s, "q") == 0) comando = 1;
    else if (strcmp(s, "gr") == 0) comando = 2;
    else if (strcmp(s, "ler") == 0) comando = 3;
    else if (strcmp(s, "movs") == 0) comando = 4;

    return comando;
}

int comando_gr (ESTADO *estado, char *s){
    int bool = 0;

    if (s != NULL) {
        escreve_ficheiro(estado, s);
        printf("\nEstado do jogo guardado em %s\n", s);
        bool = 1;
    }

    return bool;
}

int comando_ler (ESTADO *estado, char *s){
    int bool = 0;

    if(s != NULL) {
        ler_ficheiro(estado, s);
        printf("\n%s importado.\n", s);
        mostrar_tabuleiro(estado);
        bool = 1;
    }

    return bool;
}



int jogada_impossivel (ESTADO *estado){
    int jogador, bool = 0, counter = 0;
    COORDENADA a = estado->ultima_jogada;

    for(int i = a.linha - 1; i <= a.linha + 1; i++)
        for(int o = a.coluna - 1; o <=a.coluna + 1; o++)
            if(
               estado->tabela[i][o] == PRETA ||
               i == 8 || o == 8 ||
               i == (-1) || o == (-1)
               )
                counter++;

    if(counter == 8) {
        jogador = obter_jogador_atual(estado);
        if (jogador == 1)
            printf("O jogador 2 ganhou por empancamento.\nParabéns!!!\n");
        if (jogador == 2)
            printf("O jogador 1 ganhou por empancamento.\nParabéns!!!\n");
        bool = 1;
    }

    return bool;
}

int valida_jogada (ESTADO *estado, COORDENADA c){
    int bool = 1;
    COORDENADA a = estado->ultima_jogada;
    if(
       abs (a.linha - c.linha) > 1 || abs (a.coluna - c.coluna) > 1 ||
       obter_estado_casa(estado, c) != VAZIA
       )
        bool = 0;
    return bool;
}

int jogar(ESTADO *estado, COORDENADA c){
    int bool = 0;
    if(valida_jogada(estado, c) == 1) {
        bool = aux_jogar(estado, c);
        insere_jogada(estado, c);
        if(obter_jogador_atual(estado) == 2)
            aumentar_numero_jogadas(estado);
        muda_jogador(estado);
    }
    return bool;
}

int fim_do_jogo (ESTADO *estado, COORDENADA c){
    int bool = 0;
    if (obter_estado_casa(estado, c) == UM){
        printf ("O jogador 1 ganhou!!!\n");
        bool = 1;
        }
    if (obter_estado_casa(estado, c) == DOIS){
        printf ("O jogador 2 ganhou!!!\n");
        bool = 1;
        }
    return bool;
}