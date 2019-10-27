main.o: main.c
	gcc -c main.c
lista-circular-d.o: lista-circular-d.c
	gcc -c lista-circular-d.c
a.out: main.o lista-circular-d.o
	gcc main.o lista-circular-d.o
run: ./a.out
	./a.out
clean: 
	rm -f main.o lista-circular-d.o a.out *.swp
