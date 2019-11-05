abb.o: abb.c
	gcc -c abb.c
main.o: main.c
	gcc -c main.c
lista-circular-d.o: lista-circular-d.c
	gcc -c lista-circular-d.c
a.out: 	main.o lista-circular-d.o abb.o 
	gcc main.o abb.o lista-circular-d.o  
run:	a.out
	./a.out
clear:	
	rm *.o a.out
