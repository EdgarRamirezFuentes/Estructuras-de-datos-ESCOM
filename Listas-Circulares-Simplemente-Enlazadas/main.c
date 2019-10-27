#include "lista-circular.h"

int 
main(void){
	struct Nodo *nodo = NULL;
	MostrarLista(nodo);
	nodo = AgregarDato(nodo, 3, 1);
	MostrarLista(nodo);
	nodo = AgregarDato(nodo, 2, 1);
	MostrarLista(nodo);
	nodo = AgregarDato(nodo, 4, 2);
	MostrarLista(nodo);
	nodo = EliminarDato(nodo, 1);
	MostrarLista(nodo);
	nodo = EliminarDato(nodo, 2);
	MostrarLista(nodo);
	return 0;
}

