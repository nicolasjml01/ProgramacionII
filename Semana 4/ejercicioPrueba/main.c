/*
 *
 * Primero: sin especificadores y sin declarar variable en main.c (tal y como viene) 
 * Segundo: sin especificadores y con iniciación de variables. 
 *            - en funciones.c
 *            - en main.c
 *       Comprobar compilación errores.
 * Tercero: sin especificadores y quitar valores iniciales variable en main.c
 * Cuarto: extern en varGlobExt en main.c
 * Quinto: static en varGlobStat en funciones.c (y en main.c opcional)
 *    Jugar intentando declaraciones extern para intentar acceder
 *    a la variable static. Variaciones.
 * Sexto y último, lo correcto: la declaración extern en funciones.h
 */


// Para que una variable sea global a nivel de fichero se utiliza static

#include <stdio.h>
#include "funciones.h"

// Se considera que son var globales externas, lo mejor es ponerles extern para 
// que sea buenas practicas
int varGlobExt; // Como estan static en el otro lado, se inician a 0
int varGlobStat;
int varGlobMain = 100;

int main()
{
	int i;

	for(i = 0; i < 5; i++){
		funcion(i);
		printf("En main varGlobExt: %d;",varGlobExt++);
		printf(" varGlobStat: %d\n",varGlobStat++);
	}
	return 0;
}









