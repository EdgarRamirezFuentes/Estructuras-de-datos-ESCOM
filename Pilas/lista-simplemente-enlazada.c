#include "lista-simplemente-enlazada.h"

struct NodoLista*
AgregarNodoAlInicio(struct NodoLista *nodo, int dato){ // Complejidad O(1)
	struct NodoLista *nuevoNodo = (struct NodoLista*)malloc(sizeof(struct NodoLista));// O(1);
	if(nuevoNodo != NULL){
		nuevoNodo -> dato = dato; // O(1)
		if(nodo != NULL){
			nuevoNodo -> siguiente = nodo; // O(1);
		}
		return nuevoNodo; // O(1)
	}
	return nodo; // O(1)
}

struct NodoLista* 
EliminarNodoAlInicio(struct NodoLista *nodo){ // Complejidad O(1)
	struct NodoLista *tmp = NULL; // O(1)
	if(nodo != NULL){
		tmp = nodo; //O(1) 
		nodo = nodo -> siguiente; //O(1)
		free(tmp); // O(1)
		return nodo; // O(1)
	}
	return nodo; // O(1)
}
