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
	if(nodoHijo != raiz){
		if(raiz -> derecha  == nodoHijo || raiz -> izquierda == nodoHijo){
			return raiz;
		}	
		if(nodoHijo -> dato > raiz -> dato){
			return BuscarPadre(raiz -> derecha, nodoHijo);
		}
		return BuscarPadre(raiz -> izquierda, nodoHijo);
	}
	return raiz;
}

int EsHoja(struct Nodo *nodo){
	if(nodo -> izquierda == NULL && nodo -> derecha == NULL){
		return 1;
	}
	return 0;
} 

int NoTieneHijoIzquierdo(struct Nodo *nodo){
	if(nodo -> izquierda == NULL){
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

struct Nodo* EliminarDato(struct Nodo *raiz, int dato){
	struct Nodo *nodoAEliminar = BuscarDato(raiz, dato);
	if(nodoAEliminar != NULL){
		if(nodoAEliminar != raiz){
			struct Nodo *padre = BuscarPadre(raiz, nodoAEliminar);
			// No hay nodos más grandes que el nodo a eliminar.
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

			// Casos cuando hay nodos más grandes que el nodo a eliminar.

			// El nodo a la derecha del nodo a eliminar es el más chico de los grandes.
			if(NoTieneHijoIzquierdo(nodoAEliminar -> derecha) == 1){
				nodoAEliminar -> derecha -> izquierda = nodoAEliminar -> izquierda;
				if(dato > padre -> dato){
					padre -> derecha = nodoAEliminar -> derecha;
					free(nodoAEliminar);
					return raiz;
				}
				padre -> izquierda = nodoAEliminar -> derecha;
				free(nodoAEliminar);
				return raiz;
			}
			// El nodo a la derecha del nodo a eliminar no es el más chico.
			struct Nodo *nodoMasChico = BuscarElMasPequenioDeLosGrandes(nodoAEliminar -> derecha);
			struct Nodo *padreNodoMasChico = BuscarPadre(raiz, nodoMasChico);
			padreNodoMasChico -> izquierda = nodoMasChico -> derecha;
			if(dato > padre -> dato){
				padre -> derecha = nodoMasChico;
			}else{
				padre -> izquierda = nodoMasChico;	
			}
			nodoMasChico -> derecha = nodoAEliminar-> derecha;
			free(nodoAEliminar);
			return raiz;
		}
		// Si el nodo a eliminar es raiz
		if(EsHoja(nodoAEliminar) == 1){
			free(nodoAEliminar);
			return NULL;
		}	
		if(TieneSoloHijoIzquierdo(nodoAEliminar) == 1){
			struct Nodo *nuevaRaiz = nodoAEliminar -> izquierda;
			free(nodoAEliminar);
			return nuevaRaiz;
		}
		if(NoTieneHijoIzquierdo(nodoAEliminar -> derecha) == 1){
			struct Nodo *nuevaRaiz = nodoAEliminar -> derecha;
			nuevaRaiz -> izquierda = nodoAEliminar -> izquierda;
			free(nodoAEliminar);
			return nuevaRaiz;
		}
		struct Nodo *nodoMasChico = BuscarElMasPequenioDeLosGrandes(nodoAEliminar -> derecha);
		struct Nodo *padreNodoMasChico = BuscarPadre(raiz, nodoMasChico);
		padreNodoMasChico -> izquierda = nodoMasChico -> derecha;
		nodoMasChico -> izquierda = nodoAEliminar -> izquierda;
		nodoMasChico -> derecha = nodoAEliminar -> derecha;
		free(nodoAEliminar);
		return nodoMasChico;
	}
	return raiz;
}

struct Nodo* BuscarElMasPequenioDeLosGrandes(struct Nodo *nodo){
	if(nodo -> izquierda == NULL){
		return nodo;
	}
	return BuscarElMasPequenioDeLosGrandes(nodo -> izquierda);
}

void mostrar (struct Nodo *raiz)
{
	if (raiz == NULL)
	{
		return;
	}

	mostrar (raiz->izquierda);
	printf ("%d, ", raiz->dato);
	mostrar (raiz->derecha);
}	
