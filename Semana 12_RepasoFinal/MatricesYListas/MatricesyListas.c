#include "MatricesyListas.h"

matIntRef crearMatInt(int numFil, int numCol, intRef errNum)
{
    if (numFil <= 0 || numCol <= 0){
        *errNum = -1;
        return NULL;
    }
    matIntRef mat;

    if((mat = malloc (sizeof(matInt))) == NULL)
    {
        *errNum = -2;
        return NULL;
    } 

    if ((mat->m = malloc(numFil * sizeof(int *))) == NULL)
    {
        *errNum = -2;
        return NULL;
    }

    for (int i = 0; i < numFil; i++)
    {
        
    }

}

int liberarMatInt(matIntRef mat)
{

}

int leerMatInt(matIntRef m, charRef c)
{

}

int mostrarMatInt(matIntRef m, charRef c)
{

}

matIntRef sumarMatInt(matIntRef a, matIntRef b, intRef errNum)
{

}