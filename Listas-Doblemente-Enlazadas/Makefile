main.o: main.c
	gcc main.c -c
lista-doblemente-enlazada.o: lista-doblemente-enlazada.c
	gcc lista-doblemente-enlazada.c -c
a.out: main.o lista-doblemente-enlazada.o
	gcc main.o lista-doblemente-enlazada.o
run: a.out 
	./a.out
clean:
	rm -f main.o lista-doblemente-enlazada.o a.out
