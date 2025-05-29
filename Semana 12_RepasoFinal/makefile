ejercicios: listaEnlazada.o main.o matricesyListas.o
	gcc listaEnlazada.o main.o matricesyListas.o -o ejercicios

listaEnlazada.o : listaEnlazada.c listaEnlazada.h
	gcc -c listaEnlazada.c listaEnlazada.h

matricesyListas.o: matricesyListas.c matricesyListas.h
	gcc -c matricesyListas.c matricesyListas.h

main.o: main.c listaEnlazada.h matricesyListas.h
	gcc -c main.c listaEnlazada.h

clear:
	rm *.o