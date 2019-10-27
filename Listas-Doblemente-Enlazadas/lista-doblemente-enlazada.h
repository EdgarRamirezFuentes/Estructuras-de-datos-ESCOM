#ifndef __LISTADOBLEMENTEENLAZADA_H__
#define __LISTADOBLEMENTEENLAZADA_H__

#include <stdio.h>
#include <stdlib.h>
struct Nodo {
	int dato;
	struct Nodo *anterior;
	struct Nodo *siguiente;
};

struct Nodo* 
AgregarNuevoNodo(struct Nodo *nodo, int dato, int opcion);

struct Nodo*
AgregarNuevoNodoAlInicio(struct Nodo *nodo, int dato);

struct Nodo*
AgregarNuevoNodoAlFinal(struct Nodo *nodo, int dato);

struct Nodo*
EliminarNodo(struct Nodo *nodo, int opcion);

struct Nodo*
EliminarNodoAlInicio(struct Nodo *nodo);

struct Nodo*
EliminarNodoAlFinal(struct Nodo *nodo);

void
MostrarLista(struct Nodo *nodo);

#endif
