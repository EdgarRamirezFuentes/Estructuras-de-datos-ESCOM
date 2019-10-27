#ifndef __PILA_H__
#define __PILA_H__

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *siguiente;
};

struct Pila {
    int total;
    struct Nodo *datos;
};

void
push(struct Pila *pila, int dato);

int 
peek(struct Pila *pila);

int 
pop(struct Pila *pila);

struct Nodo* 
AgregarNodoAlInicio(struct Nodo *nodo, int dato);

struct Nodo*
EliminarNodoAlInicio(struct Nodo *nodo);

void MostrarPila(struct Pila *pila);

#endif
