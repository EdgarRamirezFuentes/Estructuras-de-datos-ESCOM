lista-simplemente-enlazada.o: lista-simplemente-enlazada.c
	gcc lista-simplemente-enlazada.c -c
main.o: main.c
	gcc main.c -c
a.out: main.o lista-simplemente-enlazada.o
	gcc main.o lista-simplemente-enlazada.o
run: a.out
	./a.out
clean:
	rm -f main.o lista-simplemente-enlazada.o a.out
