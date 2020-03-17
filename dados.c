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
    int i = 0;
    for(; i < 32 && estado->jogadas[i].jogador1.coluna != (-1) ; i++);
    return i;
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

int aux_jogar(ESTADO *estado, COORDENADA c){
    substitui_peca_branca(estado);
    estado->tabela[c.linha][c.coluna] = BRANCA;
    return 1;
}

//Procura pela peça BRANCA
COORDENADA obter_casa_atual (ESTADO *estado){
    int i,o;
    COORDENADA c;
    for(i = 0; i < 8; i++){
        for(o = 0; o < 8; o++){
            c = (COORDENADA){ .coluna = o, .linha = i};
            if(obter_estado_casa(estado, c) == BRANCA)
                return c;
        }
    }
}