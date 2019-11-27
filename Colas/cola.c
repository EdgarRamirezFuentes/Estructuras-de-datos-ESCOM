#include "cola.h"
#include "lista-circular-d.h"

void
enqueue(struct Cola *cola, int dato){
    cola -> datos = AgregarNuevoNodoAlFinal(cola -> datos, dato);
    cola -> total = cola -> total + 1;
}


int 
dequeue(struct Cola *cola){
    if(isEmpty(cola) == 1){
        return 0;
    }
    valorDequeue = cola -> datos -> dato;
    cola -> datos = EliminarNodoAlInicio(cola -> datos);
    cola -> total = cola -> total - 1;
    return 1;
}

int
peek(struct Cola *cola){
    if(isEmpty(cola) == 1){
        return 0;
    }
    valorPeek = cola -> datos -> dato;
    return 1;
}

int isEmpty(struct Cola *cola){
    if(cola -> datos == NULL){
        return 1;
    }
    return 0;
}

void MostrarCola(struct Cola *cola){
    if(isEmpty(cola) == 1){
        puts("No hay datos en la cola.");
        return;
    }
    struct Cola *tmp = NULL;
    tmp = (struct Cola*)malloc(sizeof(struct Cola));
    if(tmp == NULL){
        return;
    }
    while(isEmpty(cola) != 1){
        dequeue(cola);
        printf("%d, ", valorDequeue);
        enqueue(tmp, valorDequeue);
    }
    puts("\n");
    cola -> datos = tmp -> datos;
}

