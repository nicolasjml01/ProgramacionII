//
//  matrizBidimensional.c
//  dinamicaMatrices
//
//  Created by Iván Álvarez Navia on 22/03/13.
//  Copyright (c) 2013 Iván Álvarez Navia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "matrizBidimensional.h"



matFloatRef
crearMatFloat(int numFil, int numCol, intRef errNum)
{
	matFloatRef temp;
	if (!(numFil > 0 && numCol > 0)) {
#ifdef DEBUG
        fprintf(stderr, "Error: dimensiones incorrectas: %d, %d\n",numFil,numCol);
#endif
        *errNum = -1;
        return NULL;
	}
	if (NULL == (temp = malloc(sizeof(matFloat)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallor reserva memoria tipo matriz\n");
#endif
        *errNum = -2;
        return NULL;
    }
    else if (NULL == (temp->m = malloc(numFil*numCol*sizeof(float)))){ 
#ifdef DEBUG
        fprintf(stderr, "Error: fallor reserva memoria matriz\n");
#endif
        free(temp);
        *errNum = -3;
        return NULL;
    }
    else {
        temp->numFil = numFil;
        temp->numCol = numCol;
        *errNum = 0;
        return temp;
    }
}



matIntRef
crearMatInt(int numFil, int numCol, intRef errNum)
{
	matIntRef temp;
	if (!(numFil > 0 && numCol > 0)) {
#ifdef DEBUG
        fprintf(stderr, "Error: dimensiones incorrectas: %d, %d\n",numFil,numCol);
#endif
        *errNum = -1;
        return NULL;
	}
	if (NULL == (temp = malloc(sizeof(matInt)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallo reserva memoria tipo matriz\n");
#endif
        *errNum = -2;
        return NULL;
    }
    else if (NULL == (temp->m = malloc(numFil*numCol*sizeof(int)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallo reserva memoria matriz\n");
#endif
        free(temp);
        *errNum = -3;
        return NULL;
    }
    else {
        temp->numFil = numFil;
        temp->numCol = numCol;
        *errNum = 0;
        return temp;
    }
}

int
fallaMatrizFloat(matFloatRef mat)
{
    if (mat == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: referencia tipo matriz\n");
#endif
        return -1;
    }
    if (mat->numFil <= 0 || mat->numCol <=0 || mat->m == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: matriz mal construida\n");
#endif
        return -2;
    }
    return 0;
}

int
fallaMatrizInt(matIntRef mat)
{
    if (mat == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: referencia tipo matriz\n");
#endif
        return -1;
    }
    if (mat->numFil <= 0 || mat->numCol <=0 || mat->m == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: matriz mal construida\n");
#endif
        return -2;
    }
    return 0;
}

int
leerMatFloat(matFloatRef mat, charRef c)
{
    int i,j,res;
	
	if (!(res = fallaMatrizFloat(mat))) {
        if (NULL == c)
            c = "m";
        for (i=0; i < mat->numFil; i++) {
            for (j=0; j < mat->numCol; j++) {
                printf("%s[%d][%d] = ",c,i,j);
                scanf("%f%*c",&(mat->m[i * mat->numCol + j]));
                //scanf("%f%*c",mat->m + i * mat->numCol + j);
            }
        }
        return 0;
    }
    else
        return res;
}

int
leerMatInt(matIntRef mat, charRef c)
{
    
    int i,j,res;
	
	if (!(res = fallaMatrizInt(mat))) {
        if (NULL == c)
            c = "m";
        for (i=0; i < mat->numFil; i++) {
            for (j=0; j < mat->numCol; j++) {
                printf("%s[%d][%d] = ",c,i,j);
                scanf("%d%*c",&(mat->m[i * mat->numCol + j]));
                //scanf("%d%*c",mat->m + i * mat->numCol + j);
            }
        }
        return 0;
    }
    else
        return res;
}


int
mostrarMatFloat(matFloatRef mat, charRef c)
{
    int res,i,j;
	
    if (!(res = fallaMatrizFloat(mat))) {
        if (NULL == c) {
            c = " %g ";
        }
        for (i = 0; i < mat->numFil; i++) {
            printf("| ");
            for (j = 0; j < mat->numCol; j++) {
                printf(c,mat->m[i*mat->numCol+j]);
                //printf(c,*(mat->m + i*mat->numCol + j));
            }
            printf(" |\n");
        }
        return 0;
    }
	else
        return res;
}



int
mostrarMatInt(matIntRef mat, charRef c)
{
    int i,j,res;
	
    if (!(res = fallaMatrizInt(mat))) {
        if (NULL == c) {
            c = " %g ";
        }
        for (i = 0; i < mat->numFil; i++) {
            printf("| ");
            for (j = 0; j < mat->numCol; j++) {
                printf(c,mat->m[i*mat->numCol+j]);
                //printf(c,*(mat->m + i*mat->numCol + j));
            }
            printf(" |\n");
        }
        return 0;
    }
    else
        return res;
}


int
liberarMatFloat(matFloatRef mat)
{
    int res;
    
	if (!(res = fallaMatrizFloat(mat))) {
        free(mat->m);
        mat->m = NULL;
        mat->numFil = -1;
        mat->numCol = -1;
        return 0;
    }
	else
        return res;
}

int
liberarMatInt(matIntRef mat)
{
    int res;
    
	if (!(res = fallaMatrizInt(mat))) {
        free(mat->m);
        mat->m = NULL;
        mat->numFil = -1;
        mat->numCol = -1;
        return 0;
    }
	else
        return res;
}

matFloatRef
sumarMatFloat(matFloatRef a, matFloatRef b, intRef errNum)
{
	int i, j, totalElements, res;
    matFloatRef c;
    
    if (!(res =fallaMatrizFloat(a)) && !(res = fallaMatrizFloat(b))) {
        if (!(a->numFil == b->numFil && a->numCol == b->numCol)) {
#ifdef DEBUG
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (c = crearMatFloat(a->numFil, a->numCol, &res))) {
                /* // Los trata como vectores
                totalElements = a->numFil * a->numCol;
                for (i=0; i<totalElements; i++) {
                    c->m[i] = a->m[i] + b->m[i];
                }*/
               // Tratamos como se haria con matrices
               for (i = 0; i < c->numFil; i++)
               {
                    for (j = 0; j < c->numCol; j++)
                    {
                        c->m[i * c->numCol + j] = a->m[i * a->numCol + j] + b->m[i * b->numCol + j];
                    }
               }
                *errNum = 0;
                return c;
            }
            else {
                *errNum = res;
                return NULL;
            }
        }
	}
    else {
        *errNum = res;
        return NULL;
    }
}

matIntRef
sumarMatInt(matIntRef a, matIntRef b, intRef errNum)
{
	int i, totalElements, res;
    matIntRef c;
    
    if (!(res =fallaMatrizInt(a)) && !(res = fallaMatrizInt(b))) {
        if (!(a->numFil == b->numFil && a->numCol == b->numCol)) {
#ifdef DEBUG
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (c = crearMatInt(a->numFil, a->numCol, &res))) {
                totalElements = a->numFil * a->numCol;
                for (i=0; i<totalElements; i++) {
                    c->m[i] = a->m[i] + b->m[i];
                }
                return 0;
            }
            else {
                *errNum = res;
                return NULL;
            }
        }
	}
    else {
        *errNum = res;
        return NULL;
    }
}

matFloatRef
multiplicarMatFloat(matFloatRef a, matFloatRef b, intRef errNum)
{
	int i, j, k, totalElements, res;
    matFloatRef c;
    
    if (!(res =fallaMatrizFloat(a)) && !(res = fallaMatrizFloat(b))) {
        // El numero de columnas de A debe coincidir con el numero de filas de B
        if (!(a->numCol == b->numFil)) {
#ifdef DEBUG
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (c = crearMatFloat(a->numFil, a->numCol, &res))) {
                /* // Los trata como vectores
                totalElements = a->numFil * a->numCol;
                for (i=0; i<totalElements; i++) {
                    c->m[i] = a->m[i] + b->m[i];
                }*/
               // Tratamos como se haria con matrices
               for (i = 0; i < c->numFil; i++)
               {
                    for (j = 0; j < c->numCol; j++)
                    {
                        c->m[i*c->numCol+j] = 0.0;
                        //for (k = 0; k < b->numFil; k++) // Ambas valen
                        for (k = 0; k < a->numCol; k++){
                            c->m[i*c->numCol+j] += a->m[i*a->numCol+k] * b->m[k*b->numCol+j];
                        }
                    }
               }
                *errNum = 0;
                return c;
            }
            else {
                *errNum = res;
                return NULL;
            }
        }
	}
    else {
        *errNum = res;
        return NULL;
    }
}

// Funcion Obtener Máximo
float *obtenerColumnaMaxMatFloat(matFloatRef mat, intRef errNum)
{
    floatRef vector;
    float max;
    int i, j, jMax;

    if (!(*errNum =fallaMatrizFloat(mat))) {
        // Matriz mat bien construida (res() devuelve 0, es decir, !0 es 1)
        if ((vector = malloc (mat->numFil*sizeof(float))) == NULL)
        {
#ifdef DEBUG
            fprintf(stderr, "Error: reserva de memoria\n\n");
#endif
            *errNum = -5;
            return NULL;
        }else
        {
            max = mat->m[0 * mat->numCol + 0]; // max = mat->m[0];
            jMax = 0;
            for (j = 0; j < mat->numCol; j++)
            {
                for (i = 0; i < mat->numFil; i++)
                {
                    if (mat->m[i * mat->numCol + j] >= max)
                    {
                        max = mat->m[i * mat->numCol + j];
                        jMax = j;
                    }
                }
            }
            for (i = 0; i < mat->numFil; i++)
            {
                vector[i] = mat->m[i * mat->numCol * jMax];
            }
            *errNum = 0;
            return vector;
        }
    }else {
        // Matriz mat mal construida (res() devuelve -1 o -2)
        return NULL;
    }
}



