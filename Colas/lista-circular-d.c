#include "lista-circular-d.h"

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
