#include <stdio.h>
#include <stdlib.h>

/* Apartado 1 -> crear el struct */
#define NUM_MESES 12

typedef struct tipoVivienda
{
    string idCastro[21];
    string propietario[80];
    char direccion[128];
    float superficie;
    float consumos[NUM_MESES];
} vivienda;

/* Apartado 2 -> Implementar la funcion de procesarConsumos*/
#define NUM_VIVIENDAS 25

int procesarConsumos(vivienda *viviendas, int numV, float *conMedioViviendas, float *conMaxViviendas, float *conMedioMeses, float *conMaxMeses)
{
    /* Todos estos valores tiene ya la información cargada */
    /*
        viviendas -> vector de viviendas de tipo structura
        numV -> tamaño del vector de viviendas
        conMedioViviendas, conMaxViviendas, conMedioMeses, conMaxMeses -> a calcular    
    */
   
    // Precondiciones
    if (viviendas == NULL)
    {
        perror("ERROR, el valor de la structura esta vacio");
        return -1;
    }

    if (numV <= 0 || numV > NUM_VIVIENDAS)
    {
        perror("ERROR, el numero de viviendas no es valido");
        return -2;
    }

    if (conMedioViviendas == NULL || conMaxViviendas == NULL || conMedioMeses == NULL || conMaxMeses == NULL)
    {
        perror("ERROR con los valores pasados por referencia");
        return -3;
    }

    // Calculamos el consumo medio y el maximo de cada vivienda
    int i,j;

    // Con este bucle recorrere todas las viviendas y obtendre sus consumos maximos
    for (i = 0; i < numV; i++)
    {
        conMedioViviendas[i] = 0.0; // Porsi lo igualo a 0
        conMaxViviendas[i] = viviendas[i].consumos[0]; // Para la comparación el primer mes de cada vivienda será el maximo inicial
        // Con este bucle podremos obtener el consumo max de cada vivienda
        for (j = 0; j < NUM_MESES; j++)
        {
            if (conMaxViviendas[i] < viviendas[i].consumos[j])
            {
                conMaxViviendas[i] = viviendas[i].consumos[j]; // El valor del mes j pasa a ser el nuevo maximo
            }
            conMedioViviendas[i] += viviendas[i].consumos[j];
        }
        conMedioViviendas[i] = conMedioViviendas[i]/NUM_MESES;
    }

    // Calculamos el consumo medio de cada mes y el consumo maximo de cada mes de entre todas las viviendas
    // Con este bucle queremos ir obteniendo la media de consumo de cada mes
    for (j = 0; j < NUM_MESES; j++)
    {
        conMedioMeses[j] = 0.0; // Porsi lo ponemos a 0
        conMaxMeses[j] = viviendas[0].consumos[j]; // Hacemos que la primera vivienda empieze siendo el máximos
        // Con este bucle queremos obtener de cada mes la vivienda que ha consumido mas
        for (i = 0; i < numV; i++)
        {
            if (conMaxMeses[j] < viviendas[i].consumos[j])
            {
                conMaxMeses = viviendas[i].consumos[j]; // Pasa a ser la nueva vivienda que ha consumido mas
            }
            conMedioMeses[j] += viviendas[i].consumos[j];
        }
        conMedioMeses[j] = conMedioMeses[i] / NUM_VIVIENDAS;
    } 

    return 0;
}

/* 
    Apartado 3 -> Este no estaba en el examen, es mas para comprobar que ahora funciona bien. Pero ya lo hice con anterioridad  
    esto es un repaso y me da algo de palo jeje
*/