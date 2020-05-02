/**
@file listas.h
Definição das listas e das funções que as alteram
*/

#ifndef RASTROS_LISTAS_H
#define RASTROS_LISTAS_H
#include "listas.h"
#include "dados.h"

/**
\brief Tipo de dados para as listas
*/

/**
\brief Insere uma nova cabeça na lista
@param x nova cabeça da lista
@param xs lista
*/
LISTA insere_cabeca (COORDENADA x, LISTA xs);


/**
\brief Verifica se a lista está vazia
@param L Lista
Devolve verdadeiro (1) se estiver vazia
*/
int lista_esta_vazia(LISTA L);

/**
\brief Replica uma lista
@param l Lista a replicar
Dado uma lista, cria uma igual à anterior
*/
LISTA cloneL (LISTA l);

/**
\brief Verifica se as coordenadas são iguais
@param x Coordenada
@param y Coordenada
*/
int coordenadas_iguais (COORDENADA x,COORDENADA y);

/**
\brief Verifica se existe existe a coordenada x na lista l
@param l Lista de coordenadas
@param x Coordenada
*/
int nao_repete(LISTA l,COORDENADA x);

/**
\brief Insere uma nova cabeça na lista
@param x nova cabeça da lista
@param xs lista
*/
LISTA insere_cabeca (COORDENADA x, LISTA xs);

/**
\brief Devolve uma coordenada presente num certo indice
@param lista Lista de coordenadas
@param indice Indice da lista
*/
COORDENADA indice_lista(LISTA lista, int indice);

/**
\brief Calcula o tamanho de uma lista
@param lista Lista de coordenadas
*/
int tamanhodalista (LISTA lista);

/**
\brief Devolve a cabeça de uma lista
@param L Lista
*/
COORDENADA devolve_cabeca(LISTA L);

/**
\brief Liberta a memória ocupada por uma lista
@param L Lista
*/
LISTA freeL(LISTA l);
#endif //RASTROS_LISTAS_H
