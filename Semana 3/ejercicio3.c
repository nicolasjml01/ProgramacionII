#include <stdio.h>
#include <stdlib.h>

// Ocho campos de longitud de 1 bit
typedef struct OchoBits {
    unsigned char b0:1, b1:1, b2:1, b3:1,
                  b4:1, b5:1, b6:1, b7:1;
} OchoBits;

// Tramas declara una variable global. No puedo declarar mas variables de la union por no darle nombre, solo positble tramas
union {
    int campoInt;
    float campoFloat;
    long long campoLongLong;
    double campoDouble;
    OchoBits byte[8];
} tramas;

void mostrarByte(OchoBits);

int main (void)
{
    char opcion;
    int i;

    do
    {
        printf ("\n\nA) int \t B) float \t C) long long \t D) double \t Q) Salir: ");
        scanf("%c%*c", &opcion);

        switch(opcion)
        {
            case 'A':
            case 'a':
                printf ("\nTrama de bits de un int\n-----------------------------------\nEscriba un int: ");
                scanf ("%d%*c", &tramas.campoInt);
                printf("|");
                for (i = sizeof(int) -1; i>= 0; i--)
                {
                    //printf("%u%u%u%u%u%u%u%u", tramas.byte[i].b7, tramas.byte[i].b6, tramas.byte[i].b5,tramas.byte[i].b4, 
                                           // tramas.byte[i].b3, tramas.byte[i].b2, tramas.byte[i].b1,tramas.byte[i].b0);
                    mostrarByte(tramas.byte[i]);
                }
                printf("|\n");
                break;
            case 'B':
            case 'b':
                printf ("\nTrama de bits de un float\n-----------------------------------\nEscriba un float: ");
                scanf ("%f%*c", &tramas.campoFloat);
                printf("|");
                for (i = sizeof(float) -1; i>= 0; i--)
                {
                    mostrarByte(tramas.byte[i]);
                }
                printf("|\n");
                break;
            case 'C':
            case 'c':
                printf ("\nTrama de bits de un long long\n-----------------------------------\nEscriba un long long: ");
                scanf ("%lld%*c", &tramas.campoLongLong);
                printf("|");
                for (i = sizeof(long long) -1; i>= 0; i--)
                {
                    mostrarByte(tramas.byte[i]);
                }
                printf("|\n");
                break;
            case 'D':
            case 'd':
                printf ("\nTrama de bits de un double\n-----------------------------------\nEscriba un double: ");
                scanf ("%lf%*c", &tramas.campoDouble);
                printf("|");
                for (i = sizeof(double) -1; i>= 0; i--)
                {
                    mostrarByte(tramas.byte[i]);
                }
                printf("|\n");
                break;
            case 'Q':
                break;
            default:
                printf ("\nOpcion incorrecta\n");
                break;
        }

    }while (opcion != 'Q');


    return 0;
}

void mostrarByte(OchoBits byte)
{

    printf("%u%u%u%u%u%u%u%u", byte.b7, byte.b6, byte.b5, byte.b4, byte.b3, byte.b2, byte.b1, byte.b0);
}