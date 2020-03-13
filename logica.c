#include "logica.h"
#include "dados.h"

int jogar(ESTADO *estado, COORDENADA c){
    int bool;
    bool = aux_jogar(estado,c);
    printf("jogar %d %d\n", c.coluna, c.linha);
    return bool;
}
