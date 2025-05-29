#ifndef MATRICES_Y_LISTAS_H
#define MATRICES_Y_LISTAS_H
#include "listaEnlazada.h"

#define COLS    25

typedef float * floatRef;
typedef int * intRef;
typedef char * charRef;

typedef struct matInt {
	int **m;
	int numFil, numCol;
} matInt;

typedef matInt* matIntRef;

matIntRef crearMatInt(int numFil, int numCol, intRef errNum);
int liberarMatInt(matIntRef mat);
int leerMatInt(matIntRef mat, charRef c);
int mostrarMatInt(matIntRef m, charRef c);

// Funcion para pasar una lista enlazada a una matriz
int pasarListaEnlazadaAMatriz(ListaEnlazada raiz, matInt *matriz, int nFilas, int nColumnas);
int pasarMatrizAListaEnlazada(ListaEnlazadaRef raiz, matIntRef matriz);

#endif
