#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define DIMMAX 25

/* Fuente: CVECTOR.C
   Programa: CALCULO VECTORIAL
   Descripción: Pide por pantalla dos vectores (dimensión máxima DIMMAX)
   Posteriormente calcula su módulo, su suma y su producto escalar
*/

int main(void) {

/* Definiciones de variables y constantes
   ---------------------------------------
*/
  float vector1[DIMMAX], vector2[DIMMAX];       /* Vectores de entrada                */
  int diml;                                     /* Dimensión efectiva de los vectores */
  float modulov1, modulov2;                     /* Módulo de los vectores             */
  float vsuma[DIMMAX];                          /* Vector suma                        */
  float prod_escalar;                           /* Producto escalar de los vectores   */

  int i;               /* Variable auxiliar para recorrer los vectores */
  char  terminar;      /* Para pedir al usuario terminar o no          */


/* Presentación del programa
   ---------------------------------------
*/
  system ("cls");  /* Borrado de la pantalla */
  printf("Cálculo vectorial\n");
  printf("=================\n");
  printf("Se pedirán por pantalla dos vectores y se presentará:\n");
  printf("   - El módulo de cada uno de ellos.\n");
  printf("   - Su vector suma.\n");
  printf("   - Su producto escalar.\n");
  printf("El programa permite trabajar con vectores de dimensión "
         "máxima %d.\n", DIMMAX);

  do  /*--1--*/
  {
    /* Petición y validación de datos
       ---------------------------------------
     */
       do
       { printf("Dimensión de los vectores (entre 1 y %d)?: ", DIMMAX);
         scanf("%d", &diml);
       } while (diml <= 0 || diml > DIMMAX);

 
       puts("\nIntroduzca el primer vector:");
       for (i=0; i < diml; i++)
            { printf("v1[%d]?: ", i+1);
              scanf("%f", &vector1[i]);
            }

       puts("\nIntroduzca el segundo vector:");
       for (i=0; i < diml; i++)
            { printf("v2[%d]?: ", i+1);
              scanf("%f", &vector2[i]);
            }

   /* Cálculos
       ---------------------------------------
    */

    /* Módulo
     *	     -----------------------
     *	    /	 2    2          2
     *      \  /	v  + v  + ... + v
     * m =   \/    1    2          n
     *
     */
        modulov1 = modulov2 = 0;
        for (i=0; i < diml; i++)
            { modulov1 += vector1[i] * vector1[i];
              modulov2 += vector2[i] * vector2[i];
            }

        modulov1 = sqrt (modulov1);
        modulov2 = sqrt (modulov2);

    /* Vector suma
     *	        
     *  V1 + V2 = ( v1 + v2 , v1 + v2 , ... , v1 + v2  )
     *                1    1    2    2          n    n
     */
        for (i=0; i < diml; i++)
            vsuma[i] = vector1[i] + vector2[i];

    /* Producto escalar
     *	        
     *  V1 x V2 =  v1 v2 + v1 v2 + ... + v1 v2
     *               1  1    2  2          n  n
     */
        prod_escalar = 0;
        for (i=0; i < diml; i++)
            prod_escalar += vector1[i] * vector2[i];

 
    /* Resultados
       ---------------------------------------
    */
       puts("\nVectores introducidos:");
       printf("V1 = (%g", vector1[0]);
       for (i=1; i < diml; i++)
           printf(", %g", vector1[i]);
       printf(")\n");

       printf("V2 = (%g", vector2[0]);
       for (i=1; i < diml; i++)
           printf(", %g", vector2[i]);
       printf(")\n");

       printf("\n");
       printf("Módulo del primer  vector: %g\n", modulov1);
       printf("Módulo del segundo vector: %g\n", modulov2);

       puts("\nVector suma:");
       printf("V1 + V2 = (%g", vsuma[0]);
       for (i=1; i < diml; i++)
           printf(", %g", vsuma[i]);
       printf(")\n");

       puts("\nProducto escalar:");
       printf("V1 x V2 = %g\n", prod_escalar);

       printf("\n\n");

       do
       {  printf("Salir del programa (S/N)?: "); 
          fflush(stdin);  /* Vaciado del buffer de teclado */
          scanf("%c", &terminar);
          terminar = toupper(terminar);
       } while (terminar != 'S' && terminar != 'N');
        
       system ("cls");  /* Borrado de la pantalla */

  } while (terminar != 'S'); /*--cierre de 1--*/

  return 0;
}
