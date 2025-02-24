#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct puntosCardinales {
    float x, y;
} punto;

void mostrarPuntos (punto p);

int main(void)
{
    punto p1, p2, p3;
    float distancia;

    // Leer los puntos
    printf("\nIntroduzca el valor 'x' para el primer punto: ");
    scanf ("%f", &p1.x);
    printf("\nIntroduzca el valor 'y' para el primer punto: ");
    scanf ("%f", &p1.y);
    
    printf("\nIntroduzca el valor 'x' para el segundo punto: ");
    scanf ("%f", &p2.x);
    printf("\nIntroduzca el valor 'y' para el segundo punto: ");
    scanf ("%f", &p2.y);

    // Mostrar por pantalla
    printf ("\nValores para el primer punto:");
    mostrarPuntos(p1);

    printf ("\nValores para el segundo punto:");
    mostrarPuntos(p2);

    // Calcular distancia entre ellos
    distancia = sqrt (pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    printf ("\nDistancia entre ambos puntos: %.2f", distancia);

    // Calculamos el punto medio
    p3.x = (p1.x + p2.x) / 2;
    p3.y = (p1.y + p2.y) / 2;
    printf ("\nEl punto medio de los puntos es:");
    printf ("\nValor x \t Valor y");
    printf ("\n--------\t--------");
    printf ("\n%.2f    \t %.2f   \n", p3.x, p3.y);
    
}
void mostrarPuntos (punto p)
{
    printf ("\n Valor x: %.2f", p.x);
    printf ("\n Valor y: %.2f\n", p.y);
}