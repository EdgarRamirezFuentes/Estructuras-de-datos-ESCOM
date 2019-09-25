 
/**
 \file main.c
 \author Edgar Alejandro Ramírez Fuentes
 \version 1.1
 \last update date 25 / 09 / 2019
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una lista circular simplemente enlazada:
 + AgregarDato
 + AgregarDatoAlInicio
 + AgregarDatoAlFinal
 + EliminarDato
 + EliminarDatoAlInicio
 + EliminarDatoAlFinal
 + MostrarLista
*/
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *siguiente;
};

// Agrega un dato a la lista al inicio o al final de ella (El usuario elige la posición).
struct Nodo*
AgregarDato(struct Nodo *nodo, int dato, int opcion);

struct Nodo*
AgregarDatoAlInicio(struct Nodo *nodo, int dato);

void 
MostrarLista(struct Nodo *nodo);

struct Nodo*
AgregarDatoAlFinal(struct Nodo *nodo, int opcion);

struct Nodo*
EliminarDato(struct Nodo *nodo, int opcion);

struct Nodo*
EliminarDatoAlInicio(struct Nodo *nodo);

struct Nodo*
EliminarDatoAlFinal(struct Nodo *nodo);

int 
main(void){
	struct Nodo *nodo = NULL;
	MostrarLista(nodo);
	nodo = AgregarDato(nodo, 3, 1);
	MostrarLista(nodo);
	nodo = AgregarDato(nodo, 2, 1);
	MostrarLista(nodo);
	nodo = AgregarDato(nodo, 4, 2);
	MostrarLista(nodo);
	nodo = EliminarDato(nodo, 1);
	MostrarLista(nodo);
	nodo = EliminarDato(nodo, 2);
	MostrarLista(nodo);
	return 0;
}

struct Nodo*
AgregarDato(struct Nodo *nodo, int dato, int opcion){
	switch(opcion){
		case 1:
			return AgregarDatoAlInicio(nodo, dato);
		break;
		case 2: 
			return AgregarDatoAlFinal(nodo, dato);
		break;
	}
	return nodo;
}

struct Nodo*
AgregarDatoAlInicio(struct Nodo *nodo, int dato){
	struct Nodo *nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	if(nuevoNodo != NULL){
		nuevoNodo -> dato = dato;
		if(nodo == NULL){
			nuevoNodo -> siguiente = nuevoNodo;
			return nuevoNodo;
		}
		struct Nodo *tmp = nodo;
		nuevoNodo -> siguiente = nodo;
		while(tmp -> siguiente != nodo){
			tmp = tmp -> siguiente;
		}
		tmp -> siguiente = nuevoNodo;
		return nuevoNodo;
	}
	return nodo;
}	

void 
MostrarLista(struct Nodo *nodo){
	if(nodo != NULL){
		struct Nodo *tmp = nodo;
		do{
			printf("| %d |", tmp -> dato);
			tmp = tmp -> siguiente;
		}while(tmp != nodo);
	}else{
		printf("La lista está vacía");
	}
	printf("\n");
}

struct Nodo*
AgregarDatoAlFinal(struct Nodo *nodo, int dato){
	struct Nodo *nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	if(nuevoNodo != NULL){
		nuevoNodo -> dato = dato;
		if(nodo == NULL){
			nuevoNodo -> siguiente = nuevoNodo;
			return nuevoNodo;
		}
		struct Nodo *tmp = nodo;
		nuevoNodo -> siguiente = nodo;
		while(tmp -> siguiente != nodo){
			tmp = tmp -> siguiente;
		}
		tmp -> siguiente = nuevoNodo;
		return nodo;
	}	
	return nodo;
}

struct Nodo*
EliminarDato(struct Nodo *nodo, int opcion){
	switch(opcion){
		case 1:
			return EliminarDatoAlInicio(nodo);
		break;
		case 2:
			return EliminarDatoAlFinal(nodo);	
		break;
	}
	return nodo;
}

struct Nodo*
EliminarDatoAlInicio(struct Nodo *nodo){
	if(nodo == NULL){
		printf("La lista está vacía");
		return nodo;
	}
	struct Nodo *tmp = nodo;
	while(tmp -> siguiente != nodo){
		tmp = tmp -> siguiente;
	}
	tmp -> siguiente = nodo -> siguiente,
	free(nodo);
	return tmp -> siguiente;
}

struct Nodo*
EliminarDatoAlFinal(struct Nodo *nodo){
	if(nodo == NULL){
		printf("La lista está vacía");
	}
	if(nodo -> siguiente == NULL){
		free(nodo);
		return NULL;
	}
	struct Nodo *tmp = nodo;
	while(tmp -> siguiente -> siguiente != nodo){
		tmp = tmp -> siguiente;
	}
	free(tmp -> siguiente);
	tmp -> siguiente = nodo;
	return nodo;
}
