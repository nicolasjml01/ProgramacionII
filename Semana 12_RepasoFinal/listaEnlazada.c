#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazada.h"

int crearVacia(ListaEnlazadaRef raiz)
{
    *raiz = NULL;
    return 0;
}

int estaVacia(ListaEnlazada raiz)
{
    if (raiz != NULL) return 0;
    return 1;
}
int liberarListaEnlazada(ListaEnlazadaRef raiz)
{
    tipoNodoRef aBorrar;
    while (!estaVacia(*raiz))
    {
        aBorrar = *raiz;
        *raiz = (*raiz)->sig;
        free(aBorrar);
    }
    return 0;
}

tipoNodoRef creaNodo(tipoInfoRef info)
{
    
    tipoNodoRef nuevo;
    if((nuevo = malloc(sizeof(tipoNodo))) == NULL) return NULL;
    nuevo->info = *info;
    nuevo->sig = NULL;
    return nuevo;
}

int insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
    tipoNodoRef anterior, sig, nuevo;
    
    if((nuevo = creaNodo(info)) == NULL) return -1;

    if (estaVacia(*raiz) || pos == NULL || pos == *raiz)
    {
        nuevo->sig = *raiz;
        *raiz = nuevo;
        return 0;
    }

    anterior = *raiz;
    while (anterior != NULL && anterior->sig != pos)
    {
        anterior = anterior->sig;
    }
    if (anterior != NULL)
    {
        nuevo->sig = anterior->sig;
        anterior->sig = nuevo;
        return 0;
    }
    free(nuevo);
    return -2;
    
}

int insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
    tipoNodoRef nuevo, indice, anterior;

    if((nuevo = creaNodo(info)) == NULL) return -1;

    if (estaVacia(*raiz))
    {
        *raiz = nuevo;
        return 0;
    }
    if (pos == *raiz)
    {
        nuevo->sig = *raiz;
        *raiz = nuevo;
        return 0;
    }
    indice = *raiz;
    while (indice != NULL && indice->sig != pos)
    {
        anterior = indice;
        indice = indice->sig;
    }
    if (indice == NULL)
    {
        anterior->sig = nuevo;
        return 0;
    }
    if (indice != NULL)
    {
        nuevo->sig = indice->sig;
        indice->sig = nuevo;
        return 0;
    }

    free(nuevo);
    return -2;
}

int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos)
{
    if (raiz == NULL || *raiz == NULL || pos == NULL) {
        return -1; // Lista vacía o nodo inválido
    }

    // Caso: pos es el primer nodo
    if (*raiz == pos) {
        *raiz = pos->sig;
        free(pos);
        return 1;
    }

    // Buscar el nodo anterior a pos
    tipoNodoRef actual = *raiz;
    while (actual != NULL && actual->sig != pos) {
        actual = actual->sig;
    }

    if (actual == NULL) {
        return -1; // Nodo pos no se encontró en la lista
    }

    // Religar y eliminar
    actual->sig = pos->sig;
    free(pos);
    return 1;
}
int insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	return insertarAntesDeNodo(raiz, *raiz, info); // O NULL
}
int insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	return insertarDespuesDeNodo(raiz, NULL, info);
}
int eliminarNodoComienzo(ListaEnlazadaRef raiz)
{
    tipoNodoRef aBorrar;
	if (!estaVacia(*raiz))
	{
		aBorrar = *raiz;
		*raiz = (*raiz)->sig;
		free(aBorrar);
		return 0;
	}
	return -1;
}
int eliminarNodoFinal(ListaEnlazadaRef raiz)
{
    if (raiz == NULL || *raiz == NULL) {
        return 0; // Lista vacía
    }

    tipoNodoRef actual = *raiz;

    // Caso: un solo nodo
    if (actual->sig == NULL) {
        free(actual);
        *raiz = NULL;
        return 0;
    }

    // Caso: más de un nodo, buscar penúltimo
    while (actual->sig->sig != NULL) {
        actual = actual->sig;
    }

    // actual->sig es el último nodo
    free(actual->sig);
    actual->sig = NULL;
    return 0;
}
int insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info)
{
    if (raiz == NULL || *raiz == NULL || indice < 0) return 0;

    tipoNodoRef actual = *raiz;
    int contador = 0;

    while (actual != NULL && contador < indice) {
        actual = actual->sig;
        contador++;
    }

    if (actual == NULL) return -1;

    return eliminarNodo(raiz, actual);
}

int eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice)
{
    if (raiz == NULL || *raiz == NULL || indice < 0) return 0;

    tipoNodoRef actual = *raiz;
    int contador = 0;

    while (actual != NULL && contador < indice) {
        actual = actual->sig;
        contador++;
    }

    if (actual == NULL) return -1;

    return eliminarNodo(raiz, actual);
}

tipoInfo devolverInfoPosicionIndice(ListaEnlazada raiz, int indice)
{
	if (raiz == NULL || indice < 0) {
        return -1;  // Error: lista vacía o índice inválido
    }

    tipoNodoRef actual = raiz;
    int contador = 0;

    while (actual != NULL && contador < indice) {
        actual = actual->sig;
        contador++;
    }

    if (actual == NULL) {
        return -1;  // índice fuera de rango
    }

    return actual->info;
}

int insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	if (raiz == NULL || info == NULL) {
        return -1;  // Error: parámetros inválidos
    }

    // Crear nuevo nodo
    tipoNodoRef nuevo = creaNodo(info);
    if (nuevo == NULL) {
        return -1;  // Error: fallo en creación de nodo
    }

    // Lista vacía: insertar al principio
    if (*raiz == NULL) {
        *raiz = nuevo;
        return 0;
    }

    // Si debe ir al inicio
    if (nuevo->info <= (*raiz)->info) {
        nuevo->sig = *raiz;
        *raiz = nuevo;
        return 0;
    }

    // Buscar nodo anterior a la posición de inserción
    tipoNodoRef actual = *raiz;
    while (actual->sig != NULL && actual->sig->info < nuevo->info) {
        actual = actual->sig;
    }

    // Insertar después de 'actual'
    nuevo->sig = actual->sig;
    actual->sig = nuevo;

    return 0;
}

int
mostrarListaEnlazada(ListaEnlazada raiz)
{
	tipoNodoRef aImprimir;
	int res = 0,i = 0;
	
	printf("\n\n");
	printf("%-14s%-10s\n","  Posición", "Valor");
	printf("%-14s%-10s\n","  ==========", "======");


	aImprimir = raiz;
	while (aImprimir != NULL) {
		printf("\t%3d)\t%7d\n",i++, aImprimir->info);
		aImprimir = aImprimir->sig;
	}
	return res;
}


int
crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos)
{
	int i;
	tipoInfo temp;
	
	if (estaVacia(*raiz)) {
		srandom(time(NULL));
		for (i = 0; i < numNodos; i++) {
            temp = random()%10000;
            insertarDespuesDeNodo(raiz, NULL, &temp);
            //insertarAntesDeNodo(raiz, NULL, &temp);
            //insertarNodoFinal(raiz, &temp);
			//insertarNodoComienzo(raiz, &temp);
		}
		return 0;
	}
	return -1;
}

// EJERCICIO 2
int guardarListaEnlazadaTexto(ListaEnlazada raiz, char *nombreFichero)
{
    FILE *fichero;
    tipoNodoRef actual;
    int contador = 0;

    if (raiz == NULL || nombreFichero == NULL) return -1;

    if((fichero = fopen(nombreFichero, "w")) == NULL) return -2;

    actual = raiz;
    while (actual != NULL)
    {
        fprintf(fichero, "%d ", actual->info);
        actual = actual->sig;
        contador++;
    }

    fclose(fichero);
    return contador;
}

int cargarListaEnlazadaTexto (ListaEnlazadaRef raiz, char *nombreFichero)
{
    FILE *fichero;
    tipoInfo valor;
    int result, contador = 0;

    if (raiz == NULL || nombreFichero == NULL) return -1;

    if((fichero = fopen(nombreFichero, "r")) == NULL) return -2;

    while ((result = fscanf(fichero, "%d ", &valor)) == 1)
    {
        if(insertarOrdenada(raiz, &valor) != 0)
        {
            liberarListaEnlazada(raiz);
            fclose(fichero);
            return -2;
        }
        contador++;
    }
    if (result != EOF)
    {
        liberarListaEnlazada(raiz);
        fclose(fichero);
        return -2;
    }

    fclose(fichero);
    return contador;
}

// Version 2 que es mas propensa al examen. Cargar el fichero e ir creando la lista
int cargarListaEnlazadaTextoV2 (ListaEnlazadaRef raiz, char *nombreFichero)
{
    FILE *fich;
    tipoNodoRef nuevo;
    tipoInfo info;
    int res;

    if (raiz == NULL || nombreFichero == NULL) return -1;

    if((fich = fopen(nombreFichero, "r")) == NULL) return -2;

    while ((res = fscanf(fich, "%d ", &info)) == 1)
    {
        // Creamos el nuevo nodo
        nuevo = malloc(sizeof(tipoNodo));
        if(nuevo == NULL)
        {
            fclose(fich);
            return -1;
        }
		nuevo->info = info;
		nuevo->sig = NULL;

        // Insercion en la lista ordenada
        tipoNodoRef temp, anterior, actual;
        if (*raiz == NULL || (*raiz)->info >= info) // Lista vacía o la raíz es mayor que la info
        {
			nuevo->sig = *raiz;
            *raiz = nuevo;
        }else
		{
			anterior = *raiz;
			actual = (*raiz)->sig;
			while (actual != NULL && actual->info < info)
			{
				anterior = actual;
				actual = actual->sig;
			}
			nuevo->sig = actual;
			anterior->sig = nuevo;
		}
        
    }

    if (res != EOF)
    {
        tipoNodoRef aBorrar;
        while(*raiz != NULL)
        {
            aBorrar = *raiz;
            *raiz = (*raiz)->sig;
            free(aBorrar);
        }
        fclose(fich);
        return -3;
    }

    fclose(fich);
    return 0;
}

