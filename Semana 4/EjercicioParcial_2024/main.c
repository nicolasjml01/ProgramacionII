#include <stdio.h>


#define NUM_MESES 12
#define NUM_VIVIENDAS 25
// 1. Desde aqui
typedef struct tipoVivienda{
    char idCastro[21];
    char propietario[80];
    char direccion[128];
    float superficio;
    float consumos[NUM_MESES];
}vivienda;

// Prototipo
int procesarConsumos(struct tipoVivienda* viviendas, int numV,
    float * conMedioViviendas, float * conMaxViviendas,
    float * conMedioMeses, float * conMaxMeses);

int main (void)
{
    vivienda viviendas[NUM_VIVIENDAS];
    return 0;
}

// 2.
/*
conMedioViviendas es un vector con la media de consumo de cada vivienda
conMaxViviendas es un vector con el mes que mas ha consumido cada vivienda
conMedioMeses vector de NUM_MESES y es la media mes a mes de la suma de todas las viviendas
conMaxMeses el consumo maximo de entre todas las viviendas en cada mes
*/
int procesarConsumos(vivienda* viviendas, int numV,
                     float * conMedioViviendas, float * conMaxViviendas,
                     float * conMedioMeses, float * conMaxMeses)
{
    int i,j;
    int suma;
    float media;

    if (viviendas == NULL) return -1;
    if (numV <= 0 || numV > NUM_VIVIENDAS) return -2;
    if (conMedioViviendas == NULL || conMaxViviendas == NULL || conMedioMeses == NULL || conMaxMeses == NULL) return -3;

    for (i = 0; i < numV; i++)
    {
        conMedioViviendas[i] = 0.0;
        conMaxViviendas[i] = viviendas[i].consumos[0];
        for (j = 0; j < NUM_MESES; j++)
        {
            conMedioViviendas[i] += viviendas[i].consumos[j];
            if (conMaxViviendas[i] < viviendas[i].consumos[j]) conMaxViviendas[i] = viviendas[i].consumos[j];
        }
        conMedioViviendas[i] /= NUM_MESES; // Para evitar recibir un resultado entero hacemos un cast
        
    }
    for (j = 0; j < NUM_MESES; j++)
    {
        conMedioMeses[j] = 0.0;
        conMaxMeses[j] = viviendas[0].consumos[j];
        for (i = 0; i < numV; i++)
        {
            conMedioMeses[j] += viviendas[j].consumos[i];
            if (conMaxMeses[j] < viviendas[i].consumos[j]) conMaxMeses[j] = viviendas[i].consumos[j];
        }
        conMedioMeses[j] /= numV;
    }

    return 0;
}