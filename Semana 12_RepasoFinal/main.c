#include <stdio.h>
#include <stdlib.h>
#include "listaEnlazada.h"
#include "matricesyListas.h"


int main() {
    ListaEnlazada lista = NULL;
    matInt matriz = {NULL, 0, 0};
    tipoInfo valor;
    int opcion, pos, num, filas, columnas, resultado;
    char fichero[100];

    crearVacia(&lista);

    do {
        printf("\n=== MENÚ PRINCIPAL ===\n");
        printf("1. Crear lista vacía\n");
        printf("2. Crear lista con valores aleatorios\n");
        printf("3. Mostrar lista\n");
        printf("4. Insertar\n");
        printf("5. Eliminar\n");
        printf("6. Devolver valor por índice\n");
        printf("7. Insertar ordenado\n");
        printf("8. Guardar en fichero\n");
        printf("9. Cargar desde fichero\n");
        printf("10. Pasar lista a matriz\n");
        printf("11. Pasar matriz a lista\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                liberarListaEnlazada(&lista);
                crearVacia(&lista);
                printf("Lista vacía creada.\n");
                break;

            case 2:
                printf("¿Cuántos nodos aleatorios?: ");
                scanf("%d", &num);
                crearListaValoresAleatorios(&lista, num);
                printf("Lista con %d valores aleatorios creada.\n", num);
                break;

            case 3:
                printf("Contenido de la lista:\n");
                mostrarListaEnlazada(lista);
                break;

            case 4:
                printf("\n=== INSERCIÓN ===\n");
                printf("1. Al comienzo\n2. Al final\n3. En posición\n4. Antes de nodo\n5. Después de nodo\nOpción: ");
                scanf("%d", &num);
                printf("Valor a insertar: ");
                scanf("%d", &valor);

                if (num == 1) insertarNodoComienzo(&lista, &valor);
                else if (num == 2) insertarNodoFinal(&lista, &valor);
                else if (num == 3) {
                    printf("Posición: ");
                    scanf("%d", &pos);
                    insertarNodoPosicionIndice(&lista, pos, &valor);
                }
                else if (num == 4 || num == 5) {
                    printf("Índice del nodo: ");
                    scanf("%d", &pos);
                    tipoNodoRef nodo = lista;
                    for (int i = 0; i < pos && nodo != NULL; i++)
                        nodo = nodo->sig;
                    if (nodo == NULL) printf("Índice no válido.\n");
                    else {
                        if (num == 4) insertarAntesDeNodo(&lista, nodo, &valor);
                        else insertarDespuesDeNodo(&lista, nodo, &valor);
                    }
                }
                break;

            case 5:
                printf("\n=== ELIMINACIÓN ===\n");
                printf("1. Al comienzo\n2. Al final\n3. Por índice\n4. Nodo por índice (directo)\nOpción: ");
                scanf("%d", &num);

                if (num == 1) eliminarNodoComienzo(&lista);
                else if (num == 2) eliminarNodoFinal(&lista);
                else if (num == 3) {
                    printf("Índice: ");
                    scanf("%d", &pos);
                    eliminarNodoPosicionIndice(&lista, pos);
                }
                else if (num == 4) {
                    printf("Índice del nodo: ");
                    scanf("%d", &pos);
                    tipoNodoRef nodo = lista;
                    for (int i = 0; i < pos && nodo != NULL; i++)
                        nodo = nodo->sig;
                    if (nodo == NULL) printf("Índice no válido.\n");
                    else eliminarNodo(&lista, nodo);
                }
                break;

            case 6:
                printf("Índice del valor a devolver: ");
                scanf("%d", &pos);
                valor = devolverInfoPosicionIndice(lista, pos);
                printf("Valor en posición %d: %d\n", pos, valor);
                break;

            case 7:
                printf("Valor a insertar ordenado: ");
                scanf("%d", &valor);
                insertarOrdenada(&lista, &valor);
                break;

            case 8:
                printf("Nombre del fichero a guardar: ");
                scanf("%s", fichero);
                guardarListaEnlazadaTexto(lista, fichero);
                printf("Lista guardada en %s.\n", fichero);
                break;

            case 9:
                liberarListaEnlazada(&lista);
                printf("Nombre del fichero a cargar: ");
                scanf("%s", fichero);
                cargarListaEnlazadaTexto(&lista, fichero);
                printf("Lista cargada desde %s.\n", fichero);
                break;

            case 10:
                printf("Filas para la matriz: ");
                scanf("%d", &filas);
                printf("Columnas para la matriz: ");
                scanf("%d", &columnas);
                if (matriz.m != NULL) liberarMatInt(&matriz);
                resultado = pasarListaEnlazadaAMatriz(lista, &matriz, filas, columnas);
                if (resultado >= 0)
                    for (int i = 0; i < matriz.numFil; i++){
                        for (int j = 0; j < matriz.numCol; j++){
                            printf("%d ", matriz.m[i][j]);
                        }
                        printf("\n");
                    }
                else
                    printf("Error al pasar la lista a matriz.\n");
                break;

            case 11:
                liberarListaEnlazada(&lista);  // Vaciar antes
                resultado = pasarMatrizAListaEnlazada(&lista, &matriz);
                if (resultado == 0) {
                    printf("Lista generada a partir de la matriz:\n");
                    mostrarListaEnlazada(lista);
                } else {
                    printf("Error al convertir matriz a lista.\n");
                }
                break;

            case 0:
                liberarListaEnlazada(&lista);
                liberarMatInt(&matriz);
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }

    } while (opcion != 0);

    return 0;
}
