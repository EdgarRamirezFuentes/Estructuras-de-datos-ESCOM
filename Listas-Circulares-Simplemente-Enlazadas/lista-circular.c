#include "lista-circular.h"

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
