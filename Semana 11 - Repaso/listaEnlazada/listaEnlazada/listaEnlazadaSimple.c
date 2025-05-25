//
//  listaEnlazadaSimple.c
//  listaEnlazadaSimple


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazadaSimple.h"

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
crearVacia(ListaEnlazadaRef raiz)
{
	*raiz = NULL;
	return 0;
}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
estaVacia(ListaEnlazada raiz)
{
	if (raiz == NULL) return 1;
	else return 0;

}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
tipoNodoRef
creaNodo(tipoInfoRef info)
{
	tipoNodo *nuevo; // Es lo mismo que tipoNodoRef nuevo;
	nuevo = malloc(sizeof(tipoNodo));
	if (nuevo == NULL){
#ifdef DEBUG
		fprintf(stderr, "ERROR reservando la memoria\n");
#endif
		return NULL;
	}

	nuevo->info = *info;
	nuevo->sig = NULL;
	return nuevo;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef nuevo, indice, anterior;
	if ((nuevo = creaNodo(info)) == NULL)
	{
#ifdef DEBUG
		fprintf(stderr, "ERROR creando el nodo\n");
#endif
		return -1;
	}

	// Caso de que la lista esta vacía
	if (estaVacia(*raiz))
	{
		*raiz = nuevo;
	}else { // Si no esta vacía
		anterior = NULL;
		indice = *raiz;
		while (indice != NULL && indice != pos)
		{
			anterior = indice;
			indice = indice->sig;
		}
		if (pos == NULL) // Si pos es NULL el bucle termina cuando indice ==NULL
		{
			anterior->sig = nuevo;
		}
		else if (indice != NULL) // Pos tampoco es NULL, la posición existe, el bucle termina porque indice==pos, insertamosd después de indice
		{
			nuevo->sig = indice->sig; // O lo mismo que nuevo->sig = pos->sig
			indice->sig = nuevo; // O lo mismo que pos->sig = nuevo
		}
		else
		{
#ifdef DEBUG
			fprintf(stderr, "ERROR posición no valida\n");
#endif
			free(nuevo);
			return -2;
		}
	}
	return 0;
}


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef nuevo, indice, anterior;
	if ((nuevo = creaNodo(info)) == NULL)
	{
#ifdef DEBUG
		fprintf(stderr, "ERROR creando el nodo\n");
#endif
		return -1;
	}

	if (estaVacia(*raiz) || pos == NULL || pos == *raiz)
	{
		nuevo->sig = *raiz;
		*raiz = nuevo;
	/*}else
	{
		anterior = NULL;
		indice = *raiz;
		while (indice != NULL && indice != pos)
		{
			anterior = indice;
			indice = indice->sig;
		}
		if (indice != NULL)
		{
			nuevo->sig = indice;
			anterior->sig = nuevo;
		}
		else
		{
#ifdef DEBUG
			fprintf(stderr, "ERROR posición no valida\n");
#endif
			free(nuevo);
			return -2;
		}
	}*/
	}else // Sin usar indice
	{
		anterior = *raiz;
		while (anterior != NULL && anterior->sig != pos)
		{
			anterior = anterior->sig;
		}
		if (indice != NULL)
		{
			nuevo->sig = anterior->sig;
			anterior->sig = nuevo;
		}
		else
		{
	#ifdef DEBUG
			fprintf(stderr, "ERROR posición no valida\n");
	#endif
			free(nuevo);
			return -2;
		}
	}
	return 0;
}



/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	return insertarAntesDeNodo(raiz, *raiz, info); // O NULL
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	// Comprobar si esta vacia, si lo esta añado y si no compruebo que indice->sig no sea NULL si lo es se añade
	// Otra opcion seria llamadno a la funcion insertarDespuesDeNodo
	return insertarDespuesDeNodo(raiz, NULL, info);
}

/*
 * Esta función recibe una lista (por referencia), un índice entero y una
 * variable de tipoInfo por referencia. Debe insertar un nuevo nodo
 * en la posición indicada por el índice entero (implica recorrido contando
 * nodos hasta el valor indicado por indice). Ojo, hay que garantizar que 
 * esa posición existe, es decir, que si la lista tiene 5 nodos, (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4, 5 (la posición 5
 * es equivalente a añadir al final).
 * Si la posición no existe, no se puede hacer la inserción (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 6 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque implique 
 * ineficiencias (recorridos adicionales de la lista enlazada). Opcional 
 * escribir una versión eficiente que no implique repetir recorridos.
 */
