#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lo haremos con enum, pero es posible hacerlos sin ellas
typedef struct tipoMes
{
    char nombre[50];
    char abreviatura[4]; // Cuatro para almacenar el \n
    int dias;
    int orden;
}tipoMes;

enum meses { enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre};

void iniciarVector(tipoMes *, int);

int main (void)
{
    int dia, mes, total;
    //tipoMes meses[12] = {"enero", "ene", 31, 1,
                        //"febrero", "feb", 28, 2,
                        //"marzo", "mar", 30, 3};

    tipoMes meses[12];
    iniciarVector(meses, 12); 
    printf ("Introduzca un dia del año (dd/mm): ");
    scanf ("%d/%d%*c", &dia, &mes);

    total = dia;
    for (int i = 0; i < mes-1; i++)
    {
        total += meses[i].dias;
    }

    printf ("\nDesde el %d de %s hasta el dia %d de %s han transcurrido %d dias\n",
            1, meses[0].nombre, dia, meses[mes-1].nombre, total);

    return 0;
}

void iniciarVector(tipoMes * meses, int tam)
{
    static char nombreMeses[][20] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre"
                                     "noviembre", "diciembre"};

    for (int i = 0; i < tam; i++)
    {
        // Copiamos una cadena entera (segundo parametro)
        strcpy(meses[0].nombre, nombreMeses[i]);
        // Copiamos los 3 primeros caracteres de la cadena que pasamos como 2 parametro
        strncpy(meses[i].abreviatura, nombreMeses[i],3);
        meses[i].orden = i+1;
        switch(i)
        {
            case febrero: //febrero
                meses[i].dias = 28;
                break;
            case abril:
            case junio:
            case 8:
            case 10:
                meses[i].dias = 30;
                break;
            defaul:
                meses[i].dias = 31;
                break;
        }
    }
}