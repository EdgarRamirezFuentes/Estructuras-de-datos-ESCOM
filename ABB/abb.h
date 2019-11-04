#ifndef __ABB_H__
#define __ABB_H__

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *izquierda;
	struct Nodo *derecha;
};

struct Nodo* AgregarDato(struct Nodo*, int);
struct Nodo* BuscarDato(struct Nodo*, int);
struct Nodo* BuscarPadre(struct Nodo*,struct Nodo*);
struct Nodo* EliminarDato(struct Nodo*, int);
int EsHoja(struct Nodo*);
int NoTieneHijoIzquierdo(struct Nodo*);
int TieneSoloHijoIzquierdo(struct Nodo*);
struct Nodo* BuscarElMasPequenioDeLosGrandes(struct Nodo*);
void mostrar(struct Nodo*);
#endif
