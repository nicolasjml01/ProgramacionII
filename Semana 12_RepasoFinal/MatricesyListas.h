#ifndef MATRICES_Y_LISTAS_H
#define MATRICES_Y_LISTAS_H

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
int leerMatInt(matIntRef m, charRef c);
int mostrarMatInt(matIntRef m, charRef c);


#endif
