#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NNODOS 12
#define NFIL 3
#define NCOL 4

typedef int tipoInfo;

typedef struct tipoNodo{
    tipoInfo info;
    struct tipoNodo *sig;
} tipoNodo;

typedef struct matInt{
    int **m;
    int numFil, numCol;
}matInt;

typedef tipoNodo * ListaEnlazada;
typedef ListaEnlazada * ListaEnlazadaRef;

int pasarListaEnlazadaAMatriz(ListaEnlazada raiz, matInt *matriz, int nFilas, int nColumnas);

int main(void)
{
    int salida, i, j;
    ListaEnlazada lista, indice, nuevo;
    matInt mat;
    lista = indice = nuevo = NULL;

    for(i = 0; i < NNODOS; i++)
    {
        if ((nuevo = malloc(sizeof(tipoNodo))) == NULL)
        {
            return -1;
        }
        nuevo->info = random()%1000;
        nuevo->sig = lista;
        lista = nuevo;
    }

    salida = pasarListaEnlazadaAMatriz(lista, &mat, NFIL, NCOL);

    if (salida >= 0){
        printf("Valor devuelto por la funcion: %d\n", salida);
        for (i = 0; i < mat.numFil; i++){
            for (j = 0; j < mat.numCol; j++){
                printf("%d ", mat.m[i][j]);
            }
            printf("\n");
            free(mat.m[i]);
        }
        free(mat.m);
        mat.m = NULL;
        mat.numFil = mat.numCol = -1;
    }
    while(lista != NULL)
    {
        indice = lista;
        lista=lista->sig;
        free(indice);
    }
    return 0;
}

int pasarListaEnlazadaAMatriz(ListaEnlazada raiz, matInt *matriz, int nFilas, int nColumnas)
{
    int i, j, salida = 0;
    //ListaEnlazada indice; // No sería necesario, podemos usar raiz para recorrer la lista
    if (matriz == NULL || nFilas <= 0 || nColumnas <= 0)
    {
        return -1;
    }

    if((matriz->m = malloc(nFilas * sizeof(int *))) == NULL)
    {
        return -2;
    }
    for (i = 0; i < nFilas; i++){
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
    matriz->numFil = nFilas;
    matriz->numCol = nColumnas;
    //indice = raiz;

    for(i = 0; i < matriz->numFil; i++)
    {
        for (j = 0; j < matriz->numCol; j++)
        {
            if (raiz != NULL) //if (indice != NULL) 
            {
                matriz->m[i][j] = raiz->info;
                //indice = indice->sig;
                raiz = raiz->sig;
            }else{
                matriz->m[i][j] = 0;
                salida = 1;
            }
        }
    }

    // Comprobar si todavia me quedan nodos por copiar en la lista
    if (raiz != NULL) salida = 2;

    return salida;
}