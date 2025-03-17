#include <stdio.h>
#include <time.h>

#define CIERTO 1
#define FALSO  0

long ordena_burbuja (long dim, int *la)
/*--------------------------------------------------------------*/
/* Ordenamos por el método de la burbuja una vector de enteros. */
/*--------------------------------------------------------------*/
{
  int  cambio;
  long pasadas, k;
  clock_t ini, fin;
  int temp;  /* Mismo tipo que el de los elementos del vector */

  ini=clock();
  pasadas = 1;
  cambio  = CIERTO;

  while ( (pasadas <= dim-1) && cambio)
  { cambio = FALSO;
    for (k=0; k <= dim-1 - pasadas; k++)
       if(la[k] > la[k+1])   /* <----- ORDEN ASCENDENTE */
	 {
	  temp    = la[k];
	  la[k]   = la[k+1];
	  la[k+1] = temp;
	  cambio  = CIERTO;
	 }
    pasadas++;
  }

  fin=clock();
  return ( (fin-ini)/CLK_TCK) ;
}


long ordena_insercion (long dim, int *la)
/*--------------------------------------------------------------*/
/* Ordenamos por el método de inserción un vector de enteros.   */
/*--------------------------------------------------------------*/
{
   int  encontrado;
   long k, j, nuevaposicion;
   int  temp;  /* Mismo tipo que el de los elementos del vector */
   clock_t ini, fin;

   ini=clock();

   for (k=1; k < dim; k++)
   { temp = la[k];
     encontrado = FALSO;
     j = k;
     while ( (j > 0) && !encontrado )
      { if ( la[j-1] > temp )
	   { la[j] = la[j-1];
	     j--;
	   }
	  else  encontrado = CIERTO;
      }
     nuevaposicion = j;

     la[nuevaposicion] = temp;
   }

   fin=clock();
   return ( (fin-ini)/CLK_TCK);
}


 
long ordena_seleccion (long dim, int *la)
/*--------------------------------------------------------------*/
/* Ordenamos por el método de selección un vector de enteros.   */
/*--------------------------------------------------------------*/
{
   long mayor, k, j;
   int  temp;  /* Mismo tipo que el de los elementos del vector */
   clock_t ini, fin;

   ini=clock();
   for (k=dim-1; k >= 1; k--)
   {   mayor = 0;
       for (j = 1; j <= k; j++)
	   if (la[j] > la[mayor])
	      mayor = j;
 
       temp      = la[mayor];
       la[mayor] = la[k];
       la[k]     = temp;
   }

   fin=clock();
   return ( (fin-ini)/CLK_TCK);
}
