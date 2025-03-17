/* Fuente: TESTORD.C
   Programa ORDENACION DE VECTORES
   Realiza ordenaciones de vectores de enteros, de longitudes cada vez 
   mayores, por distintos algoritmos, y compara tiempos.
*/

#include <stdio.h>
#include <stdlib.h>
#include "metodos.h"
#include "auxi.h"
#include "memoria.h"

void pedir_datos (long *, long *, char *);
void presentacion(void);

int main(void)
{
   int *vector;
   int *vector_original;

   long tope, puntos_muestreo, incremento;
   char tipo_inicio_vector;
   long veces;

   long t_burbuja;
   long t_insercion;
   long t_seleccion;

   presentacion();
   pedir_datos (&tope, &puntos_muestreo, &tipo_inicio_vector);

   incremento = tope / puntos_muestreo;

   system ("cls");
   printf("\n");
   printf("METODOS DE ORDENACION\n");
   printf("dim vector ord ini   burbuja inserción selección\n",
	    "---------- ------- --------- --------- ---------\n");
   for (veces=incremento; veces <= tope; veces+=incremento)
   {
      /* Reservamos memoria para el vector                  */
      if ( (vector = asignar_memoria(veces)) == NULL)
	   return 1;

      /* Reservamos un segundo bloque del mismo tamaño para */
      /* guardar el vector primitivo desordenado y que todos*/
      /* algoritmos ordenen el mismo vector.                */
      if ( (vector_original = asignar_memoria(veces)) == NULL)
	   return 1;
      
 
      /* Iniciamos con valores el vector a ordenar.         */
      /* El tercer parámetro indica que tipo de iniciación  */
      /* deseamos: ordenada de forma ascendente, de forma   */
      /* descendente o cargada con valores aleatorios.      */
       iniciar (veces, vector, tipo_inicio_vector);

      /* Guardamos el vector recién cargado en el           */
      /* vector_original. La función duplicar copia desde   */
      /* vector origen a vector destino un número dado de   */
      /* elementos: duplicar (n.elem., lorigen, ldestino)   */
      duplicar (veces, vector, vector_original);
      t_burbuja = ordena_burbuja (veces, vector);

      duplicar (veces, vector_original, vector);
      t_insercion = ordena_insercion (veces, vector);

      duplicar (veces, vector_original, vector);
      t_seleccion = ordena_seleccion (veces, vector);


      liberar_memoria(vector);
      liberar_memoria(vector_original);


      /* Salida de datos */
      printf("%9ld %7c %9ld %9ld %9ld\n",
	     veces, tipo_inicio_vector,
	     t_burbuja, t_insercion, t_seleccion);
   }

   printf("\n");
   system ("pause");
   return 0;
}


void presentacion (void)
{
  system ("cls");
  printf("COMPARATIVA DE LOS METODOS BASICOS DE ORDENACION\n");
  printf("------------------------------------------------\n");
  printf("Este programa es capaz de medir los tiempos de ");
  printf("ejecución de los algoritmos\n");
  printf("básicos de ordenación para vectores de distintos ");
  printf("tamaños.\n");
  printf("\n");
  printf("El programa pedirá varios datos de entrada:\n");
  printf("(1) (long) Longitud máxima del vector a ordenar\n");
  printf("(2) (long) Número de puntos de muestreo a presentar\n");
  printf("(3) (char) Tipo de iniciación del vector\n");
  printf("	     a)    ascendente\n");
  printf("	     d)    descendente\n");
  printf("	     otro) aleatorio\n");
  printf("\n");
  printf("Ver enunciado del problema para más información\n");

  printf("\n");
  system ("pause");
}


void pedir_datos (long *tp, long *pm, char *ord)
{
   system ("cls");
   printf ("\n");

   printf ("Longitud máxima vector a ordenar: ");
   scanf ("%ld", tp);

   printf ("\n");
   do
   { printf ("Número de puntos de muestreo a presentar (max %ld): ",
              *tp/10);
     scanf ("%ld", pm);
   } while (*pm <= 0 || *pm > *tp);

   printf ("\n");
   printf ("Tipo de iniciación del vector\n");
   printf (" a)    ascendente\n");
   printf (" d)    descendente\n");
   printf (" otro) aleatorio\n");
   fflush(stdin);
   scanf ("%c", ord);
}

