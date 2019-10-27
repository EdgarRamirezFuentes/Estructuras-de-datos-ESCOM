#include "lista-circular-d.h"

int
main(void){
	struct Nodo *nodo = NULL;	
	/* Opciones AgregarNuevoNodo
	 * 1. Agregar al Inicio
	 * 2. Agregar al final
	 *
	 * Opciones EliminarNodo
	 * 1. EliminarAlInicio
	 * 2. EliminarAlFinal
	 * */
	nodo = AgregarNuevoNodo(nodo, 5, 2);
	nodo = AgregarNuevoNodo(nodo, 10, 2);
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo, 1);
	MostrarLista(nodo);
	return 0;
}
