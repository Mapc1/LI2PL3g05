#ifndef RASTROS_LOGICA_H
#define RASTROS_LOGICA_H
#include "dados.h"

int jogada_impossivel (ESTADO *estado);
int valida_jogada (ESTADO *estado, COORDENADA c);
int jogar(ESTADO *e, COORDENADA c);
int fim_do_jogo (COORDENADA c);
#endif //RASTROS_LOGICA_H
