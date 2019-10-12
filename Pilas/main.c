/**
 \file main.c
 \author Edgar Alejandro Ramírez Fuentes
 \version 1.0
 \last update date 12 / 10 / 2019
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una pila construida con lista simplemente enlazada:
 + push
 + pop
 + peek
 + MostrarPila
**/

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

int
main(void){
		struct Pila *pila = (struct Pila*)malloc(sizeof(struct Pila));
		pila -> total = 0;
		pila -> datos = NULL;
		push(pila, 5);
		printf("El dato tope es %d\n", peek(pila));
		push(pila,10);
		printf("El dato tope es %d\n", peek(pila));
		MostrarPila(pila);	
}

void MostrarPila(struct Pila *pila){
	struct Pila *tmp = pila;
	if(tmp != NULL){
		printf("Datos en la pila:\n");
		while(tmp -> datos != NULL){
			printf("|\t%d\t|\n", tmp -> datos -> dato);
			tmp -> datos = tmp -> datos -> siguiente;
		}
	}else{
		printf("No hay datos en la pila");
	}
}

int 
peek(struct Pila *pila){
    if(pila -> datos != NULL){
         return pila -> datos -> dato;
    }
	return 0;
}

void
push(struct Pila *pila, int dato){
	pila -> datos = AgregarNodoAlInicio(pila -> datos, dato);
}

struct Nodo*
AgregarNodoAlInicio(struct Nodo *nodo, int dato){ // Complejidad O(1)
	struct Nodo *nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));// O(1);
	if(nuevoNodo != NULL){
		nuevoNodo -> dato = dato; // O(1)
		if(nodo != NULL){
			nuevoNodo -> siguiente = nodo; // O(1);
		}
		return nuevoNodo; // O(1)
	}
	return nodo; // O(1)
}

struct Nodo* 
EliminarNodoAlInicio(struct Nodo *nodo){ // Complejidad O(1)
	struct Nodo *tmp = NULL; // O(1)
	if(nodo != NULL){
		tmp = nodo; //O(1) 
		nodo = nodo -> siguiente; //O(1)
		free(tmp); // O(1)
		return nodo; // O(1)
	}
	return nodo; // O(1)
}