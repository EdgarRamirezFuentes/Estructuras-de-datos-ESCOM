#include "lista-doblemente-enlazada.h"

int main(void){
	struct Nodo *nodo = NULL;	
	/* Opciones AgregarNuevoNodo
	 * 1. Agregar al Inicio
	 * 2. Agregar al final
	 *
	 * Opciones EliminarNodo
	 * 1. EliminarAlInicio
	 * 2. EliminarAlFinal
	 * */
	//nodo = AgregarNuevoNodo(nodo, 5, 1);
	//nodo = AgregarNuevoNodo(nodo, 10, 1);
	nodo = AgregarNuevoNodo(nodo, 15, 1);
	nodo = AgregarNuevoNodo(nodo, 0, 2);
	printf("Lista Original: ");
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo, 1);
	printf("Lista después de eliminar un nodo al inicio: ");
	MostrarLista(nodo);
	nodo = EliminarNodo(nodo,2);
	printf("Lista después de eliminar un nodo al final: ");
	MostrarLista(nodo);
	return 0;
}

