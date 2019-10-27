#ifndef __LISTACIRCULAR_H__
#define __LISTACIRCULAR_H__

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *siguiente;
};

// Agrega un dato a la lista al inicio o al final de ella (El usuario elige la posición).
struct Nodo*
AgregarDato(struct Nodo *nodo, int dato, int opcion);

struct Nodo*
AgregarDatoAlInicio(struct Nodo *nodo, int dato);

void 
MostrarLista(struct Nodo *nodo);

struct Nodo*
AgregarDatoAlFinal(struct Nodo *nodo, int opcion);

struct Nodo*
EliminarDato(struct Nodo *nodo, int opcion);

struct Nodo*
EliminarDatoAlInicio(struct Nodo *nodo);

struct Nodo*
EliminarDatoAlFinal(struct Nodo *nodo);

#endif
