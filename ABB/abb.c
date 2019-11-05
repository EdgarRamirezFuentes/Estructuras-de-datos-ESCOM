#include "abb.h"
#include "lista-circular-d.h"

struct Arbol* AgregarDato(struct Arbol *raiz, int dato){
	struct Arbol *nuevoArbol = (struct Arbol*) malloc(sizeof(struct Arbol));
	if(nuevoArbol != NULL){
		nuevoArbol -> dato = dato;
		if(raiz == NULL){
			if(nuevoArbol != 0){
				return nuevoArbol;
			}
			return NULL;
		}
		if(raiz -> dato == dato){
			free(nuevoArbol);
			return raiz;
		}
		if(dato > raiz -> dato){
			raiz -> derecha = AgregarDato(raiz -> derecha, dato);
			return raiz;
		}
		if(dato < raiz -> dato){
			raiz -> izquierda = AgregarDato(raiz -> izquierda, dato);
			return raiz;
		}
	}
	return raiz;
}

struct Arbol* BuscarDato(struct Arbol *raiz, int dato){
	if(raiz == NULL){
		return NULL;
	}
	else if(raiz -> dato == dato){
		return raiz;
	}
	else if(dato > raiz -> dato){
		return BuscarDato(raiz -> derecha, dato);
	}
	return BuscarDato(raiz -> izquierda, dato);
}

struct Arbol* BuscarPadre(struct Arbol *raiz, struct Arbol *ArbolHijo){
	if(ArbolHijo != raiz){
		if(raiz -> derecha  == ArbolHijo || raiz -> izquierda == ArbolHijo){
			return raiz;
		}	
		if(ArbolHijo -> dato > raiz -> dato){
			return BuscarPadre(raiz -> derecha, ArbolHijo);
		}
		return BuscarPadre(raiz -> izquierda, ArbolHijo);
	}
	return raiz;
}

int EsHoja(struct Arbol *Arbol){
	if(Arbol -> izquierda == NULL && Arbol -> derecha == NULL){
		return 1;
	}
	return 0;
} 

int NoTieneHijoIzquierdo(struct Arbol *Arbol){
	if(Arbol -> izquierda == NULL){
		return 1;
	}
	return 0;
}

int TieneSoloHijoIzquierdo(struct Arbol *Arbol){
	if(Arbol -> derecha == NULL && Arbol -> izquierda != NULL){
		return 1;
	}
	return 0;
}

struct Arbol* EliminarDato(struct Arbol *raiz, int dato){
	struct Arbol *ArbolAEliminar = BuscarDato(raiz, dato);
	if(ArbolAEliminar != NULL){
		if(ArbolAEliminar != raiz){
			struct Arbol *padre = BuscarPadre(raiz, ArbolAEliminar);
			// No hay Arbols más grandes que el Arbol a eliminar.
			if(EsHoja(ArbolAEliminar) == 1){
				if(dato > padre -> dato){
					free(ArbolAEliminar);
					padre -> derecha = NULL;
					return raiz;
				}
				free(ArbolAEliminar);
				padre -> izquierda = NULL;
				return raiz;
			}
			if(TieneSoloHijoIzquierdo(ArbolAEliminar)){
				if(dato > padre -> dato){
					padre -> derecha = ArbolAEliminar -> izquierda; 
					free(ArbolAEliminar);
					return raiz;
				}
				padre -> izquierda = ArbolAEliminar -> izquierda;
				free(ArbolAEliminar);
				return raiz;
			}

			// Casos cuando hay Arbols más grandes que el Arbol a eliminar.

			// El Arbol a la derecha del Arbol a eliminar es el más chico de los grandes.
			if(NoTieneHijoIzquierdo(ArbolAEliminar -> derecha) == 1){
				ArbolAEliminar -> derecha -> izquierda = ArbolAEliminar -> izquierda;
				if(dato > padre -> dato){
					padre -> derecha = ArbolAEliminar -> derecha;
					free(ArbolAEliminar);
					return raiz;
				}
				padre -> izquierda = ArbolAEliminar -> derecha;
				free(ArbolAEliminar);
				return raiz;
			}
			// El Arbol a la derecha del Arbol a eliminar no es el más chico.
			struct Arbol *ArbolMasChico = BuscarElMasPequenioDeLosGrandes(ArbolAEliminar -> derecha);
			struct Arbol *padreArbolMasChico = BuscarPadre(raiz, ArbolMasChico);
			padreArbolMasChico -> izquierda = ArbolMasChico -> derecha;
			if(dato > padre -> dato){
				padre -> derecha = ArbolMasChico;
			}else{
				padre -> izquierda = ArbolMasChico;	
			}
			ArbolMasChico -> derecha = ArbolAEliminar-> derecha;
			ArbolMasChico -> izquierda = ArbolAEliminar -> izquierda;
			free(ArbolAEliminar);
			return raiz;
		}
		// Si el Arbol a eliminar es raiz
		if(EsHoja(ArbolAEliminar) == 1){
			free(ArbolAEliminar);
			return NULL;
		}	
		if(TieneSoloHijoIzquierdo(ArbolAEliminar) == 1){
			struct Arbol *nuevaRaiz = ArbolAEliminar -> izquierda;
			free(ArbolAEliminar);
			return nuevaRaiz;
		}
		if(NoTieneHijoIzquierdo(ArbolAEliminar -> derecha) == 1){
			struct Arbol *nuevaRaiz = ArbolAEliminar -> derecha;
			nuevaRaiz -> izquierda = ArbolAEliminar -> izquierda;
			free(ArbolAEliminar);
			return nuevaRaiz;
		}
		struct Arbol *ArbolMasChico = BuscarElMasPequenioDeLosGrandes(ArbolAEliminar -> derecha);
		struct Arbol *padreArbolMasChico = BuscarPadre(raiz, ArbolMasChico);
		padreArbolMasChico -> izquierda = ArbolMasChico -> derecha;
		ArbolMasChico -> izquierda = ArbolAEliminar -> izquierda;
		ArbolMasChico -> derecha = ArbolAEliminar -> derecha;
		free(ArbolAEliminar);
		return ArbolMasChico;
	}
	return raiz;
}

struct Arbol* BuscarElMasPequenioDeLosGrandes(struct Arbol *Arbol){
	if(Arbol -> izquierda == NULL){
		return Arbol;
	}
	return BuscarElMasPequenioDeLosGrandes(Arbol -> izquierda);
}

void mostrar (struct Arbol *raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	mostrar (raiz->izquierda);
	printf ("%d, ", raiz->dato);
	mostrar (raiz->derecha);
}

void BFS(struct Arbol *arbol, struct Lista *lista){
	printf("%d, ", arbol -> dato);
	if(arbol -> izquierda != NULL){
		lista = AgregarNuevoListaAlFinal(lista, arbol -> izquierda);
	}	
	if(arbol -> derecha != NULL){
		lista = AgregarNuevoListaAlFinal(lista, arbol -> derecha);
	}
	if(lista == NULL){
		printf("\n");
		return;
	}
	struct Arbol *nuevaRaiz = lista -> dato;
	lista = EliminarListaAlInicio(lista);
	BFS(nuevaRaiz, lista);
	
}
