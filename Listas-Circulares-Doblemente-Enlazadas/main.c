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
	nodo = AgregarNuevoNodo(nodo, 5, 1);
	nodo = AgregarNuevoNodo(nodo, 10, 1);
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo, 1);
	MostrarLista(nodo);
	return 0;
}

struct Nodo*
AgregarNuevoNodo(struct Nodo *nodo, int dato, int opcion){
	if(nodo == NULL){
		nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
		if(nodo != NULL){
			nodo -> dato = dato;
			nodo -> anterior = nodo;
			nodo -> siguiente = nodo;
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
	return NULL;
}

struct Nodo*
AgregarNuevoNodoAlInicio(struct Nodo *nodo, int dato){
	struct Nodo *nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
	if(nuevoNodo != NULL){
		struct Nodo *tmp = nodo;
		while(tmp -> siguiente != nodo){
			tmp = tmp -> siguiente;
		}
		nuevoNodo -> dato = dato;
		nuevoNodo -> siguiente = nodo;
		nuevoNodo -> anterior = tmp;
		nodo -> anterior = nuevoNodo;
		tmp -> siguiente = nuevoNodo;
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
		while(tmpParaRecorrerLista -> siguiente != nodo){
			tmpParaRecorrerLista = tmpParaRecorrerLista -> siguiente;
		}
		nuevoNodo -> dato = dato;
		nuevoNodo -> anterior = tmpParaRecorrerLista;
		nuevoNodo -> siguiente = nodo;
		tmpParaRecorrerLista -> siguiente = nuevoNodo;
		nodo -> anterior = nuevoNodo;
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
	return NULL;
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
			struct Nodo *nodoFinal =nodo;
			while( nodoFinal -> siguiente != nodo){
				nodoFinal = nodoFinal -> siguiente;
			}
			nodoFinal -> siguiente=  direccionNuevoInicioLista;
			direccionNuevoInicioLista -> anterior  = nodoFinal;
			free(nodo);
			return direccionNuevoInicioLista;
		}
	}else{
		free(nodo);
		return NULL;
	}
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
		if(nodo -> siguiente == nodo){
			printf("| %d |", nodo -> dato);
		}else{
			struct Nodo *tmp = nodo;
			while(tmp -> siguiente != nodo){
				printf("| %d |", tmp -> dato);
				tmp = tmp -> siguiente;
			}
			printf("| %d |", tmp -> dato);
		}
		
		printf("\n");
	}else{
		printf("La lista no tiene datos\n");
	}
}
