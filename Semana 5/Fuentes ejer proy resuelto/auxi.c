#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void mostrar (long dim, int *la)
/*-------------------------------------------------*/
/* Mostramos el vector ‘la’ de enteros en pantalla */
/*-------------------------------------------------*/
{ long i;
  for (i = 0; i < dim; i++)
       printf("%8d", la[i]);
}


void iniciar (long dim, int *la, char ord)
/*-------------------------------------------------*/
/* Cargamos el vector ‘la’ con números aleatorios  */
/* El parámetro ord indica:                        */
/*  a   : cargar ordenado de forma ascendente      */
/*  d   : cargar ordenado de forma descendente     */
/*  otro: cargar de forma aleatoria                */
/*-------------------------------------------------*/
{ long i;
  
  srand (time (0));  /* En otros compiladores randomize(); */
 

  if (ord == 'a')
     for (i = 0; i < dim; ++i)
	 { if ( (i+1) > INT_MAX )
	        la[i] = INT_MAX;
	   else la[i] = (int) i+1;
	 }
  else
  if (ord == 'd')
     for (i = 0; i < dim; ++i)
	 { if ( (dim-i) > INT_MAX )
	        la[i] = INT_MAX;
	   else la[i] = (int) dim-i;
	 }
  else
     for (i = 0; i < dim; ++i)
	 la[i] = rand();
}


void duplicar (long dim, int *ldesde, int *lhasta)
/*----------------------------------------------*/
/* Cargamos todos los elementos del vector      */
/* ldesde en el vector lhasta.                  */
/*----------------------------------------------*/
{ long i;

  for (i = 0; i < dim; i++)
       lhasta[i] = ldesde[i];
}
