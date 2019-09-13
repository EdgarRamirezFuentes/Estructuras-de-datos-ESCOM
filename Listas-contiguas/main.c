#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Se agrega para poder utilizar memcpy.
#include <stdbool.h> // Se agrega para poder hacer uso de variables de tipo booleanas.
#include <time.h> // Se agrega para poder utilizar números random.
//Es la estructura donde guardaremos la información de nuestra lista.
struct Lista
{
	// Nota: posicionActual Apunta a la posición en la que se agregará un nuevo dato.
	int tamanio; // Almacena la longitud de la lista.
	int *datos; // Almacena los datos ingresados por el usuario mediante memoria dinámica.
	int posicionActual; // Almacena la posición en la que se insertará el siguiente dato introducido(Esa posición está esperando un dato);
};

// Una vez que ya se verifico el espacio de memoria y se modificó si era necesario, esta función recibe la lista en la que se agregará el nuevo dato.
// El dato se agregará en la posición actual y el valor de posición actual aumentará su valor en 1.
void AgregarDato(struct Lista *lista, int dato);

// Recibe como parámetro la lista de la cual se quiere conocer los valores que contiene.
// Si la lista no tiene algún dato, le notificará al usuario de este hecho.
void MostrarLista(struct Lista *lista);

// Recibe como parámetro un apuntador de una struct Lista y verifica si esta lista necesita expandir, disminuir o  es correcto su espacio en memoria.
// Si devuelve 0 su espacio de memoria se encuentra correctamente.
// Si devuelve 1 necesita incrementrar su espacio memoria al doble.
// Si devuelve 2 necesita decrementar su espacio de memoria a la mitad.
int VerificarMemoria(struct Lista *lista);

// Recibe como parámetro un apuntador de una struct Lista y devolverá true si aumenta el espacio de memeoria de la lista, si no regresa un false.
bool AumentarMemoria(struct Lista *lista);

// Recibe como parámetro un apuntador de una struct Lista y devolverá true si decrementó el espacio de memoria de la lista, si no regresa false.
bool DecrementarMemoria(struct Lista *lista);

// Recibe como parámetro un apuntador de una struct Lista y eliminará el último elemento de esta lista.
void  EliminarUltimoDato(struct Lista *lista);

// Recibe como parámetro un apuntador de una struct Lista e invertirá los datos de la lista.
void InvertirLista(struct Lista *lista);

// Recibe como parámetros un apuntador de una struct Lista y el dato a buscar dentro de la lista.
void BuscarDato(struct Lista *lista, int dato);

// Recibe como parámetro un apuntador de una struct Lista y verifica si contiene algún dato.
bool EstaVacia(struct Lista *lista);

// Recibe como parámetro un apuntador de una struct Lista y crea una nueva lista con los datos alternados de una lista random y un guardian.
// para saber si la lista actual está alternada o está en estado normal.
void AlternarLista(struct Lista *lista, bool *estaAlternada);

