#include "cola.h"

int main(void) {
    struct Cola *cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola -> total = 0;
    cola -> datos = NULL;
    enqueue(cola, 5);
    printf("El dato en el tope de la cola es: %d\n", peek(cola));
    MostrarCola(cola);
    enqueue(cola, 10);
    printf("El dato en el tope de la cola es: %d\n", peek(cola));
    MostrarCola(cola);
    dequeue(cola);
    printf("El dato en el tope de la cola es: %d\n", peek(cola));
    MostrarCola(cola);
    return 0;
}
