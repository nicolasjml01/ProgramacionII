/* Fuente: MALLOC1.C
Programa: GENERACION DE UN VECTOR EN MEMORIA DINAMICA CON MALLOC
Descripción: Se hace un estudio de las posiciones de memoria donde se almacenan los datos
estáticos y las variables generadas con reserva de memoria dinámica.
*/

#include <stdio.h>
#include <stdlib.h>
#define N 8

int main(void) 
{
	int vx[N] = {0};
	int i, j;
	int *ptr;
	int (*ptr2)[4];

	system ("clear");

	puts("VECTOR CREADO CON MALLOC");
	puts("========================");
	puts("");
	puts("Estudio de las posiciones de memoria donde se almecenan los datos estáticos");
	puts("y las variables generadas con reserva de memoria dinámica.");
	puts("");

	if ( (ptr = malloc(N*sizeof(int))) == NULL ){ 
		printf ("Error reservando memoria\n");
		return -1;
	}
	else { 
		puts ("Variables estáticas:");
		puts ("    int vx[N] = {0};  N=5");
		puts ("    int i;          ");
		puts ("    int *ptr;       ");
		puts ("    int (*ptr2)[4])  ");
		puts ("                    ");
		printf("Dirección último elemento de vx: %p \n", vx+(N-1));
		printf("Dirección comienzo de vx.......: %p \n", vx);
		printf("Dirección de i.................: %p \n", &i);
		printf("Dirección de ptr...............: %p \n", &ptr);
		printf("Dirección de ptr2..............: %p \n", &ptr2);

		printf("Dirección último elemento vector dinámico ptr: %p \n", ptr+(N-1));
		printf("Dirección comienzo vector dinámico ptr.......: %p \n", ptr);

		printf("\n\n");
		printf("Carga del vector dinámico:\n");

		for (i = 0; i < N; i++){ 
			//printf("Elemento %d: ", i+1);
			//scanf ("%d", ptr+i);
			//scanf("%d", &(*(ptr + i)));
			//scanf("%d", &ptr[i]);
			ptr[i] = i;
			//*(ptr + i) = i;
		}

		printf("\n\n");
		printf("El vector es: %p\n", ptr);
		for (i = 0; i < N; i++){
			//printf("%5d", *(ptr+i));
			printf("%5d", ptr[i]);
		}
		
		ptr2 = (int (*)[4])ptr;
		
		printf("\n\n");
		printf("La matriz bidimensional es: %p\n", ptr2);
		
		for (i = 0; i < 2; i++){
			printf("|");
			for (j = 0; j < 4; j++){
				//printf("%5d", *(*(ptr2 + i) + j));  
				printf("%5d", ptr2[i][j]);
			}
			printf("|\n");
		}
   
		free(ptr);
		ptr = NULL;
		ptr2 = NULL;
   
		printf ("\n\n");

		return 0;
	}
}
