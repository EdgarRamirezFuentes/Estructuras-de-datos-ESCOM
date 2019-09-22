/**
 \file main.c
 \author Edgar Alejandro Ramírez Fuentes
 \version 1.1
 \last update date 22 / 09 / 2019
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

#include <stdio.h>
#include <stdlib.h>
struct Nodo {
	int dato;
	struct Nodo *siguiente;
};

void
MostrarLista(struct Nodo *nodo);

// Agrega un nuevo nodo en la lista.
// El usuario decide si agregarla al inicio o al final de la lista. 
struct Nodo* 
AgregarNuevoNodo(struct Nodo *nodo, int dato, int opcion);

struct Nodo*
AgregarNodoAlFinal(struct Nodo *nodo, int dato);

struct Nodo* 
AgregarNodoAlInicio(struct Nodo *nodo, int dato);

// Elimina un nodo en la lista.
// El usuario decide si eliminarlo al inicio o al final de la lista. 
struct Nodo*
EliminarNodo(struct Nodo *nodo, int opcion);

struct Nodo*
EliminarNodoAlInicio(struct Nodo *nodo);

struct Nodo*
EliminarNodoAlFinal(struct Nodo *nodo);

int 
main(void){
	struct Nodo *nodo = NULL;
	nodo = AgregarNuevoNodo(nodo,0,1);
	MostrarLista(nodo);
	nodo = AgregarNuevoNodo(nodo,1,2);
	MostrarLista(nodo);
	nodo = AgregarNuevoNodo(nodo,-1,1);
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo, 1);
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo, 2);
	MostrarLista(nodo);
	return 0;
}

struct Nodo* 
AgregarNuevoNodo(struct Nodo *nodo, int dato, int opcion){ // Complejidad O(1)
	switch(opcion){
		case 1:
			return AgregarNodoAlInicio(nodo, dato);
		break;
		case 2:
			return AgregarNodoAlFinal(nodo, dato);
		break;
	}	
	return nodo;
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
AgregarNodoAlFinal(struct Nodo* nodo, int dato){ // Complejidad O(n)
	struct Nodo* tmp = NULL; // O(1)
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo)); // O(1)
	if(nuevoNodo != NULL){
		nuevoNodo -> dato = dato; // O(1)
		if(nodo == NULL){
			return nuevoNodo; // O(1)
		}
		tmp = nodo; // O(1)
		while(tmp -> siguiente != NULL){ // O(n)
			tmp = tmp -> siguiente; // O(1)
		}
		tmp -> siguiente = nuevoNodo; //O(1)
		return nodo; // O(1)
	}
	return nodo; // O(1)
}
void 
MostrarLista(struct Nodo* nodo){ // Complejidad O(n)
	if(nodo != NULL){
		while(nodo != NULL){ // O(n)
			printf("| %d |", nodo -> dato); // O(1)
			nodo = nodo -> siguiente;
		}
		printf("\n"); // O(1)
	}else{
		printf("No hay datos en la lista"); // O(1)
	}
}

struct Nodo*
EliminarNodo(struct Nodo *nodo, int opcion){ // Complejidad O(1)
	switch(opcion){
		case 1:
			return EliminarNodoAlInicio(nodo);
		break;
		case 2:
			return EliminarNodoAlFinal(nodo);
		break;
	}
	return nodo;
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

struct Nodo*
EliminarNodoAlFinal(struct Nodo *nodo){ // Complejidad O(n)
	struct Nodo *tmp = NULL; // O(1)
	if(nodo != NULL){
		if(nodo -> siguiente == NULL){ // 0(1)
			free(nodo); // O(1)
			return NULL; //O(1)
		}
		tmp = nodo; // O(1)
		while(tmp -> siguiente -> siguiente != NULL){ // O(n)
			tmp = tmp -> siguiente; // O(1)
		}
		free(tmp -> siguiente); // O(1)
		tmp -> siguiente = NULL;
		tmp -> siguiente = NULL;
		return nodo; // O(1)
	}
	return nodo;
}