int
insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info)
{
	if (indice < 0) return -1;

    // Caso especial: insertar al comienzo
    if (indice == 0) {
        return insertarNodoComienzo(raiz, info);
    }

    tipoNodoRef actual = *raiz;
    int posicion = 0;

    // Avanzar hasta el nodo anterior a la posición deseada
    while (actual != NULL && posicion < indice - 1) {
        actual = actual->sig;
        posicion++;
    }

    if (actual == NULL) {
        // Índice fuera del rango válido
        return -1;
    }

    // Insertar después del nodo actual
    return insertarDespuesDeNodo(raiz, actual, info);

}


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos) {
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



/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
eliminarNodoComienzo(ListaEnlazadaRef raiz)
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


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
eliminarNodoFinal(ListaEnlazadaRef raiz)
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

/*
 * Esta función recibe una lista (por referencia) y un índice entero
 * Debe eliminar el nodo situado en en la posición indicada por el
 * índice entero (implica recorrido contando nodos hasta el valor
 * indicado por indice). Ojo, hay que garantizar que
 * esa posición existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4.
 * Si la posición no existe, no se puede hacer la eliminación (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 5 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque 
 * implique ineficiencias (recorridos adicionales de la lista enlazada). 
 * Opcional escribir una versión eficiente que no implique repetir recorridos.
 */
int
eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice)
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



/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
liberarListaEnlazada(ListaEnlazadaRef raiz)
{
	tipoNodoRef aBorrar;
	/*while (*raiz != NULL)
	{
		aBorrar = *raiz;
		*raiz = (*raiz)->sig;
		free(aBorrar);
	}*/
	while (!estaVacia(*raiz))
	{
		aBorrar = *raiz;
		*raiz = (*raiz)->sig;
		free(aBorrar);
	}
}


/********************************************************************
 *                                                                  *
 * Las cuatro funciones que vienen a continuación dependen de cómo  *
 * está definido el tipo de dato tipoInfo. No es lo mismo mostrar   *
 * por pantalla el contenido de los datos almacenados en una lista  *
 * enlazada si éste es de tipo entero, o si se trata de un registro.*
 * Adicionalmente, y para que el alumno no pierda el tiempo         *
 * en implementar funciones que aportan poco desde un punto de vista*
 * docente, se proporcionan ya implementadas las funciones          *
 * mostrarListaEnlazada() y crearListaValoresAleatorios(). Las otras*
 * dos son sencillas y se dejan al alumno su implementación.        *
 *                                                                  *
 *******************************************************************/

/*
 * Esta función recibe una lista (por referencia) y un índice entero
 * Debe devolver la información almacenada en el nodo situado en la 
 * posición indicada por el índice entero (implica recorrido contando nodos 
 * hasta el valor indicado por indice). Ojo, hay que garantizar que
 * esa posición existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4.
 * Si la posición no existe, no se puede devolver nada (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 5 tampoco).
 * IMPORTANTE: tipoInfo es, en este caso particular, un entero. Aunque
 * la dependencia es pequeña, si existe. ¿Cómo se devuelve el código de error
 * en caso de no existir la posición indicada por el parámetro indice?. Si 
 * tipoInfo es un int es sencillo, si es un registro también, pero ya es
 * diferente implementación.
 */
tipoInfo
devolverInfoPosicionIndice(ListaEnlazada raiz, int indice)
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


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info)
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

// Funciones con ficheros
int guardarListaEnlazadaTexto(ListaEnlazada raiz, char *nombreFichero)
{
	FILE *fichero;           // Para abrir y escribir en el fichero de texto
    tipoNodoRef actual;      // Para recorrer la lista nodo a nodo
    int contador;            // Para contar cuántos nodos se han escrito correctamente
    
	if (raiz == NULL) return -1;
	if (nombreFichero == NULL) return -1;

	fichero = fopen(nombreFichero, "w");
	if (fichero == NULL) return -1;

	actual = raiz;
	contador = 0;

	while(actual != NULL)
	{
		fprintf(fichero, "%d ", actual->info);
		contador++;
		actual = actual->sig;
	}

	fclose(fichero);
	return contador;
}
int cargarListaEnlazadaTexto (ListaEnlazadaRef raiz, char *nombreFichero)
{
	FILE *fichero;          // Para abrir y leer el fichero de texto
    tipoInfo valor;         // Para almacenar cada entero leído del fichero
    int leidos;             // Para almacenar el resultado de fscanf y detectar errores de lectura
    int contador = 0;           // Para contar cuántos nodos se insertaron correctamente

	if (raiz == NULL) return -1;
	if (nombreFichero == NULL) return -1;

	// Creamos una lista vacia
	crearVacia(raiz);
	
	// Abrimos el fichero
	fichero = fopen(nombreFichero, "r");
	if (fichero == NULL) return -2;

	while((leidos = fscanf(fichero, "%d ", &valor)) == 1)
	{
		if(insertarOrdenada(raiz, &valor) != 0)
		{
			liberarListaEnlazada(raiz);
			fclose(fichero);
			return -2;
		}
		contador++;	
	}

	if (leidos != EOF)
	{
		fclose(fichero);
		return -2;
	}

	fclose(fichero);
	return contador;
	
}
