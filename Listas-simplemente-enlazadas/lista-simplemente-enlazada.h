/**
 \file main.c
 \author Edgar Alejandro Ramírez Fuentes
 \version 1.1
 \last update date 26 / 10 / 2019
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una lista simplemente ligada:
 + AgregarNuevoNodo
 + AgregarNodoAlInicio
 + AgregarNodoAlFinal
 + MostrarLista
 + EliminarNodo
 + EliminarNodoAlFinal
 + EliminarNodoAlInicio
*/

#ifndef __LISTASIMPLEMENTEENLAZADA_H__
#define __LISTASIMPLEMENTEENLAZADA_H__

#include <stdio.h>
#include <stdlib.h>
struct Nodo {
	int dato;
	struct Nodo *siguiente;
};

void
MostrarLista(struct Nodo *);

// Agrega un nuevo nodo en la lista.
// El usuario decide si agregarla al inicio o al final de la lista. 
struct Nodo* 
AgregarNuevoNodo(struct Nodo *, int , int );

struct Nodo*
AgregarNodoAlFinal(struct Nodo *, int );

struct Nodo* 
AgregarNodoAlInicio(struct Nodo *, int );

// Elimina un nodo en la lista.
// El usuario decide si eliminarlo al inicio o al final de la lista. 
struct Nodo*
EliminarNodo(struct Nodo *, int );

struct Nodo*
EliminarNodoAlInicio(struct Nodo *);

struct Nodo*
EliminarNodoAlFinal(struct Nodo *);

#endif
