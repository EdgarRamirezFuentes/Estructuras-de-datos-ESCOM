#include "cola.h"

int main(void) {
    struct Cola *cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola -> total = 0;
    cola -> datos = NULL;
    enqueue(cola, 5);
    enqueue(cola, 10);
    enqueue(cola, 15);
    enqueue(cola, 20);
    MostrarCola(cola);
    dequeue(cola);
    MostrarCola(cola);
    enqueue(cola, 5);
    MostrarCola(cola);
    
    return 0;
}
