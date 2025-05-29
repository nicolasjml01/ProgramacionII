ejercicio1: listaEnlazada.o main.o
	gcc listaEnlazada.o main.o -o ejercicio1

listaEnlazada.o : listaEnlazada.c listaEnlazada.h
	gcc -c listaEnlazada.c listaEnlazada.h

main.o: main.c listaEnlazada.h
	gcc -c main.c listaEnlazada.h

clear:
	rm *.o