#ifndef __PILA_H__
#define __PILA_H__

#include <stdio.h>
#include <stdlib.h>
#include "lista-simplemente-enlazada.h"

struct Pila {
    int total;
    struct NodoLista *datos;
};

int valorPop;
int valorPeek;

void push(struct Pila *,int);
int pop(struct Pila *);
int peek(struct Pila *);
int isEmpty(struct Pila *);
void MostrarPila(struct Pila *);
#endif
