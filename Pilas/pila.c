#include "pila.h"

void MostrarPila(struct Pila *pila){
	struct Pila *tmp = pila;
	if(tmp != NULL){
		printf("Datos en la pila:\n");
		while(tmp -> datos != NULL){
			printf("|\t%d\t|\n", tmp -> datos -> dato);
			tmp -> datos = tmp -> datos -> siguiente;
		}
	}else{
		printf("No hay datos en la pila");
	}
}

int 
peek(struct Pila *pila){
    if(pila -> datos != NULL){
         return pila -> datos -> dato;
    }
	return 0;
}

void
push(struct Pila *pila, int dato){
	pila -> datos = AgregarNodoAlInicio(pila -> datos, dato);
}