int main(){
	// Se inicializa un puntero de tipo struct Lista y se almacena espacio de memoria con el tamaño de una struct Lista.
	struct Lista *lista= (struct Lista*) malloc(sizeof(struct Lista));
       	lista -> datos = (int*) malloc(8*sizeof(int)); // Se le asigna el tamaño al campo puntero dato donde se guardarán los datos ingresados.
	lista -> tamanio = 8; // Se establece el valor del tamaño de la lista datos con base al valor con que se inicializó.
	lista -> posicionActual = 0; // Se establece el guardián el cual cuidará nuestra posición actual.
	int  opcion; // Se declara la variable opción como guardián de la opción que escoja el usuario.
	bool repetir; // Se declara la variable repetir como guardián para saber si el usuario quiere hacer otra operación en el sistema.
	int dato = 0; // Se declara la variable dato la cual va a almacenar el dato que se quiera agregar o buscar.
	bool estaAlternada = false; // Guardián que checa si la lista actual está alternada con una random.
	do {
		system("clear"); // Borramos todo datos que esté en consola.
		repetir = true; // Inicializamos la variable repetir en true.
		opcion = 0; // Inicializamos par
		printf("Listas\n");
		printf("1. Agregar Elemento a lista.\n2. Eliminar último elemento de la lista.\n3. Mostrar Lista.\n4. Invertir Lista Actual\n");
		printf("5. Buscar un dato en la lista.\n6. Contar elementos de la lista\n7. Alternar lista con lista random\n8. Salir");
		printf("\n¿Qué operación deseas hacer? ");
		scanf("%d", &opcion); // Escaneamos la decisión del usuario ante las opciones mostradas.
		switch(opcion) // Con base a lo que seleccionó el usuario haremos un proceso.
		{
			// Nota: system("clear") limpiar la consola para mejor visualización de los datos.
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
			default: // La opción ingresada no es válida.
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
void AgregarDato(struct Lista *lista, int dato)
{
	if(VerificarMemoria(lista) == 1) // Evaluamos si necesita incrementar su tamaño de memoria, si lo necesita...
	{
		if(AumentarMemoria(lista)){ // Mandamos a Aumentar el espacio de memoria y esperamos la respuesta de la operación, si se hizo ...
			*(lista-> datos + lista -> posicionActual) = dato; // Leemos el dato y lo asignamos al valor de la posición actual.
			lista -> posicionActual++; // Y la posición aumenta en 1.
			system("clear"); // Limpiamos la consola.
			printf("Se agregó correctamente el dato a la lista.");

		}else{ // Si no se pudo aumentar la memoria...
			printf("No se encontró memoria para almacenar más datos."); // Notificamos al usuario que no queda espacio en la memoria.
		}
	}else{ // Si no necesita aumentar su memoria, entonces...
		*(lista -> datos + lista-> posicionActual) = dato; // Leemos el dato y los asignamos al valor de la posición actual.
		lista -> posicionActual++; // Y la posición aumenta en 1.
		system("clear");
		printf("Se agregó correctamente el dato a la lista.");
	}
}

void MostrarLista(struct Lista *lista){
	if(EstaVacia(lista)){ // Verifica que tenga por lo menos un elemento en la lista, si no hay algún dato, entonces...
		printf("No hay datos en la lista"); // Notificamos al usuario que no existen datos en la lista.
	}else{ // Si tiene por lo menos un dato, entonces...
		printf("\nLa lista actual es la siguiente: \n");
		for(int i = 0; i < lista -> posicionActual; i++){ //Hacemos un recorrido de la lista
			printf("| %d |", *(lista -> datos + i)); // E imprimimos el dato de cada casilla.
		}
	}
}

int VerificarMemoria(struct Lista *lista){
	if(lista -> tamanio == lista -> posicionActual){ // Verifica si el tamaño de la lista es igual a la posición actual de la lista si lo es...
		return 1; // Necesita incremento de espacio de memoria.
	}else if(lista -> posicionActual == (lista -> tamanio / 2)-1){ // Si no, verifica si posicion actual es igual a el tamaño menos uno, si lo es 
		return 2; // Necesita decremento de espacio de memoria
	}else{ // Si no cumple las siguientes condicionales entonces...
		return 0; // No necesita modificar su espacio de memoria.
	}
}

bool AumentarMemoria(struct Lista *lista){
	int *tmp; // Se crea una variable temporal para respaldar nuestra información de lista.
	lista -> tamanio *= 2; // Por eficiencia se aumentará el espacio de memoria al doble cada que lo requiera.
	tmp = (int*) malloc ( lista->tamanio * sizeof(int)); // Se reserva el nuevo espacio de memoria necesario para guardar más datos en la lista.
	if(tmp != NULL){ // Si se asignó un espacio en la memoria a la variable temporal, entonces...
		// Se copian los datos de nuestra lista principal a la lista temporal y la nueva lista tiene tamaño correcto.
		memcpy(tmp, lista->datos , (lista -> tamanio/2) * sizeof(int)); 
		free(lista->datos); // Se libera la memoria que ocupaba nuestra lista anterior para disponer de más memoria.
		lista -> datos = tmp; // Ahora la nueva lista de datos de la estructura.
	       return true; // Regresa un true para indicar que se logró hacer la migración de información y se aumentó el espacio de memoria.
	}else{ // Si es igual a NULL significa que ya no había espacio para alojar una lista de tamaño lista-> tamanio *= 2.
		lista -> tamanio /=2; // Se regresa el tamaño de la lista original a su tamaño original.
		return false; // Regresa un false para indicar que no se logró hacer el aumento de tamaño.
	}
}

bool DecrementarMemoria(struct Lista *lista){
	int *tmp; // Se crea una variable temporal para respaldar nuestra información de lista.
	lista -> tamanio /= 2; // Disminuimos el tamaño de la lista actual a la mitad para liberar espacio de memoria.
	// Se reserva el espacio de  memoria de la nueva lista reducida en nuestra variable temporal.
	tmp = (int*) malloc(lista -> tamanio * sizeof(int));
       if(tmp != NULL){ // Se checa si se asignó una dirección de memoria a nuestra variable temporal.
    		memcpy(tmp, lista -> datos, (lista -> tamanio) * sizeof(int)); // Hacemos la copia de la mitad del lista original en la temporal.
	     	free(lista -> datos); // Liberamos la memoria de la lista original.
		lista -> datos = tmp; // Igualamos el puntero de la lista de struct Lista a nuestra nueva lista temporal con tamaño correcto.
		return true; // Regresa true para saber que todo se hizo correcto.
       }else{
		lista -> tamanio *= 2; // Se regresa el tamaño de la lista original.
		return false;
       }	       
}
void EliminarUltimoDato(struct Lista *lista){
	if(!EstaVacia(lista)){ // Verifica si hay por lo menos un elemento en la lista, si se cumple...
		if(VerificarMemoria(lista) == 2){ // Verificamos si se necesita decrementar memoria, si lo necesita...
			if(DecrementarMemoria(lista)){ // Decrementamos la memoria de la lista.
				*(lista-> datos + (lista-> posicionActual - 1)) = 0; // Le da el valor de 0 a la posición anterior de la pos actual.
				lista -> posicionActual--; // Y disminuye la posición actual.
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
		printf("No hay elementos para eliminar"); // Si no hay elementos para eliminar le avisamos al usuario acerca esto.
	}
}

void InvertirLista(struct Lista *lista){
	if(!EstaVacia(lista)){ // Verificamos que tengamos datos para invertir
		int *tmp = (int*) malloc(lista -> tamanio * sizeof(int)); // Creamos una lista temporal en la cual se guardan los datos invertidos.
		int posicionListaTmp = 0; // Declaramos esta variable para controlar la posicion de insercion en la nueva lista.
		for(int i = lista -> posicionActual - 1; i >= 0; i--){ // Iniciamos la cuenta desde nuestro último dato de la lista original.
			*(tmp + posicionListaTmp) = *(lista -> datos + i); // La posición de tmp guarda el valor de la posición de la lista original.
			posicionListaTmp++; // Aumenta la posición de inserción en la nueva lista.
		}
		free(lista -> datos); // Liberamos la memoria de la lista original porque ya hemos respaldado los datos invertidos.
		lista -> datos = tmp; // Ahora la lista es la nueva lista con los datos invertidos.
		printf("Se ha invertido la lista correctamente.");
	}else{ // Si está vacía la lista...
		printf("No hay datos que invertir"); // Notificamos al usuario.
	}
}

void BuscarDato(struct Lista *lista, int dato){
	int  contadorDeApariciones = 0; // Guardián para contar las veces de apariciones 
	struct Lista *posicionDeAparicion = (struct Lista*) malloc(sizeof(struct Lista)); // Lista temporal para almacenar las posiciones de aparicion
	posicionDeAparicion -> tamanio = 8; // Se declara un tamaño inicial de nuestra lista temporal.
	posicionDeAparicion -> posicionActual = 0; // Se declara la posición inicial en nuestra lista temporal.
	posicionDeAparicion -> datos = (int*)malloc(8*sizeof(int)); // Se le da el tamaño al arreglo dinámico donde estarán las posiciones guardadas.
	if(!EstaVacia(lista)){ // Checamos si tiene por lo menos un dato, si lo tiene, entonces...
		for(int i = 0; i < lista -> posicionActual; i++){ //Hacemos un barrido de los datos actuales de la lista original. 
			if(dato == *(lista -> datos + i)){ // Validamos si el dato en la posición actual es igual al dato enviado por el usuario.
				AgregarDato(posicionDeAparicion, i); // Agregamos la posición del dato a nuestro arreglo que almacena posiciones.
				contadorDeApariciones++; // Aumentamos el número de apariciones del dato en la lista.
			}
		}
		if(contadorDeApariciones > 0){ // Si al finalizar el barrido el dato apareció más de una vez...
			//Imprimimos el número de apariciones y las posiciones en las que se encuentra.
			printf("\nEl dato aparece %d veces y se encuentra en las posiciones: ", contadorDeApariciones);
			for(int i= 0; i < posicionDeAparicion -> posicionActual; i++){
				printf(" %d,", *(posicionDeAparicion -> datos + i));
			}
			free(posicionDeAparicion); // Liberamos la memoria utilizada para la lista temporal.
		}else{ // Si no aparece el dato ni una sola vez en la lista, entonces...
			printf("El dato %d no se encuentra en la lista.", dato); // Informamos al usuario acerca de la situación.
			free(posicionDeAparicion); // Liberamos la memoria utilizada para la lista temporal.
		}
	}else{ // Si la lista está vacía, entonces...
		printf("La lista está vacía"); // Notificamos al usuario acerca de la situación.
		free(posicionDeAparicion); // Y liberamos la memoria utilizada para nuestra lista temporal.
	}
}
bool EstaVacia(struct Lista *lista){
	if(lista-> posicionActual == 0){ // Checamos si la lista está vacía, si lo está...
		return true; // Retorna un true para saber que está vacía.
	}else{ // Si no está vacía, entonces...
		return false; // Retorna false para saber que que tiene por lo menos un dato la lista.
	}
}
void AlternarLista(struct Lista *lista, bool *estaAlternada){
	// Creamos una lista con el número de datos en la lista original + 1.
	int *listaRandom = (int*) malloc((lista -> posicionActual) * sizeof(int));
	int *listaAlternada = (int*) malloc(((lista -> posicionActual + 1) * 2)  * sizeof(int));
	int posicionEnListas = 0;
	// Damos una semilla distinta para generar números random.
	srand(time(NULL));
	for(int i = 0; i < lista -> posicionActual;i++){
		*(listaRandom + i) = rand() % (101 - 1); // Asignamos un número random entre 1 y 100 a la posición actual en lista random.
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
