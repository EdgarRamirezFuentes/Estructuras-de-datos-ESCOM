#include "pila.h"

void
push(struct Pila *pila, int dato){
	pila -> datos = AgregarNodoAlInicio(pila -> datos, dato);
	pila -> total = pila -> total + 1;
}

int 
pop(struct Pila *pila){
	if(isEmpty(pila) == 1){
		return 0;
	}
	if(peek(pila) == 1){
		valorPop = valorPeek;
		pila -> datos = EliminarNodoAlInicio(pila -> datos);
		pila -> total = pila -> total - 1;
	}
	return 1;
}

int
peek(struct Pila *pila){
	if(isEmpty(pila) == 1){
		return 0;
	}
	valorPeek = pila -> datos -> dato;
	return 1;
}

int 
isEmpty(struct Pila *pila){
	if(pila -> datos == NULL){
		return 1;
	}
	return 0;
}

void MostrarPila(struct Pila *pila){
	struct Pila *tmp = NULL;
	if(isEmpty(pila) == 1){
		puts("No hay datos en la pila");
	}
	puts("Los datos en la pila son: ");
	tmp = (struct Pila*)malloc(sizeof(struct Pila));
	if(tmp != NULL){
		while(isEmpty(pila) != 1){
			pop(pila);
			printf("%d, ", valorPop);
			push(tmp, valorPop);
		}
		while(isEmpty(tmp) != 1){
			pop(tmp);
			push(pila, valorPop);
		}
		puts("\n");
	}
}