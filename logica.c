#include "logica.h"
#include "dados.h"

int comando_pos (ESTADO *estado, char *arg){
    ESTADO *tmp = (ESTADO *) malloc(sizeof(ESTADO));
    JOGADA jogada;
    int njogada = atoi(arg);

    if(njogada < 0)
        njogada = 0;
    else if(njogada > obter_numero_jogadas(estado) + 1)
        njogada = obter_numero_jogadas(estado) + 1;

    inicializar_estado(tmp);

    for(int i = 0; i < njogada; i++){
        jogada = obter_movs(estado, i);

        jogar(tmp, jogada.jogador1);
        jogar(tmp, jogada.jogador2);
    }

    estado->undo = njogada;

    mostrar_tabuleiro(tmp);
    comando_movs(tmp);

    free(tmp);
    return 1;
}

int compara_comando (char *s){
    int comando = 0;

    if (strcmp(s, "q") == 0) comando = 1;
    else if (strcmp(s, "gr") == 0) comando = 2;
    else if (strcmp(s, "ler") == 0) comando = 3;
    else if (strcmp(s, "movs") == 0) comando = 4;
    else if (strcmp(s, "pos") == 0) comando = 5;

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
    int jogador, bool = 0, counter = 0,i,o;
    COORDENADA a = estado->ultima_jogada;

    for(i = a.linha - 1; i <= a.linha + 1; i++)
        for(o = a.coluna - 1; o <=a.coluna + 1; o++)
            if(
               estado->tabela[i][o] == PRETA ||
               i == 8 || o == 8 ||
               i == (-1) || o == (-1)
               )
                counter++;

    if(counter == 8) {
        jogador = obter_jogador_atual(estado);
        if (jogador == 1)
            printf("O jogador 2 ganhou por empancamento.\nParabens!!!\n");
        if (jogador == 2)
            printf("O jogador 1 ganhou por empancamento.\nParabens!!!\n");
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
    if(estado->undo != (-1)) {
        reverte_estado(estado);
    }

    if(valida_jogada(estado, c) == 1) {
        bool = aux_jogar(estado, c, BRANCA, PRETA);
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
