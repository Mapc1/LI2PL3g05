#include "dados.h"

void inicializa_jogadas(ESTADO *estado){
    //Coloca os valores de jogador1 e jogador2 em todos os índices a (-1)
    for(int i = 0; i < 32; i++){
        estado->jogadas[i].jogador1 = (COORDENADA){.coluna = (-1), .linha = (-1)};
        estado->jogadas[i].jogador2 = (COORDENADA){.coluna = (-1), .linha = (-1)};
    }
}

void inicializa_tabela(ESTADO *estado){
    //Coloca todas as peças a "VAZIA" menos a que está na posiçao 3x4 que e inciada a "BRANCA"
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (i == 3 && j == 4)
                estado->tabela[i][j] = BRANCA;
            else
                estado->tabela[i][j] = VAZIA;
        }
}

ESTADO *inicializar_estado() {
    //Aloca memória para o estado
    ESTADO *estado = (ESTADO *) malloc(sizeof(ESTADO));

    estado->jogador_atual = 1;
    estado->num_jogadas = 0;
    estado->ultima_jogada = (COORDENADA){.coluna = (-1), .linha = (-1)};

    inicializa_jogadas(estado);
    inicializa_tabela(estado);

    return estado;
}

int obter_jogador_atual(ESTADO *estado){
    //Eu não sei se esta função é suposto mudar o jogador atual ou simplesmente devolver o atual
    if(estado->jogador_atual == 1)
        estado->jogador_atual = 2;
    else
        estado->jogador_atual = 1;
    return estado->jogador_atual;
}

CASA obter_estado_casa(ESTADO *estado, COORDENADA c){
    return (estado->tabela[c.linha][c.coluna]);
}

int obter_numero_jogadas(ESTADO *estado){
    int i = 0;
    for(; i < 32 && estado->jogadas[i].jogador1.coluna != (-1) ; i++);
    return i;
}

int aux_jogar(ESTADO *estado, COORDENADA c){
    int bool = 0;
    if(estado->tabela[c.linha][c.coluna] == VAZIA &&
       c.linha >= 0   &&
       c.linha <= 7   &&
       c.coluna >= 0  &&
       c.coluna <= 7){
        substitui_peca_branca(estado);
        estado->tabela[c.linha][c.coluna] = BRANCA;
        bool = 1;
    }
}

//Substitui a peça BRANCA com uma peça PRETA
void substitui_peca_branca(ESTADO *estado){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(estado->tabela[i][j] == BRANCA){
                estado->tabela[i][j] = PRETA;
                return;
            }
}
