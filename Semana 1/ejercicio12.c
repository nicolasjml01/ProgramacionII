#include <stdio.h>
#include <stdlib.h>

typedef struct fraccion {
    int numerador, denominador;
} fraccion;

int mcd(int a, int b);
int mcm(int a, int b);
fraccion sumarFracciones(fraccion f1, fraccion f2);
fraccion restarFracciones(fraccion f1, fraccion f2);

int main(void) {
    fraccion f1, f2, f3;
    char operacion;

    // Leer la primera fracción
    printf("\nIntroduzca el valor del numerador de la primera fracción: ");
    scanf("%d", &f1.numerador);
    printf("Introduzca el valor del denominador de la primera fracción: ");
    scanf("%d", &f1.denominador);

    // Validar denominador no sea 0
    if (f1.denominador == 0) {
        printf("Error: El denominador no puede ser cero.\n");
        return -1;
    }

    // Leer la operación
    printf("\nIntroduzca la operación a realizar (+, -, /, *): ");
    scanf(" %c", &operacion);

    // Leer la segunda fracción
    printf("\nIntroduzca el valor del numerador de la segunda fracción: ");
    scanf("%d", &f2.numerador);
    printf("Introduzca el valor del denominador de la segunda fracción: ");
    scanf("%d", &f2.denominador);

    // Validar denominador no sea 0
    if (f2.denominador == 0) {
        printf("Error: El denominador no puede ser cero.\n");
        return -1;
    }

    // Operaciones según el caso
    switch (operacion) {
        case '*':
            f3.numerador = f1.numerador * f2.numerador;
            f3.denominador = f1.denominador * f2.denominador;
            break;

        case '/':
            f3.numerador = f1.numerador * f2.denominador;
            f3.denominador = f1.denominador * f2.numerador;
            break;

        case '-':
            f3 = restarFracciones(f1, f2);
            break;

        case '+':
            f3 = sumarFracciones(f1, f2);
            break;

        default:
            printf("Operación no válida.\n");
            return -1;
            break;
    }

    // Imprimir el resultado final
    printf("\nResultado: %d / %d\n", f3.numerador, f3.denominador);

    return 0;
}

// Función para calcular el MCD (Máximo Común Divisor)
int mcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para calcular el MCM (Mínimo Común Múltiplo)
int mcm(int a, int b) {
    return abs((a * b) / mcd(a, b));
}

// Función para sumar fracciones y devolver el resultado simplificado
fraccion sumarFracciones(fraccion f1, fraccion f2) {
    fraccion resultado;

    // Calcular el MCM de los denominadores
    int denominadorComun = mcm(f1.denominador, f2.denominador);
    
    // Ajustar numeradores al nuevo denominador
    int numerador1 = f1.numerador * (denominadorComun / f1.denominador);
    int numerador2 = f2.numerador * (denominadorComun / f2.denominador);
    
    // Sumar los numeradores
    resultado.numerador = numerador1 + numerador2;
    resultado.denominador = denominadorComun;

    // Simplificar la fracción
    int divisorComun = mcd(resultado.numerador, resultado.denominador);
    resultado.numerador /= divisorComun;
    resultado.denominador /= divisorComun;

    return resultado;
}

// Función para restar fracciones y devolver el resultado simplificado
fraccion restarFracciones(fraccion f1, fraccion f2) {
    fraccion resultado;

    // Calcular el MCM de los denominadores
    int denominadorComun = mcm(f1.denominador, f2.denominador);
    
    // Ajustar numeradores al nuevo denominador
    int numerador1 = f1.numerador * (denominadorComun / f1.denominador);
    int numerador2 = f2.numerador * (denominadorComun / f2.denominador);
    
    // Restar los numeradores
    resultado.numerador = numerador1 - numerador2;
    resultado.denominador = denominadorComun;

    // Simplificar la fracción
    int divisorComun = mcd(resultado.numerador, resultado.denominador);
    resultado.numerador /= divisorComun;
    resultado.denominador /= divisorComun;

    return resultado;
}
