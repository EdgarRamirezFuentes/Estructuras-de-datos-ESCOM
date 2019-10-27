main.o: main.c
	gcc -c main.c
lista-circular.o: lista-circular.c	
	gcc -c lista-circular.c
a.out: main.o lista-circular.o
	gcc  main.o lista-circular.o
run: a.out
	./a.out
clean: 
	rm -f main.o lista-circular.o *.swp a.out
