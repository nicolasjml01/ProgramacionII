#include <stdio.h>
#include <stdlib.h>
#include "matricesyListas.h"
#include "listaEnlazada.h"

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

int leerMatInt(matIntRef mat, charRef c)
{
    int i, j;

    if (NULL == c)
        c = "m";
    for (i = 0; i < mat->numFil; i++)
    {
        for (j = 0; j < mat->numCol; j++)
        {
            printf("%s[%d][%d]: ", c, i, j);
            scanf ("%d%*c", &(mat->m[i][j]));
        }
    }

    return 0;

}   

int mostrarMatInt(matIntRef mat, charRef c)
{
    int i,j;
	
    if (c == NULL) {
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

int pasarListaEnlazadaAMatriz(ListaEnlazada raiz, matInt *matriz, int nFilas, int nColumnas)
{
    if (nFilas <= 0 || nColumnas <= 0 || raiz == NULL || matriz == NULL) return -1;
    
    int i, j, resultado = 0;

    // Ya se encuentra reservada la memoria para la estructura, por lo tanto solo es necesario reservar para las filas y columnas
    if((matriz->m = malloc(nFilas * sizeof(int *))) == NULL) return -2;
    
    for (i = 0; i < nFilas; i++)
    {
        if ((matriz->m[i] = malloc(nColumnas * sizeof(int))) == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(matriz->m[i]);
            }
            free(matriz->m);
            matriz->m = NULL;
            matriz->numFil = matriz->numCol = -1;
            return -2;
        }
    }
    matriz->numCol = nColumnas;
    matriz->numFil = nFilas;

    /* 
    CASOS cuando paso la lista a la matriz
        1) La matriz se llena pero a la lista le quedan valores. Se devuelve 0
        2) La lista se vacia pero la matriz aun tiene espacios disponibles. Se devuelve 1
        3) Coinciden el numero de valores de la lista con los de la matriz. Se devuelve 2
    */

    for (i = 0; i < nFilas; i++)
    {
        for (j = 0; j < nColumnas; j++)
        {
            if (raiz != NULL) // Caso 1
            {
                matriz->m[i][j] = raiz->info;
                raiz =  raiz->sig;
            }else // Caso 2
            {
                matriz->m[i][j] = 0;
                resultado = 1;
            }
        }
    }

    if (raiz != NULL) resultado = 2;

    return resultado;    
}

int pasarMatrizAListaEnlazada(ListaEnlazadaRef raiz, matIntRef matriz)
{
    if (raiz == NULL || matriz == NULL) return -1;

    int i, j;
    tipoNodoRef nuevo, anterior, actual;

    for (i = 0; i < matriz->numFil; i++)
    {
        for (j = 0; j < matriz->numCol; j++)
        {
            if ((nuevo =  malloc(sizeof(tipoNodo))) == NULL) return -2;
            nuevo->info = matriz->m[i][j];
            nuevo->sig = NULL;

            if (nuevo->info > 0)
            {
                if (*raiz == NULL || (*raiz)->info > nuevo->info)
                {
                    nuevo->sig = *raiz;
                    *raiz = nuevo;
                }else
                {
                    anterior = *raiz;
                    actual = (*raiz)->sig;
                    while (actual != NULL && actual->info < nuevo->info)
                    {
                        anterior = actual;
                        actual = actual->sig;
                    }
                    nuevo->sig = anterior->sig;
                    anterior->sig = nuevo;
                }
            }
        }
    }
    return 0;
}
