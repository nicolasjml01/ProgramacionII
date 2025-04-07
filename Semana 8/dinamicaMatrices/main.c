//
//  main.c
//  dinamicaMatrices
//
//  Created by Iván Álvarez Navia on 22/03/13.
//  Copyright (c) 2013 Iván Álvarez Navia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrizBidimensional.h"

int
main (int argc, const char * argv[])
{
	char menu[] = "Suma de matrices: \nA) Leer datos \nB) Sumar matrices \nC) Ver resultados \nD) Liberar matrices \nE) Multiplicar matrices \nF) Vector columna maximo \nQ) Salir";
	char opcion;
    int numFil, numCol,errNum, i;
	floatRef vectorA, vectorB;
    
	matFloatRef A, B, C, D;
    
    A = B = C = D = NULL;
	vectorA = vectorB = NULL;
	do {
		printf("%s ",menu);
        scanf("%c%*c",&opcion);
		opcion = toupper(opcion);
		switch (opcion) {
			case 'A':
                if (A != NULL || B != NULL) {
                    printf("Ya existen matrices ... opciones C o D\n\n");
                    break;
                }
				printf("\n\nDimensiones de las matrices:\n\n");
                printf("Número de filas: ");
                scanf("%d%*c",&numFil);
                printf("Número de columnas: ");
                scanf("%d%*c",&numCol);
                
                printf("Primera matriz: \n");
                if (NULL != (A = crearMatFloat(numFil, numCol, &errNum)))
                    leerMatFloat(A, "Matriz A");
                else
                    printf("Fallo creación matriz: %d\n",errNum);
                
                printf("Segunda matriz: \n");
				if (NULL != (B = crearMatFloat(numFil, numCol, &errNum)))
                    leerMatFloat(B, "Matriz B");
                else
                    printf("Fallo creación matriz: %d\n",errNum);
                break;
			case 'B':
				printf("\n\nSuma...");
                if (NULL != C){
                    liberarMatFloat(C);
                    free(C);
                }
				if (NULL == (C = sumarMatFloat(A, B, &errNum)))
                    printf("... no realizada %d\n",errNum);
                else
                    printf("efectuada.\n\n");
				break;
			case 'C':
				printf("\n\nVisualización de resultados\n\n");
				printf("\n\nPrimera matriz\n\n");
				mostrarMatFloat(A, " %6.2lf ");
				printf("\n\nSegunda matriz\n\n");
				mostrarMatFloat(B, " %6.2lf ");
				printf("\n\nMatriz suma\n\n");
				mostrarMatFloat(C, " %6.2lf ");
				printf("\n\nMatriz multiplicacion\n\n");
				mostrarMatFloat(D, " %6.2lf ");
				printf ("\n\nVector columna máximo matriz A\n\n");
				for (i = 0; i < A->numFil; i++)
				{
					printf ("%6.2lf\n", vectorA[i]);
				}
				printf ("\n\nVector columna máximo matriz B\n\n");
				for (i = 0; i < A->numFil; i++)
				{
					printf ("%6.2lf\n", vectorB[i]);
				}
				break;
			case 'D':
				printf("\n\nLiberación de matrices y vectores...");
				liberarMatFloat(A);
				free(A);
				A = NULL;
				liberarMatFloat(B);
				free(B);
				B = NULL;
				liberarMatFloat(C);
				free(C);
				C = NULL;
				liberarMatFloat(D);
				free(D);
				D = NULL;
				free(vectorA);
				vectorA = NULL;
				free(vectorB);
				vectorB = NULL;
				printf("efectuada.\n\n");
                break;
			case 'E':
				printf("\n\nProducto...");
				if (NULL != D){
					liberarMatFloat(D);
					free(D);
				}
				if (NULL == (D = multiplicarMatFloat(A, B, &errNum)))
					printf("... no realizada %d\n",errNum);
				else
					printf("efectuada.\n\n");
				break;
			case 'F':
				printf("\n\nVector columna máximo matriz A...");
				if (NULL != vectorA){
					free(vectorA);
				}
				if (NULL == (vectorA = obtenerColumnaMaxMatFloat(A, &errNum)))
					printf("... no realizada %d\n",errNum);
				else
					printf("efectuada.\n\n");
					printf("\n\nVector columna máximo matriz B...");
				if (NULL != vectorB){
					free(vectorB);
				}
				if (NULL == (vectorB = obtenerColumnaMaxMatFloat(B, &errNum)))
					printf("... no realizada %d\n",errNum);
				else
					printf("efectuada.\n\n");
				break;
			case 'Q':
				printf("\n\nSaliendo.\n\n");
				break;
			default:
				printf("\n\nOpción incorrecta!\a\n\n");
				break;
		}
	} while ('Q' != opcion);
	printf("\n\nTerminación normal del programa.\n\n");
    return 0;
}


