#ifndef __ABB_H__
#define __ABB_H__

#include <stdio.h>
#include <stdlib.h>
#include "lista-circular-d.h"

struct Arbol {
	int dato;
	struct Arbol *izquierda;
	struct Arbol *derecha;
};

extern struct Arbol *raiz;
extern struct Lista *ColaBFS;

struct Arbol* AgregarDato(struct Arbol*, int);
struct Arbol* BuscarDato(struct Arbol*, int);
struct Arbol* BuscarPadre(struct Arbol*,struct Arbol*);
struct Arbol* EliminarDato(struct Arbol*, int);
int EsHoja(struct Arbol*);
int NoTieneHijoIzquierdo(struct Arbol*);
int TieneSoloHijoIzquierdo(struct Arbol*);
struct Arbol* BuscarElMasPequenioDeLosGrandes(struct Arbol*);
void mostrar(struct Arbol*);
void BFS(struct Arbol *, struct Lista *);
#endif
