#include "abb.h"
int main(void){
	struct Arbol *raiz = NULL;

	raiz = AgregarDato(raiz, 100);
	raiz = EliminarDato(raiz, 100);
	mostrar(raiz);
	raiz = AgregarDato(raiz, 80);
	raiz = AgregarDato(raiz, 200);
	raiz = AgregarDato(raiz, 70);
	raiz = AgregarDato(raiz, 90);
	raiz = AgregarDato(raiz, 150);
	raiz = AgregarDato(raiz, 204);
	mostrar(raiz);
	raiz = AgregarDato(raiz, 50);
	raiz = AgregarDato(raiz, 71);
	raiz = AgregarDato(raiz, 86);
	EliminarDato(raiz, 100);
	mostrar(raiz);
	raiz = AgregarDato(raiz, 95);
	raiz = AgregarDato(raiz, 52);
	mostrar(raiz);
	return 0;
}
