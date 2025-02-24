/*
    El ejercicio lo que hace es declarar un vector de tipoEmpleado elementos. 
    Cada elemento es una variable tipoEmpleado (3 campos -> ape, nombre, matricula)
    Declara además un vector de peutneros del mismo tamaño, cada puntero apunta a tipoEmpleado. Almacena las direcciones de memoria de los elementos
del vector de tipoEmpleado
    ¿Para que hacer esto?
    Pasos:
    1) Declara vectores
    2) Rellena el vector
    3) Muestra el vector de tipoEmpleado
    4) Los ordena por apellidos
    5) Se vuelve a mostrar, vemos con un temporizador cuanto tarda en ordenarlo
    6) Lo haremos probaremos con el vector de empleados y con los punteros
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>


typedef struct empleados {
    char apellidos[30];
    char nombre[15];
    int  matricula;
    char bufferRelleno[50000]; // Para comprobar la eficiencia si el struct es muy grande
} tipoEmpleado;


void cargarRegistrosAleatorios(tipoEmpleado * empleados, int numEmpleados);
void cargarUnRegistro(tipoEmpleado * empleado);

void mostrarRegistro(tipoEmpleado empleado);
void mostrarRegistrosRef(tipoEmpleado ** refsEmpleados, int numEmpleados);
void mostrarRegistros(tipoEmpleado * empleados, int numEmpleados);

void ordenarRegistrosRefApellido(tipoEmpleado ** refsEmpleados, int numEmpleados);
void ordenarRegistrosApellido(tipoEmpleado * empleados, int numEmpleados);

void ordenarRegistrosRefNombre(tipoEmpleado ** refsEmpleados, int numEmpleados);
void ordenarRegistrosNombre(tipoEmpleado *empleados, int numEmpleados);

void ordenarRegistrosRefMatricula(tipoEmpleado ** refsEmpleados, int numEmpleados);
void ordenarRegistrosMatricula(tipoEmpleado *empleados, int numEmpleados);


int buscarRegistroNombre(char *nombre, tipoEmpleado *empleados, int numEmpleados);
int buscarRegistroRefNombre(char *nombre, tipoEmpleado ** refsEmpleados, int numEmpleados);

#define NUM_EMPLEADOS   10


int
main(void)
{
    tipoEmpleado regEmpleados[NUM_EMPLEADOS], unEmpleado;
    tipoEmpleado *regEmpleadosRef[NUM_EMPLEADOS];
    int i, indice;
    clock_t tiempoInicial, tiempoFinal;
    char nombre[50];
    
    
    
    cargarRegistrosAleatorios(regEmpleados, NUM_EMPLEADOS);
    
    //mostrarRegistros(regEmpleados, NUM_EMPLEADOS);
    
    printf("\n\n Jugando con un único registro: \n");
    unEmpleado = regEmpleados[2];
    mostrarRegistro(unEmpleado);
    mostrarRegistro(regEmpleados[2]);
    mostrarRegistros(&unEmpleado, 1);
    
    //    cargarUnRegistro(&unEmpleado);
    //    printf("\n\nEl registrocargado es: \n");
    //    mostrarRegistro(unEmpleado);
    //    printf("\ny el registro regEmpleados[2] es: \n");
    //    mostrarRegistro(regEmpleados[2]);
    
    for (i = 0; i < NUM_EMPLEADOS; i++)
	    regEmpleadosRef[i] = &regEmpleados[i]; // Para cada elemento le asignamos la direccion de memoria de regEmpleados
    
    printf("\n\nValores no clasificados (a través matriz punteros): \n");
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);
    
    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosRefApellido(regEmpleadosRef, NUM_EMPLEADOS);
    tiempoFinal = clock ();
    
    
    printf("\n\nValores clasificados (a través matriz punteros): \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);
    
    printf("\n\nAhora valores no clasificados matriz de registros original: \n");
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);
    
    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosApellido(regEmpleados, NUM_EMPLEADOS);
    tiempoFinal = clock ();
    
    printf("\n\nAhora valores clasificados matriz de registros original: \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosRefNombre(regEmpleadosRef, NUM_EMPLEADOS);
    tiempoFinal = clock ();

    printf("\n\nValores ordenador por nombre (a través matriz punteros): \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosNombre(regEmpleados, NUM_EMPLEADOS);
    tiempoFinal = clock ();
    
    printf("\n\nValores ordenados por nombre vector: \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);
    
    printf("\n\nValores ordenador por matricula (a través matriz punteros): \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosRefMatricula(regEmpleadosRef, NUM_EMPLEADOS);
    tiempoFinal = clock ();

    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosMatricula(regEmpleados, NUM_EMPLEADOS);
    tiempoFinal = clock ();
    
    printf("\n\nValores ordenados por matricula del vector: \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    printf ("Escribe un nombre para buscar: ");
    scanf("%[^\n]%*c", nombre);
    indice = buscarRegistroNombre(nombre, regEmpleados, NUM_EMPLEADOS);
    if (indice == -1) printf ("\nError: nombre no encontrado");
    else printf ("\n El nombre ha sido encontrado en el indice: %d", indice);
    // Otra ocpion es llamar a modificar registro
    // modificarRegistro(&regEmpleados(indice));
    return 0;
}

void
cargarRegistrosAleatorios(tipoEmpleado * empleados, int numEmpleados)
{
    int i;
    static char apellidos [][15] = {"ALONSO","ALVAREZ","ARBESU",
        "DOMINGUEZ","FERNANDEZ","FLORIANO",
        "GONZALEZ","GOMEZ","GUTIERREZ",
        "MARTIN", "MORO", "PEREZ","TURRION",
        "ZAMBRANO"};
    static char nombres [][15] = {"ALVARO","ARSENIO","DOMINGO",
        "FELIPE","FATIMA","FABIAN",
        "GONZALO","PEDRO","PATRICIA",
        "TOMAS", "ZOILO"};
    int numApellidos = sizeof(apellidos)/15;
    int numNombres = sizeof(nombres)/15;
    char buffer[5];
    
    srandom(time(NULL));
    for (i = 0; i < numEmpleados; i++) {
        sprintf(empleados[i].apellidos,"%s %s",apellidos[random() % numApellidos],
                apellidos[random() % numApellidos]); // En lugar de mostrar por pantalla lo guarda en la variable marcado como 1er atributo
        sprintf(empleados[i].nombre,"%s",nombres[random() % numNombres]);
        sprintf(buffer,"%c%c%c%c",(char)('0' + random() % 10),
                (char)('0' + random() % 10),
                (char)('0' + random() % 10),
                (char)('0' + random() % 10));
        empleados[i].matricula = atoi(buffer); // atoi convierte una cadena a entero
    }
}


void
cargarUnRegistro(tipoEmpleado * empleado)
{
    /*
     * Esta función recibe un ÚNICO REGISTRO de tipo tipoEmpleado
     * y el alumno debe escribir el código necesario para que
     * se pidan los datos necesarios por pantalla y cargar
     * los campos del registro con los datos introducidos 
     * por teclado por el usuario
     */
    cargarRegistrosAleatorios(empleado, 1);
    
}


