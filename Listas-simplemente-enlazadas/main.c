#include "lista-simplemente-enlazada.h"

int 
main(void){
	struct Nodo *nodo = NULL;
	nodo = AgregarNuevoNodo(nodo,0,1);
	MostrarLista(nodo);
	nodo = AgregarNuevoNodo(nodo,1,2);
	MostrarLista(nodo);
	nodo = AgregarNuevoNodo(nodo,-1,1);
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo, 1);
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo, 2);
	nodo = AgregarNuevoNodo(nodo,2009,1);
	nodo = AgregarNuevoNodo(nodo,2010,2);
	nodo = EliminarNodo(nodo, 2);
	nodo = AgregarNuevoNodo(nodo,2011,2);
	MostrarLista(nodo);
	return 0;
}

