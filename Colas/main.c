/**
 \file main.c
 \author Edgar Alejandro Ramírez Fuentes
 \version 1.0
 \last update date 12 / 10 / 2019
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una cola construida con una lista doblemente enlazada para agilizar el tiempo de desencolamiento:
 + enqueue
 + dequeue
 + peek
 + MostrarCola
**/

#include <stdio.h>
#include <stdlib.h>


struct Nodo {
	int dato;
	struct Nodo *anterior;
	struct Nodo *siguiente;
};

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

struct Nodo*
AgregarNuevoNodoAlFinal(struct Nodo *nodo, int dato);

struct Nodo*
EliminarNodoAlInicio(struct Nodo *nodo);

void 
MostrarCola(struct Cola *cola);

int main(void) {
    struct Cola *cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola -> total = 0;
    cola -> datos = NULL;
    enqueue(cola, 5);
    printf("El dato en el tope de la cola es: %d\n", peek(cola));
    MostrarCola(cola);
    enqueue(cola, 10);
    printf("El dato en el tope de la cola es: %d\n", peek(cola));
    MostrarCola(cola);
    dequeue(cola);
    printf("El dato en el tope de la cola es: %d\n", peek(cola));
    MostrarCola(cola);
    return 0;
}

void
enqueue(struct Cola *cola, int dato){
    cola -> datos = AgregarNuevoNodoAlFinal(cola -> datos, dato);
}

void
MostrarCola(struct Cola *cola){
    if(cola -> datos != NULL){
        printf("Cola: ");
        struct Nodo *tmp = cola -> datos;
        do{
            printf("| %d |", tmp -> dato);
            tmp = tmp -> siguiente;
        }while(tmp != cola -> datos);
        printf("\n");
    }
}

void 
dequeue(struct Cola *cola){
    cola -> datos = EliminarNodoAlInicio(cola -> datos);
}

int
peek(struct Cola *cola){
    if(cola -> datos != NULL){
        return cola -> datos -> dato;
    }
    return 0;
}


struct Nodo*
AgregarNuevoNodoAlFinal(struct Nodo *nodo, int dato){
	struct Nodo *nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
	if(nuevoNodo != NULL){
        nuevoNodo -> dato = dato;
        if(nodo != NULL){
            nuevoNodo -> anterior = nodo -> anterior;
            nuevoNodo -> siguiente = nodo;
            nodo -> anterior -> siguiente = nuevoNodo;
            nodo -> anterior = nuevoNodo;
            return nodo;
        }else{
            nuevoNodo -> anterior = nuevoNodo;
            nuevoNodo -> siguiente = nuevoNodo;
            return nuevoNodo;
        }
	}else{
		return nodo;
	}
    return nodo;		
}

struct Nodo*
EliminarNodoAlInicio(struct Nodo *nodo){
	if(nodo -> siguiente != nodo){
		if(nodo -> siguiente -> siguiente == nodo){
			struct Nodo *nuevaDireccion = nodo -> siguiente;
			nuevaDireccion -> siguiente = nuevaDireccion;
			nuevaDireccion -> anterior = nuevaDireccion;
			free(nodo);
			return nuevaDireccion;
			
		}else{
			struct Nodo *direccionNuevoInicioLista = nodo -> siguiente;
			struct Nodo *nodoFinal = nodo -> anterior;
			nodoFinal -> siguiente =  direccionNuevoInicioLista;
			direccionNuevoInicioLista -> anterior  = nodoFinal;
			free(nodo);
			return direccionNuevoInicioLista;
		}
	}else{
		free(nodo);
		return NULL;
	}
}