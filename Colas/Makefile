main.o: main.c
	gcc -c main.c
lista-circular-d.o: lista-circular-d.c
	gcc -c lista-circular-d.c
cola.o: cola.c
	gcc -c cola.c

a.out: main.o lista-circular-d.o cola.o
	gcc main.o lista-circular-d.o cola.o

run: ./a.out
	./a.out
clean: 
	rm -f main.o lista-circular-d.o a.out cola.o *.swp
