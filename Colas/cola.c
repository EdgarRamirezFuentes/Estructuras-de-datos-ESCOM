#include "cola.h"
#include "lista-circular-d.h"

void
enqueue(struct Cola *cola, int dato){
    cola -> datos = AgregarNuevoNodoAlFinal(cola -> datos, dato);
}

void
MostrarCola(struct Cola *cola){
    if(cola -> datos != NULL){
        printf("Cola: ");
        struct Nodo *tmp = cola -> datos;
        do{
            printf("| %d |", tmp -> dato);
            tmp = tmp -> siguiente;
        }while(tmp != cola -> datos);
        printf("\n");
    }
}

void 
dequeue(struct Cola *cola){
    cola -> datos = EliminarNodoAlInicio(cola -> datos);
}

int
peek(struct Cola *cola){
    if(cola -> datos != NULL){
        return cola -> datos -> dato;
    }
    return 0;
}


