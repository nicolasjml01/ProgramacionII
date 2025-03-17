
ejecicio2: cbppal.o cbfaux.o
	gcc cbppal.o cbfaux.o -o ejecicio2

cbppal.o: cbppal.c cbfaux.h
	gcc -c cbppal.c 

cbfaux.o: cbfaux.c cbfaux.h
	gcc -c cbfaux.c

clean:
	rm *.o

# -c lo que hace es generar el nombre del .o que le hemos dado al nombrarlo
# *.o Borra todos los objetos (forzar a que se vuelva a compilar todo)

# Posiilidad de usar MACROS como si fuesen variables y es exportable
# CC = gcc  Cambiamos el compilador
# $(CC) => Para usarlo
# 
# OBJS = cbppal.o cbfaux.o
# $(OBJS)
# 
# CFLAGS = -c
# $(CFLAGS)
# OPCIONES PARA FLAGS => -DDEBUG (define un DEBUG para controlar precondicones y saber que ha fallado) 



