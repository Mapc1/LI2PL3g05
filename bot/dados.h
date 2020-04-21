#ifndef BOT_DADOS_H
#define BOT_DADOS_H

typedef enum{
    UM = '1',
    DOIS = '2',
    VAZIA = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

typedef struct{
    int coluna,
    int linha
} COORDENA;

typedef CASA TAB [8][8];
#endif //BOT_DADOS_H
