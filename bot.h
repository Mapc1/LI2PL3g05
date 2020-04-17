/**
@file bot.h
Definição do bot
*/

#ifndef RASTROS_BOT_H
#define RASTROS_BOT_H
#include "bot.h"

int vai_ganhar (ESTADO *estado, COORDENADA c);
double calcula_distancia (COORDENADA c,COORDENADA d);
double valor_da_peca (ESTADO *estado, COORDENADA c);
int comando_jog(ESTADO *estado);

#endif //RASTROS_BOT_H
