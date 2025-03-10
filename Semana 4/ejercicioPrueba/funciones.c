#include <stdio.h>

static int varGlobExt = 5;
static int varGlobStat = 50; //aquí añadir static precediendo la definición

void funcion(int x)
{
	extern int varGlobMain;
	printf ("Nueva vairbale global desde Main: %d\n", varGlobMain++);
	printf("El parámetro = %d ",x);
	printf("varGlobExt: %d ",varGlobExt++);
	printf("varGlobStat: %d\n",varGlobStat++);
}