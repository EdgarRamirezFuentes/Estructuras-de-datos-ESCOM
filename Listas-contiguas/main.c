/**
 \file main.c
 \author Edgar Alejandro Ramírez Fuentes
 \version 1.1
 \last update date 19 / 09 / 2019
 \copyright GNU Public License v3.
 Implementación de las funciones básicas
 y algunas funciones opcionales de una 
 lista de memoria contigua:
 + AgregarDato
 + MostrarLista
 + VerificarMemoria
 + AumentarMemoria
 + DecrementarMemoria
 + EliminarUltimoDato
 + InvertirLista
 + BuscarDato
 + EstaVacia
 + AlternarLista 
*/


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

int 
main(void){
	struct Lista *lista= (struct Lista*) malloc(sizeof(struct Lista));
       	lista -> datos = (int*) malloc(8*sizeof(int));
	lista -> tamanio = 8;
	lista -> posicionActual = 0;
	int  opcion;
	bool repetir; 
	int dato = 0;
	bool estaAlternada = false;
	do {
		system("clear"); 
		repetir = true; 
		opcion = 0; 
		printf("Listas\n");
		printf("1. Agregar Elemento a lista.\n2. Eliminar último elemento de la lista.\n3. Mostrar Lista.\n4. Invertir Lista Actual\n");
		printf("5. Buscar un dato en la lista.\n6. Contar elementos de la lista\n7. Alternar lista con lista random\n8. Salir");
		printf("\n¿Qué operación deseas hacer? ");
		scanf("%d", &opcion); 
		switch(opcion)
		{
			
			case 1: // Agregar un Dato a lista.
				system("clear");
				printf("Ingresa el dato que se agregará a la lista: ");
				scanf("%d", &dato);		
				AgregarDato(lista, dato);
			break;
			case 2: // Eliminar el último dato de la lista.i
				system("clear");
				EliminarUltimoDato(lista);
			break;
			case 3: // Mostar los datos de la lista.
				system("clear");
				MostrarLista(lista);
			break;
			case 4: // Invertir la lista actual.
				system("clear");
				InvertirLista(lista);
			break;
			case 5: // Buscar un dato en la lista.
				system("clear");
				printf("¿Qué dato deseas buscar en la lista? ");
				scanf("%d", &dato);
				BuscarDato(lista,dato);
			break;
			case 6: // Imprimir el número de datos en la lista.
				printf("La lista tiene %d datos.", lista -> posicionActual);
			break;
			case 7: // Alternar la lista actual con una random del mismo tamaño.
				AlternarLista(lista, &estaAlternada);
			break;
			case 8: // Salir del programa.
				free(lista);
				return 0;
			break;
			default:
				printf("Opción no válida.");
			break;
		}
		system("clear");
		printf("\n¿Deseas hacer otra operación?\n1 -> Sí.\n2. -> No.");
		scanf("%d", &opcion); // Reutilizamos la variable opcion para saber si desea hacer más operaciones o salir.
		if(opcion != 1){
			repetir = false;
		}
	}while(repetir != false);
	free(lista);
	return 0;
}
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
