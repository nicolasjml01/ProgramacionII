OBJS = main.o empleado.o
CC = gcc
#CTAGS = -c 
CTAGS = -c -g -DDEBUG

empleados : $(OBJS)
	$(CC) $(OBJS) -o empleados

main.o : main.c empleado.h
	$(CC) $(CTAGS) main.c

empleado.o : empleado.c empleado.h
	$(CC) $(CTAGS) empleado.c
clean:
	rm $(OBJS) empleados	
