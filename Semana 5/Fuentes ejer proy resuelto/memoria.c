#include <stdio.h>
#include <stdlib.h>
int *asignar_memoria (long n) {
   int *mem;
   if ( (mem = (int *) calloc(n, sizeof(int))) == NULL )
	 printf("Error reservando memoria.\n");

   return mem;
}



void liberar_memoria (int *la) {
   free(la);    /* Liberamos la memoria reservada anteriormente */
}
