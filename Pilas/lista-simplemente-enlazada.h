#ifndef __LISTASIMPLEMENTEENLAZADA_H__
#define __LISTASIMPLEMENTEENLAZADA_H__

#include <stdio.h>
#include <stdlib.h>

struct NodoLista {
	int dato;
	struct NodoLista *siguiente;
};

struct NodoLista* AgregarNodoAlInicio(struct NodoLista *, int);
struct NodoLista* EliminarNodoAlInicio(struct NodoLista *);

#endif
