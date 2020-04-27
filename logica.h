#ifndef BOT_LOGICA_H
#define BOT_LOGICA_H
#include "tree.h"

double quem_ganha (ESTADO *estado, ARVORE tree);

ESTADO *joga(ESTADO *estado, ARVORE tree);

double valor_jogada(ARVORE tree);

ARVORE valor_jogada_recursiva(ARVORE tree);
#endif //BOT_LOGICA_H
