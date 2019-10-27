#include "lista-contigua.h"

void 
AgregarDato(struct Lista *lista, int dato){
	if(VerificarMemoria(lista) == 1)// Evaluamos si necesita incrementar su tamaño de memoria.
	{
		if(AumentarMemoria(lista)){ 
			*(lista-> datos + lista -> posicionActual) = dato; 
			lista -> posicionActual++; 
			system("clear"); 
			printf("Se agregó correctamente el dato a la lista.");

		}else{ 
			printf("No se encontró memoria para almacenar más datos."); 
		}
	}else{ 
		*(lista -> datos + lista-> posicionActual) = dato; 
		lista -> posicionActual++; 
		system("clear");
		printf("Se agregó correctamente el dato a la lista.");
	}
}

void 
MostrarLista(struct Lista *lista){
	if(EstaVacia(lista)){ 
		printf("No hay datos en la lista"); 
	}else{ 
		printf("\nLa lista actual es la siguiente: \n");
		for(int i = 0; i < lista -> posicionActual; i++){ 
			printf("| %d |", *(lista -> datos + i)); 
		}
	}
}

int 
VerificarMemoria(struct Lista *lista){
	if(lista -> tamanio == lista -> posicionActual){ 
		return 1; // Necesita incremento de espacio de memoria.
	}else if(lista -> posicionActual == (lista -> tamanio / 2)-1){  
		return 2; // Necesita decremento de espacio de memoria
	}else{ 
		return 0; // No necesita modificar su espacio de memoria.
	}
}

bool 
AumentarMemoria(struct Lista *lista){
	int *tmp; 
	lista -> tamanio *= 2; 
	tmp = (int*) malloc ( lista->tamanio * sizeof(int)); 
	if(tmp != NULL){ 
		memcpy(tmp, lista->datos , (lista -> tamanio/2) * sizeof(int)); 
		free(lista->datos); 
		lista -> datos = tmp;
	       return true; 
	}else{ 
		lista -> tamanio /=2; 
		return false; 
	}
}

bool 
DecrementarMemoria(struct Lista *lista){
	int *tmp; 
	lista -> tamanio /= 2; 
	tmp = (int*) malloc(lista -> tamanio * sizeof(int));
       if(tmp != NULL){ 
    		memcpy(tmp, lista -> datos, (lista -> tamanio) * sizeof(int));
	     	free(lista -> datos);
		lista -> datos = tmp; 
		return true; 
       }else{
		lista -> tamanio *= 2; 
		return false;
       }	       
}
void 
EliminarUltimoDato(struct Lista *lista){
	if(!EstaVacia(lista)){ 
		if(VerificarMemoria(lista) == 2){ 
			if(DecrementarMemoria(lista)){ 
				*(lista-> datos + (lista-> posicionActual - 1)) = 0; 
				lista -> posicionActual--; 
				printf("Se ha eliminado el último dato de la lista correctamente");
			}else{
				*(lista -> datos + (lista -> posicionActual - 1)) = 0;
				lista -> posicionActual--;
				printf("Se ha eliminado el último dato de la lista correctamente.");
			}
		}else{
			*(lista -> datos + (lista -> posicionActual - 1)) = 0;
			lista -> posicionActual--;
			printf("Se ha eliminado el último dato de la lista correctamente");
		}
	}else{
		printf("No hay elementos para eliminar"); 
	}
}

void 
InvertirLista(struct Lista *lista){
	if(!EstaVacia(lista)){ 
		int *tmp = (int*) malloc(lista -> tamanio * sizeof(int)); 
		int posicionListaTmp = 0; // Declaramos esta variable para controlar la posicion de insercion en la nueva lista.
		for(int i = lista -> posicionActual - 1; i >= 0; i--){ 
			*(tmp + posicionListaTmp) = *(lista -> datos + i); 
			posicionListaTmp++; 
		}
		free(lista -> datos); 
		lista -> datos = tmp; 
		printf("Se ha invertido la lista correctamente.");
	}else{ 
		printf("No hay datos que invertir"); 
	}
}

void 
BuscarDato(struct Lista *lista, int dato){
	int  contadorDeApariciones = 0;  
	struct Lista *posicionDeAparicion = (struct Lista*) malloc(sizeof(struct Lista)); 
	posicionDeAparicion -> tamanio = 8;
	posicionDeAparicion -> posicionActual = 0; 
	posicionDeAparicion -> datos = (int*)malloc(8*sizeof(int)); 
	if(!EstaVacia(lista)){ 
		for(int i = 0; i < lista -> posicionActual; i++){  
			if(dato == *(lista -> datos + i)){
				AgregarDato(posicionDeAparicion, i);
				contadorDeApariciones++; 
			}
		}
		if(contadorDeApariciones > 0){ 
			printf("\nEl dato aparece %d veces y se encuentra en las posiciones: ", contadorDeApariciones);
			for(int i= 0; i < posicionDeAparicion -> posicionActual; i++){
				printf(" %d,", *(posicionDeAparicion -> datos + i));
			}
			free(posicionDeAparicion); 
		}else{ 
			printf("El dato %d no se encuentra en la lista.", dato); 
			free(posicionDeAparicion);
		}
	}else{ 
		printf("La lista está vacía"); 
		free(posicionDeAparicion); 
	}
}
bool 
EstaVacia(struct Lista *lista){
	if(lista-> posicionActual == 0){ 
		return true; 
	}else{ 
		return false; 
	}
}
void 
AlternarLista(struct Lista *lista, bool *estaAlternada){
	int *listaRandom = (int*) malloc((lista -> posicionActual) * sizeof(int));
	int *listaAlternada = (int*) malloc(((lista -> posicionActual + 1) * 2)  * sizeof(int));
	int posicionEnListas = 0;
	srand(time(NULL));
	for(int i = 0; i < lista -> posicionActual;i++){
		*(listaRandom + i) = rand() % (101 - 1); 
	}
	for(int i = 0; i < lista -> posicionActual *2; i+=2){
		*(listaAlternada + i) = *(lista -> datos + posicionEnListas);
		*(listaAlternada + (i+1)) = *(listaRandom + posicionEnListas);
		posicionEnListas++;
	}
	free(lista -> datos);
	free(listaRandom);
	lista -> datos = listaAlternada;
	lista -> tamanio = (lista -> posicionActual * 2) + 2;
	lista -> posicionActual = (lista -> posicionActual * 2);
	*estaAlternada = true;
	printf("Se ha alternado la lista correctamente.");
}
