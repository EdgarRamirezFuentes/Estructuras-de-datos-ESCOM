#include "abb.h"

struct Nodo* AgregarDato(struct Nodo *raiz, int dato){
	struct Nodo *nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
	if(nuevoNodo != NULL){
		nuevoNodo -> dato = dato;
		if(raiz == NULL){
			if(nuevoNodo != 0){
				return nuevoNodo;
			}
			return NULL;
		}
		if(raiz -> dato == dato){
			free(nuevoNodo);
			return raiz;
		}
		if(dato > raiz -> dato){
			raiz -> derecha = AgregarDato(raiz -> derecha, dato);
			return raiz;
		}
		if(dato < raiz -> dato){
			raiz -> izquierda = AgregarDato(raiz -> izquierda, dato);
			return raiz;
		}
	}
	return raiz;
}

struct Nodo* BuscarDato(struct Nodo *raiz, int dato){
	if(raiz == NULL){
		return NULL;
	}
	else if(raiz -> dato == dato){
		return raiz;
	}
	else if(dato > raiz -> dato){
		return BuscarDato(raiz -> derecha, dato);
	}
	return BuscarDato(raiz -> izquierda, dato);
}

struct Nodo* BuscarPadre(struct Nodo *raiz, struct Nodo *nodoHijo){
	if(raiz -> derecha  == nodoHijo || raiz -> izquierda == nodoHijo){
		return raiz;
	}	
	if(nodoHijo -> dato > raiz -> dato){
		return BuscarPadre(raiz -> derecha, nodoHijo);
	}
	return BuscarPadre(raiz -> izquierda, nodoHijo);
}

int EsHoja(struct Nodo *nodo){
	if(nodo -> izquierda == NULL && nodo -> derecha == NULL){
		return 1;
	}
	return 0;
} 

int TieneSoloHijoDerecho(struct Nodo *nodo){
	if(nodo -> derecha != NULL && nodo -> izquierda == NULL){
		return 1;
	}
	return 0;
}

int TieneSoloHijoIzquierdo(struct Nodo *nodo){
	if(nodo -> derecha == NULL && nodo -> izquierda != NULL){
		return 1;
	}
	return 0;
}

int TieneDosHijos(struct Nodo *nodo){
	if(nodo -> izquierda != NULL && nodo -> derecha != NULL){
		return 1;
	}
	return 0;
}

struct Nodo* EliminarDato(struct Nodo *raiz, int dato){
	struct Nodo *nodoAEliminar = BuscarDato(raiz, dato);
	if(nodoAEliminar != NULL){
		if(nodoAEliminar != raiz){
			struct Nodo *padre = BuscarPadre(raiz, nodoAEliminar);
			if(EsHoja(nodoAEliminar) == 1){
				if(dato > padre -> dato){
					free(nodoAEliminar);
					padre -> derecha = NULL;
					return raiz;
				}
				free(nodoAEliminar);
				padre -> izquierda = NULL;
				return raiz;
			}
			if(TieneSoloHijoIzquierdo(nodoAEliminar)){
				if(dato > padre -> dato){
					padre -> derecha = nodoAEliminar -> izquierda; 
					free(nodoAEliminar);
					return raiz;
				}
				padre -> izquierda = nodoAEliminar -> izquierda;
				free(nodoAEliminar);
				return raiz;
			}
			// Casos cuando no es hoja o solo tiene hijo izquierdo
		}	
	}
	return raiz;
}

struct Nodo* BuscarElMasPequenioDeLosGrandes(struct Nodo *nodo){
	if(nodo -> izquierda == NULL){
		return nodo;
	}
	return BuscarElMasPequenioDeLosGrandes(nodo -> izquierda);
}	