void
mostrarRegistro(tipoEmpleado empleado)
{
    /*
     * Esta función muestra por pantalla y en una única línea 
     * los datos almacenados en los campos del registro
     * recibido
     */
    printf("\n%s \t %s \t %d", empleado.apellidos, empleado.nombre, empleado.matricula);
}

void
mostrarRegistros(tipoEmpleado * empleados, int numEmpleados)
{
    /*
     * Esta función recibe un vector de registros de tipoEmpleado
     * de tamaño numEmpleados, y muestra por pantalla el contenido
     * de los campos de todos los registros de dicho vector, un 
     * registro por línea
     */
    printf ("\nAPELLIDOS \t NOMBRE \t MATRICULA");
    printf ("\n----------\t--------\t----------");
    for (int i = 0;i < numEmpleados; i++)
    {
        mostrarRegistro(empleados[i]);
    }   
    printf ("\n"); 
}

void
mostrarRegistrosRef(tipoEmpleado ** refsEmpleados, int numEmpleados)
{
    /*
     * Esta función recibe un vector de  punteros a registros de
     * tipoEmpleado, de tamaño numEmpleados (el vector), y muestra por pantalla
     * el contenido de los campos de todos los registros referenciados
     * por los punteros del vector, mostrando un registro por línea
     */
    printf ("\nAPELLIDOS \t NOMBRE \t MATRICULA");
    for (int i=0; i < numEmpleados; i++){
        printf("\n%s \t %s \t %d", refsEmpleados[i]->apellidos, refsEmpleados[i]->nombre, refsEmpleados[i]->matricula);
        // printf("\n%s \t %s \t %d", (*refsEmpleados[i]).apellidos, (*refsEmpleados[i]).nombre, (*refsEmpleados[i]).matricula);
    }
}


void
ordenarRegistrosApellido(tipoEmpleado * empleados, int numEmpleados)
{
    int i,j;
    tipoEmpleado temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(empleados[j].apellidos, empleados[j - 1].apellidos)) < 0) {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}

void
ordenarRegistrosRefApellido(tipoEmpleado ** refsEmpleados, int numEmpleados)
{
        /*
         * Esta función es análoga a la función ordenarRegistrosApellido
         * pero con la diferencia que en vez de recibir un vector de 
         * registros, recibe un vector de punteros a registros. La función
         * utiliza el mismo algoritmo de ordenación (burbuja) para ordenar
         * pero en vez de ordenar los registros, se ordenará el vector
         * de punteros, utilzando la información del campo apellidos
         * del registro apuntado. 
         */
    int i,j;
    tipoEmpleado *temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(refsEmpleados[j]->apellidos, refsEmpleados[j - 1]->apellidos)) < 0) {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    }
}

void ordenarRegistrosRefNombre(tipoEmpleado ** refsEmpleados, int numEmpleados)
{
    int i,j;
    tipoEmpleado *temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(refsEmpleados[j]->nombre, refsEmpleados[j - 1]->nombre)) < 0) {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    }
}
void ordenarRegistrosNombre(tipoEmpleado *empleados, int numEmpleados)
{
    int i,j;
    tipoEmpleado temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(empleados[j].nombre, empleados[j - 1].nombre)) < 0) {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}

// HACER ESTO BIEN, NO SE ORDENA BIEN 
void ordenarRegistrosRefMatricula(tipoEmpleado ** refsEmpleados, int numEmpleados)
{
    int i,j;
    tipoEmpleado *temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((refsEmpleados[j]->nombre) < (refsEmpleados[j - 1]->nombre)) {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    }
}
void ordenarRegistrosMatricula(tipoEmpleado *empleados, int numEmpleados)
{
    int i,j;
    tipoEmpleado temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((empleados[j].nombre) < (empleados[j - 1].nombre)) {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}

int buscarRegistroNombre(char *nombre, tipoEmpleado *empleados, int numEmpleados)
{
    int i;
    for (i = 0; i < numEmpleados; i++)
    {
        if (strcmp(nombre, empleados[i].nombre) == 0)
        {   // Es que el campo nombre esta entre los empleados
            return i;
        }
    }
    return -1;
}