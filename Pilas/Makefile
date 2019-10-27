lista-simplemente-enlazada.o: lista-simplemente-enlazada.c
	gcc lista-simplemente-enlazada.c -c
main.o: main.c
	gcc main.c -c
pila.o: pila.c
	gcc pila.c -c
a.out: main.o lista-simplemente-enlazada.o pila.o
	gcc main.o lista-simplemente-enlazada.o pila.o
run: a.out
	./a.out
clean:
	rm -f main.o lista-simplemente-enlazada.o a.out pila.o *.swp
