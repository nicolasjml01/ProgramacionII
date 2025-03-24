/* Probar su correcto funcionamiento es necesario cargar la información de los registros. Me dio palo*/
#include <stdio.h>
#include <stdlib.h> 

int calcularCalificaciones(estudiante *estudiantes, int numEstudiantes, float *calificacionesFinales, float *promedioPruebas, int *numAprobados);

#define NUM_EVA_CONT 5
#define NUM_ESTUDIANTES 300
int main (void)
{
    estudiante vectorEstudiantes[NUM_ESTUDIANTES];
    float calificacionesFinales[NUM_ESTUDIANTES];
    flaot promedioPruebas[NUM_EVA_CONT];
    int numEstudiantes, numAprobados;

    // **Apartado C -> Lo ponemos antes porque lo necesitamos**
    int resultado = calcularCalificaciones(vectorEstudiantes, numEstudiantes, calificacionesFinales, promedioPruebas, &numAprobados);

    return 0;
}

// Apartado A
typedef struct tipoEstudiante
{
    char nombre[80];
    char dni[10];
    float pruebasContinua[NUM_EVA_CONT];
    float calificacionExamenFinal;
}estudiante;

// Apartado B
int calcularCalificaciones(estudiante *estudiantes, int numEstudiantes, float *calificacionesFinales, float *promedioPruebas, int *numAprobados)
{
    if (estudiantes == NULL)
    {
        perror("El vector de estudiantes es NULL");
        return -1;
    }

    if (numEstudiantes <= 0 || numEstudiantes > NUMESTUDIANTES)
    {
        perror("El numero de estudiantes no es valido");
        return -2;
    }

    if (calificacionesFinales == NULL || promedioPruebas == NULL || numAprobados == NULL)
    {
        perror("Alguno de los punteros pasados por valor es NULL");
        return -3;
    }

    int i,j;
    float mediaNotaContinua;
    *numAprobados = 0;
    for (i = 0; i < numEstudiantes; i++)
    {
        mediaNotaContinua = 0.0;
        for (j = 0; j < NUM_EVA_CONT; j++)
        {
            mediaNotaContinua += estudiantes[i].pruebasContinua[j];
        }
        mediaNotaContinua = mediaNotaContinua / NUM_EVA_CONT;
        // Calcular su nota final
        calificacionesFinales[i] = mediaNotaContinua * 0.5 + estudiantes[i].calificacionExamenFinal * 0.5;
        if (calificacionesFinales >= 5) (*numAprobados)++;
    }

    // Haremos este apartado de la 2 manera utilizando ya la variable dad
    for (j = NUM_EVA_CONT; j++)
    {
        promedioPruebas[j] = 0.0;
        for (i = 0; i < numEstudiantes; i++)
        {
            promedioPruebas[j] += estudiantes[i].pruebasContinua[j];
        }

        promedioPruebas[j] /= numEstudiantes;
    }

    return 0;
}
