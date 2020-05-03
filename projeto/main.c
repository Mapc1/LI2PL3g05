#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"


int main(){
    ESTADO *estado = (ESTADO *) malloc(sizeof(ESTADO));;
    inicializar_estado(estado);
    mostrar_tabuleiro(estado);
    interpretador(estado);
return 0;
}