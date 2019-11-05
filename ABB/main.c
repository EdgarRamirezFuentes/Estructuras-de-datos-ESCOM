#include "abb.h"
int main(void){
	struct Arbol *raiz = NULL;
	struct Lista *ColaBFS = NULL;

	raiz = AgregarDato(raiz, 100);
	raiz = AgregarDato(raiz, 80);
	raiz = AgregarDato(raiz, 200);
	raiz = AgregarDato(raiz, 70);
	raiz = AgregarDato(raiz, 90);
	raiz = AgregarDato(raiz, 150);
	raiz = AgregarDato(raiz, 204);
	raiz = AgregarDato(raiz, 50);
	raiz = AgregarDato(raiz, 71);
	raiz = AgregarDato(raiz, 86);
	raiz = AgregarDato(raiz, 95);
	raiz = AgregarDato(raiz, 52);
	printf("BFS: ");
	BFS(raiz, ColaBFS);
	EliminarDato(raiz, 80);
	printf("Despues de eliminar 80: ");
	BFS(raiz, ColaBFS);
	return 0;
}
