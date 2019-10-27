#ifndef __LISTA-CONTIGUA_H__
#define __LISTA-CONTIGUA_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Se agrega para poder utilizar memcpy.
#include <stdbool.h> // Se agrega para poder hacer uso de variables de tipo booleanas.
#include <time.h> // Se agrega para poder utilizar números random.
struct
Lista
{
	// Nota: posicionActual Apunta a la posición en la que se agregará un nuevo dato.
	int tamanio; 
	int *datos; 
	int posicionActual; 
};

void 
AgregarDato(struct Lista *lista, int dato);
void 
MostrarLista(struct Lista *lista);
// Recibe como parámetro un apuntador de una struct Lista y verifica si esta lista necesita expandir, disminuir o  es correcto su espacio en memoria.
// Si devuelve 0 su espacio de memoria se encuentra correctamente.
// Si devuelve 1 necesita incrementrar su espacio memoria al doble.
// Si devuelve 2 necesita decrementar su espacio de memoria a la mitad.
int 
VerificarMemoria(struct Lista *lista);
// Recibe como parámetro un apuntador de una struct Lista y devolverá true si aumenta el espacio de memeoria de la lista, si no regresa un false.
bool 
AumentarMemoria(struct Lista *lista);
// Recibe como parámetro un apuntador de una struct Lista y devolverá true si decrementó el espacio de memoria de la lista, si no regresa false.
bool 
DecrementarMemoria(struct Lista *lista);
void  
EliminarUltimoDato(struct Lista *lista);
void 
InvertirLista(struct Lista *lista);
void 
BuscarDato(struct Lista *lista, int dato);
bool 
EstaVacia(struct Lista *lista);
// Recibe como parámetro un apuntador de una struct Lista y crea una nueva lista con los datos alternados de una lista random.
void 
AlternarLista(struct Lista *lista, bool *estaAlternada);

#endif
