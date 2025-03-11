#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_MESES 12
#define NUM_VIVIENDAS 25
// 1. Desde aqui
typedef struct tipoVivienda{
    char idCastro[21];
    char propietario[80];
    char direccion[128];
    float superficie;
    float consumos[NUM_MESES];
}vivienda;

// Prototipo
void cargarRegistrosAleatorios(vivienda *v, int num);
void mostrarRegistros(vivienda *v, int num);
int procesarConsumos(vivienda* viviendas, int numV,
                     float * conMedioViviendas, float * conMaxViviendas,
                     float * conMedioMeses, float * conMaxMeses);

int main (void)
{
    int numV;
    int resultado;
    float conMedioMeses[NUM_MESES], conMaxMeses[NUM_MESES];

    printf ("\nIntroduzca el numero de viviendas a crear (entre 1 y %d): ", NUM_VIVIENDAS);
    scanf ("%d", &numV);

    if (numV <= 0 || numV > NUM_VIVIENDAS) {
        printf("\nERROR, el número de viviendas debe estar entre 1 y %d\n", NUM_VIVIENDAS);
        return -1;
    }
    vivienda viviendas[numV];
    float conMedioViviendas[numV], conMaxViviendas[numV]; 
    cargarRegistrosAleatorios(viviendas, numV);

    resultado = procesarConsumos(viviendas, numV, conMedioViviendas, conMaxViviendas, conMedioMeses, conMaxMeses);
    if (resultado == -1) printf("\nERROR, el struct de viviendas no ha sido cargado correctamente\n");
    if (resultado == -2) printf("\nERROR, el número de viviendas debe estar entre 1 y %d\n", NUM_VIVIENDAS);
    if (resultado == -3) printf("\nERROR, los valores máximo y medios no pueden ser NULL\n");
    
    mostrarRegistros(viviendas, numV);

    printf("\nConsumo medio de cada vivienda:\n");
    for (int i = 0; i < numV; i++) {
        printf("Vivienda %s: %.2f\n", viviendas[i].idCastro, conMedioViviendas[i]);
    }
    
    printf("\nConsumo máximo de cada vivienda:\n");
    for (int i = 0; i < numV; i++) {
        printf("Vivienda %s: %.2f\n", viviendas[i].idCastro, conMaxViviendas[i]);
    }

    printf("\nConsumo medio por mes:\n");
    for (int j = 0; j < NUM_MESES; j++) {
        printf("Mes %d: %.2f\n", j + 1, conMedioMeses[j]);
    }
    
    printf("\nConsumo máximo por mes:\n");
    for (int j = 0; j < NUM_MESES; j++) {
        printf("Mes %d: %.2f\n", j + 1, conMaxMeses[j]);
    }

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
            conMedioMeses[j] += viviendas[i].consumos[j];
            if (conMaxMeses[j] < viviendas[i].consumos[j]) conMaxMeses[j] = viviendas[i].consumos[j];
        }
        conMedioMeses[j] /= numV;
    }

    return 0;
}

// 3.
void cargarRegistrosAleatorios(vivienda *v, int numV) {
    static char propietarios[][20] = {"Nicolas Miranda", "Pedro Benitez", "Juan Perez", "Maria Lopez", "Carlos Gomez", "Ana Martinez", "Luis Fernandez"};
    static char direcciones[][50] = {"Av Mirat 32", "Calle del dragon 1","Calle Falsa 123", "Av. Siempre Viva 742", "Paseo del Prado 15", "Gran Via 55", "Diagonal 80"};
    int numPropietarios = sizeof(propietarios) / sizeof(propietarios[0]);
    int numDirecciones = sizeof(direcciones) / sizeof(direcciones[0]);
    
    srand(time(NULL));
    
    for (int i = 0; i < numV; i++) {
        sprintf(v[i].idCastro, "ID-%05d", rand() % 100000);
        strcpy(v[i].propietario, propietarios[rand() % numPropietarios]);
        strcpy(v[i].direccion, direcciones[rand() % numDirecciones]);
        v[i].superficie = (rand() % 300) + 20 + ((rand() % 100) / 100.0); // Superficie entre 20.00 y 319.99
        
        for (int j = 0; j < NUM_MESES; j++) {
            v[i].consumos[j] = (rand() % 500) + ((rand() % 100) / 100.0); // Consumo entre 0.00 y 499.99
        }
    }
}
void mostrarRegistros(vivienda *v, int numV) {
    printf("\n%-10s %-20s %-30s %-10s %s\n", "ID Castro", "Propietario", "Dirección", "Superficie", "Consumos");
    printf("------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < numV; i++) {
        printf("%-10s %-20s %-30s %-10.2f ", v[i].idCastro, v[i].propietario, v[i].direccion, v[i].superficie);
        for (int j = 0; j < NUM_MESES; j++) {
            printf("%.2f ", v[i].consumos[j]);
        }
        printf("\n");
    }
}