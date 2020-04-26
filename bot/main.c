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
    ARVORE tree = inicializa_raiz(obter_ultima_jogada(estado));
    estado = joga(estado, tree);
    escreve_ficheiro(estado, argv[2]);

    return 0;
}
