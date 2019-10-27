lista-contigua.o: lista-contigua.c
	gcc lista-contigua.c -c
main.o: main.c
	gcc main.c -c
a.out: main.o lista-contigua.o
	gcc main.o lista-contigua.o
run: a.out
	./a.out
clean:
	rm -f a.out main.o lista-contigua.o *.swp

