#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "logica.h"
#include "tree.h"
#include <time.h>

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Erro!!!\nDeve inserir dois ficheiros\n");
        exit(1);
    }

    srand(time(NULL));

    ESTADO *estado = malloc(sizeof(ESTADO));
    inicializa_jogadas(estado);

    ler_ficheiro(estado, argv[1]);
    ARVORE tree = inicializa_raiz(obter_ultima_jogada(estado));
    tree = cria_folhas(estado, tree);
    estado = escolhe_coord(estado, tree);
    escreve_ficheiro(estado, argv[2]);

    return 0;
}
