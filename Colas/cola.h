#ifndef __COLA_H__
#define __COLA_H_

#include <stdio.h>
#include <stdlib.h>

int valorPeek;
int valorDequeue;

struct Cola {
    int total;
    struct Nodo *datos;
};

void enqueue(struct Cola *, int);

int dequeue(struct Cola *);

int peek(struct Cola *);

void MostrarCola(struct Cola *);

int isEmpty(struct Cola *);

#endif
