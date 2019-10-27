#include "pila.h"

int
main(void){
		struct Pila *pila = (struct Pila*)malloc(sizeof(struct Pila));
		pila -> total = 0;
		pila -> datos = NULL;
		push(pila, 5);
		printf("El dato tope es %d\n", peek(pila));
		push(pila,10);
		printf("El dato tope es %d\n", peek(pila));
		MostrarPila(pila);	
}
