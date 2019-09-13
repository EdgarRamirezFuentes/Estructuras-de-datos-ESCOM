#include <stdio.h>
#include <stdlib.h>
struct Nodo {
	int dato;
	struct Nodo *anterior;
	struct Nodo *siguiente;
};

struct Nodo* 
AgregarNuevoNodo(struct Nodo *nodo, int dato, int opcion);

struct Nodo*
AgregarNuevoNodoAlInicio(struct Nodo *nodo, int dato);

struct Nodo*
AgregarNuevoNodoAlFinal(struct Nodo *nodo, int dato);

struct Nodo*
EliminarNodo(struct Nodo *nodo, int opcion);

struct Nodo*
EliminarNodoAlInicio(struct Nodo *nodo);

struct Nodo*
EliminarNodoAlFinal(struct Nodo *nodo);

void
MostrarLista(struct Nodo *nodo);
int main(void){
	struct Nodo *nodo = NULL;	
	/* Opciones AgregarNuevoNodo
	 * 1. Agregar al Inicio
	 * 2. Agregar al final
	 *
	 * Opciones EliminarNodo
	 * 1. EliminarAlInicio
	 * 2. EliminarAlFinal
	 * */
	//nodo = AgregarNuevoNodo(nodo, 5, 1);
	//nodo = AgregarNuevoNodo(nodo, 10, 1);
	nodo = AgregarNuevoNodo(nodo, 15, 1);
	nodo = AgregarNuevoNodo(nodo, 0, 2);
	printf("Lista Original: ");
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo, 1);
	printf("Lista después de eliminar un nodo al inicio: ");
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo,2);
	printf("Lista después de eliminar un nodo al final: ");
	MostrarLista(nodo);
	return 0;
}

struct Nodo*
AgregarNuevoNodo(struct Nodo *nodo, int dato, int opcion){
	if(nodo == NULL){
		nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
		if(nodo != NULL){
			nodo -> dato = dato;
			return nodo;
		}else{
			return NULL;
		}
	}
	switch(opcion){
		case 1:
			return AgregarNuevoNodoAlInicio(nodo, dato);
		break;
		case 2: 
			return AgregarNuevoNodoAlFinal(nodo, dato);
		break;
	}
}

struct Nodo*
AgregarNuevoNodoAlInicio(struct Nodo *nodo, int dato){
	struct Nodo *nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
	if(nuevoNodo != NULL){
		nuevoNodo -> dato = dato; 
		nuevoNodo -> siguiente = nodo;
		nodo -> anterior = nuevoNodo;
		return nuevoNodo;
	}else{
		return nodo;
	}
}
struct Nodo*
AgregarNuevoNodoAlFinal(struct Nodo *nodo, int dato){
	struct Nodo *tmpParaRecorrerLista = nodo;
	struct Nodo *nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
	if(nuevoNodo != NULL){
		while(tmpParaRecorrerLista -> siguiente != NULL){
			tmpParaRecorrerLista = tmpParaRecorrerLista -> siguiente;
		}
		nuevoNodo -> dato = dato;
		nuevoNodo -> anterior = tmpParaRecorrerLista;
		tmpParaRecorrerLista -> siguiente = nuevoNodo;
		return nodo;
	}else{
		return nodo;
	}		
}

struct Nodo*
EliminarNodo(struct Nodo *nodo, int opcion){
	if(nodo == NULL){
		printf("No hay datos en la lista.");
		return NULL;
	}
	switch(opcion){
		case 1:
			return EliminarNodoAlInicio(nodo);
		break;
		case 2:
			return EliminarNodoAlFinal(nodo);
		break;
	}
}

struct Nodo*
EliminarNodoAlInicio(struct Nodo *nodo){
	if(nodo -> siguiente != NULL){
		struct Nodo *direccionNuevoInicioLista;
		direccionNuevoInicioLista = nodo -> siguiente;
		nodo -> siguiente -> anterior = NULL;
		free(nodo);
		return direccionNuevoInicioLista;
	}
	free(nodo);
	return NULL;
}

struct Nodo*
EliminarNodoAlFinal(struct Nodo *nodo){
	if(nodo -> siguiente != NULL){
		struct Nodo *tmpParaRecorrerLista = nodo;
		while(tmpParaRecorrerLista -> siguiente -> siguiente != NULL){
			tmpParaRecorrerLista = tmpParaRecorrerLista -> siguiente;
		}
		free(tmpParaRecorrerLista -> siguiente);
		tmpParaRecorrerLista -> siguiente = NULL;
		return nodo;
	}
	free(nodo);
	return NULL;
}

void 
MostrarLista(struct Nodo *nodo){
	if(nodo != NULL){
		while(nodo != NULL){
			printf("| %d |", nodo -> dato);
			nodo= nodo -> siguiente;
		}
		printf("\n");
	}else{
		printf("La lista no tiene datos\n");
	}
}
