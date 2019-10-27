#ifndef __COLA_H__
#define __COLA_H_

#include <stdio.h>
#include <stdlib.h>


struct Cola {
    int total;
    struct Nodo *datos;
};

void 
enqueue(struct Cola *cola, int dato);

void 
dequeue(struct Cola *cola);

int 
peek(struct Cola *cola);

void 
MostrarCola(struct Cola *cola);

#endif
