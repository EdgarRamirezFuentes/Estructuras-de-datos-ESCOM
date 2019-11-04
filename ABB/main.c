#include "abb.h"

int main(void){
	struct Nodo *raiz = NULL;
	raiz = AgregarDato(raiz, 100);
	raiz = AgregarDato(raiz, 150);
	raiz = AgregarDato(raiz, 180);
	raiz = AgregarDato(raiz, 179);
	raiz = AgregarDato(raiz, 200);
	raiz = AgregarDato(raiz, 148);
	raiz = AgregarDato(raiz, 149);
	raiz = AgregarDato(raiz, 60);
	raiz = AgregarDato(raiz, 70);
	raiz = AgregarDato(raiz, 80);
	raiz = AgregarDato(raiz, 65);
	raiz = AgregarDato(raiz, 50);
	raiz = AgregarDato(raiz, 55);
	mostrar(raiz);
	printf("\n");
	raiz = EliminarDato(raiz, 50);
	mostrar(raiz);
	printf("\nLa nueva raiz es %d\n", raiz -> dato);
	return 0;
}
