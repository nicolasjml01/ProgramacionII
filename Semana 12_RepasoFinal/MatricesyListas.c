#include <stdio.h>
#include <stdlib.h>
#include "MatricesyListas.h"

matIntRef crearMatInt(int numFil, int numCol, intRef errNum)
{
    if (numFil <= 0 || numCol <= 0){
        *errNum = -1;
        return NULL;
    }
    matIntRef mat;
    int i, j;

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

    for (i = 0; i < numFil; i++)
    {
        if((mat->m[i] = malloc(sizeof(numCol * sizeof(int)))) == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(mat->m[i]);
            }
            free(mat->m);
            free(mat);
            *errNum = -2;
            return NULL;
        }
    }

    mat->numFil = numFil;
    mat->numCol =numCol;
    *errNum = 0;

    return mat;
}

int liberarMatInt(matIntRef mat)
{
    int i;

    for (i = 0; i < mat->numFil; i++)
    {
        free(mat->m[i]);
    }
    free(mat->m);
    mat->m = NULL;
    mat->numCol = mat->numFil = -1;
    return 0;
}

int leerMatInt(matIntRef m, charRef c)
{
    int i, j;

    for (i = =; i < m->numFil; i++)
    {
        for (j = 0; j < m->numCol; j++)
        {
            printf("m[%d][%d]: ", i, j);
            scanf ("%d%*c", &mat->m[i][j]);
        }
    }

    return 0;

}   

int mostrarMatInt(matIntRef mat, charRef c)
{
    int i,j;
	
    if (C == NULL) {
        c = " %g ";
    }
    for (i = 0; i < mat->numFil; i++) {
        printf("| ");
        for (j = 0; j < mat->numCol; j++) {
            printf(c,mat->m[i][j]);
        }
        printf(" |\n");
    }
    return 0;
}

