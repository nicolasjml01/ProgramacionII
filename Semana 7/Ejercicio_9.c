#include <stdio.h>
#include <stdlib.h>

int * concatenarVectores(int *vi, int dim1, int *v2, int dim2);
void concatenarVectores2(int *v1, int dim1, int *v2, int dim2, int **v3);

int main (void)
{
    int vector1[] = {2,3}, vector2[] = {3,4,5}, dim1 = 2, dim2 = 3;
    int *vector3, i;

    //vector3 = concatenarVectores(vector1, dim1, vector2, dim2);
    // Otra opcion es
    concatenarVectores(int *v1, int dim1, int *v2, int dim2, &vector3);


    for (i = 0; i < dim1 + dim2; i++)
    {
        printf ("%d ", vector3[i]);
    }
    printf ("\n");

    free(vector3);
    return 0;
}

int * concatenarVectores(int *v1, int dim1, int *v2, int dim2)
{
    int *v3;

    //v3 = calloc (dim1+dim2, sizeof(int)); // Otra forma de hacerlo
    if ((v3 = malloc ((dim1+dim2) * sizeof(int))) == NULL) // Esto siempre devuelve un * a itipo de dato sizeof
    {
#ifdef DEBUG
        fprintf(stderr, "\nERROR en reserva de memoria\n");
#endif
        return NULL;
    }
    int i;

    for (i = 0; i < dim1; i++)
    {
        v3[i] = v1[i];
    }
    for (i = 0; i < dim2; i++)
    {
        v3[dim1+i] = v2[i];
    }

    return v3;
}

void concatenarVectores2(int *v1, int dim1, int *v2, int dim2, int **v3)
{

    //v3 = calloc (dim1+dim2, sizeof(int)); // Otra forma de hacerlo
    if ((*v3 = malloc ((dim1+dim2) * sizeof(int))) == NULL) // Esto siempre devuelve un * a itipo de dato sizeof
    {
#ifdef DEBUG
        fprintf(stderr, "\nERROR en reserva de memoria\n");
#endif
    }

    int i;

    for (i = 0; i < dim1; i++)
    {
        (*v3)[i] = v1[i];
    }
    for (i = 0; i < dim2; i++)
    {
        (*v3)[dim1+i] = v2[i];
    }

}

