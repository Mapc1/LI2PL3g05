#ifndef BOT_LOGICA_H
#define BOT_LOGICA_H
#include "tree.h"
#include "dados.h"

double quem_ganha (ESTADO *estado, LISTA jogadas_passadas);

ESTADO *escolhe_coord(ESTADO *estado, ARVORE tree);

double valor_jogada(ARVORE tree);

ARVORE valor_jogada_recursiva(ARVORE tree);
#endif //BOT_LOGICA_H
