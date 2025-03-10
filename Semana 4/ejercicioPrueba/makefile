OBJS = main.o funciones.o
CC = gcc 
CFLAGS = -c -fcommon

ejemplo : $(OBJS)
	$(CC) $(OBJS) -o ejemplo

main.o : funciones.h main.c
	$(CC) $(CFLAGS) main.c

funciones.o : funciones.c
	$(CC) $(CFLAGS) funciones.c