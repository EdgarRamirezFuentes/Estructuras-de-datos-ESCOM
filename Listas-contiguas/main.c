#include "lista-contigua.h"
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
