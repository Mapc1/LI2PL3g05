#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "logica.h"

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Erro!!!\nDeve inserir dois ficheiros\n");
        exit(1);
    }

    ESTADO *estado = malloc(sizeof(ESTADO));
    inicializa_jogadas(estado);

    ler_ficheiro(estado, argv[1]);
    estado = joga(estado);
    escreve_ficheiro(estado, argv[2]);

    return 0;
}
