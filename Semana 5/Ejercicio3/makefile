
ejecicio3: calcvect.o vector.o iovector.o
	gcc calcvect-o vector.o iovector.o -lm -o ejecicio3

calcvect.o: calcvect.c vector.h iovector.h
	gcc -c calcvect.c

vector.o: vector.c vector.h
	gcc -c vector.c

iovector.o: iovector.c iovector.h
	gcc -c iovector.c

clean:
	rm *.o

# Usamos -lm porque usamos la biblioteca math.h