#include <stdio.h>
#include <ctype.h>
#include "listaEnlazada.h"

int main() {
    ListaEnlazada lista = NULL;
    tipoInfo valor;
    int opcion, pos, num;
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
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                liberarListaEnlazada(&lista);  // Por si ya había una
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
                printf("1. Al comienzo\n");
                printf("2. Al final\n");
                printf("3. En posición (índice)\n");
                printf("4. Antes de un nodo (índice)\n");
                printf("5. Después de un nodo (índice)\n");
                printf("Opción: ");
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
                printf("1. Al comienzo\n");
                printf("2. Al final\n");
                printf("3. Por índice\n");
                printf("4. Nodo por índice (directo)\n");
                printf("Opción: ");
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

            case 0:
                liberarListaEnlazada(&lista);
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
