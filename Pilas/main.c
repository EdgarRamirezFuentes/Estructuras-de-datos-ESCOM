#include "pila.h"

int
main(void){
		struct Pila *pila = (struct Pila*)malloc(sizeof(struct Pila));
		pila -> total = 0;
		pila -> datos = NULL;
		if(pop(pila) == 0){
			puts("No hay datos en la pila.");
		}
		push(pila,20);
		push(pila,15);
		push(pila,10);
		push(pila, 5);
		MostrarPila(pila);
		if(pop(pila) == 0){
			puts("No hay datos en la pila.");
		}
		MostrarPila(pila);
		if(peek(pila) == 0){
			puts("No hay datos en la pila");
		}else{
			printf("El valor tope de la pila es: %d", valorPeek);
		}
		
}
