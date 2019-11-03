abb.o: abb.c
	gcc -c abb.c
main.o: main.c
	gcc -c main.c
a.out: 	main.o abb.o
	gcc main.o abb.o
run:	a.out
	./a.out
clear:	
	rm *.o a.out
