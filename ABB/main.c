#include "abb.h"

int main(void){
	struct Nodo *raiz = NULL;
	raiz = AgregarDato(raiz, 5);
	raiz = AgregarDato(raiz, 10);
	raiz = AgregarDato(raiz, -5);
	if(BuscarDato(raiz, 5) != NULL)
		printf("El dato 5 existe\n");
	else
		printf("El dato 5 no existe\n");
	if(BuscarDato(raiz, 10) != NULL)
		printf("El dato 10 existe\n");
	else
		printf("El dato 10 no existe\n");
	printf("El padre de 10 es: %d\n", BuscarPadre(raiz, BuscarDato(raiz,10)) -> dato);	
	printf("El padre de -5 es: %d\n", BuscarPadre(raiz, BuscarDato(raiz,-5)) -> dato);	
	EliminarDato(raiz, 10);
	if(BuscarDato(raiz, 10) != NULL)
		printf("El dato 10 existe\n");
	else
		printf("El dato 10 no existe\n");
	EliminarDato(raiz, -5);
	if(BuscarDato(raiz, -5) != NULL)
		printf("El dato -5 existe\n");
	else
		printf("El dato -5 no existe\n");
	


	return 0;
}
