#ifndef __LISTA_H__
#define __LISTA_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no_int NoInt;

typedef struct lista_int;

ListaInt * 
lista_novo(void); 

void
lista_adiciona(ListaInt *lista, int posicao, int item);

int
lista_obtem(ListaInt *lista, int posicao);

void 
lista_adiciona_fim(Lista *lista, int item);

void 
lista_Libera(ListaInt *lista);



NoInt *
no_int_novo(int item, NoInt *proximo);

NoInt *
no_int_adiciona_inicio(NoInt *cabeca, int item);

NoInt *
no_int_adiciona_fim(NoInt *cabeca, int item);

NoInt *
no_int_adiciona(NoInt *cabeca, int posicao, int item); 

NoInt *
no_int_remove_inicio(NoInt *cabeca);

size_t
lista_no_tamanho(ListaNo *cabeca);

NoInt*
no_int_obtem(NoInt *cabeca, int posicao);

NoInt*
no_int_inverte(NoInt *cabeca);

NoInt*
no_int_filtro(NoInt* cabeca, int valor_filtrado);

