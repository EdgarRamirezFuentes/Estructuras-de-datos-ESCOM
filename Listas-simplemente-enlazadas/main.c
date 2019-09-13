#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Nodo {
	int dato;
	struct Nodo *siguiente;
};

// Muestra los elementos de la lista enviada como parámetro.
void MostrarLista(struct Nodo *nodo, int totalDatos);

// Agrega un nuevo nodo al después del último nodo con dato asignado.
struct Nodo* AgregarNuevoNodo(struct Nodo *nodo, int dato, int opcion, bool *hayMemoria, int *totalDatos);

int main(){
	struct Nodo *nodo = (struct Nodo*) calloc(1 , sizeof(struct Nodo));
       	nodo -> siguiente = NULL;
	int opcion;
	int dato;
	bool hayMemoria = true;
	int totalDatos = 0;
	bool repetir = true;
	do{
		system("clear");
		printf("Listas enlazadas.");
		printf("\n1. Agregar al inicio de la lista.\n2. Agregar al final de la lista.\n3. Agregar en una posición específica\n");
		printf("4. Mostrar la lista.");
		printf("\n¿Qué operación deseas hacer? ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
			       	system("clear");	
				if(hayMemoria){
					printf("Ingresa el dato a agregar en la lista: ");
					scanf("%d",&dato);
					nodo = AgregarNuevoNodo(nodo, dato, opcion, &hayMemoria, &totalDatos);
				}else{
					printf("No hay memoria para agregar otro dato");
				}
			break;
			case 2:
				system("clear");
				if(hayMemoria){
					printf("Ingresa el dato que se va a agregar al final de la lista: ");
					scanf("%d", &dato);
					AgregarNuevoNodo(nodo, dato, opcion, &hayMemoria, &totalDatos);

				}else{
					printf("No hay memoria para agregar otro dato");
				}
			break;
			case 3:
				system("clear");
				if(hayMemoria){
					printf("Ingresa el dato que se va a agregar en una posición específica: ");
					scanf("%d", &dato);
					AgregarNuevoNodo(nodo, dato, opcion, &hayMemoria, &totalDatos);
				}else{
					printf("No hay memoria para agregar otro dato.");
				}
			break;
			case 4:
				system("clear");
				MostrarLista(nodo, totalDatos);
			break;
			default:
				system("clear");
				printf("Opción no válida.");
			break;
		}
		system("clear");
		printf("\n1. Sí\n2. No");
		printf("\n¿Deseas hacer otra operación? ");
		scanf("%d", &opcion);
		if(opcion != 1){
			repetir = false;
		}
	}while(repetir != false);
	return 0;
}

struct Nodo* AgregarNuevoNodo(struct Nodo *nodo, int dato, int opcion, bool *hayMemoria, int *totalDatos){
	int posicion = 0;
	switch(opcion){
		case 1:
			if(*totalDatos == 0){
				printf("1");
				nodo -> dato = dato;
				*totalDatos += 1;
				printf("Se agregó correctamente el primer elemento de la lista");
				return nodo;
			}else{
				printf("2");
				printf("Entré al segundo");
				struct Nodo *nuevoNodo;
				nuevoNodo = (struct Nodo*) calloc(1 , sizeof(struct Nodo));
				if(nuevoNodo != NULL){
					nuevoNodo -> siguiente = nodo;
					nuevoNodo -> dato = dato;
					*hayMemoria = true;
					*totalDatos += 1;
					printf("Se agregó correctamente al inicio de la lista.");
					return nuevoNodo;				
				}else{
					printf("No se pudo agregar el nuevo dato, falta memoria");
					*hayMemoria = false;
					return nodo;
				}
			}

		break;
		case 2:
			if(totalDatos == 0){
				nodo -> dato = dato;
				*totalDatos += 1;
				printf("Se agregó correctamente el primer elemento de la lista");
				return nodo;
			}else{
				struct Nodo *nuevoNodo;
				nuevoNodo = (struct Nodo*) calloc(1, sizeof(struct Nodo));
				if(nuevoNodo != NULL){
					while(nodo -> siguiente != NULL){
						nodo = nodo -> siguiente;
					}
					nodo -> siguiente = nuevoNodo;
					nuevoNodo -> dato = dato;
					nuevoNodo -> siguiente = NULL;
					printf("Dato agregado correctamente al final de la lista");
					*hayMemoria = true;
					*totalDatos += 1;
					return nodo;
				}else{
					printf("No se pudo agregar el nuevo dato, falta memoria.");
					*hayMemoria = false;
					return nodo;
				}	
			}
			
		break;
		case 3:
			if(*totalDatos == 0){
				printf("Se agregó correctamente el primer dato de lista.");
			}else{
				MostrarLista(nodo, *totalDatos);
				printf("Ingresa la posición en la que se insertará el dato: ");
				scanf("%d", &posicion);
				if(posicion == 0){
					AgregarNuevoNodo(nodo, dato, opcion, hayMemoria, totalDatos);
				}else{
					for(int i = 0; i < posicion; i++){
						nodo = nodo -> siguente;
					}
					struct Nodo *nuevoNodo =  (struct Nodo*) calloc(1,sizeof(struct Nodo));
					if(nuevoNodo != NULL){
							
					}else{

					}
				}
			}
		break;
	}
}

void MostrarLista(struct Nodo *nodo, int totalDatos){
	if(totalDatos == 0){
		printf("No hay datos agregados en la lista.");
	}else{
		if(nodo -> siguiente != NULL){
			while(nodo != NULL){
				printf("| %d |", nodo -> dato);
				nodo = nodo -> siguiente;
			}
		}else{
			printf("| %d |", nodo -> dato);
		}
	}
}
