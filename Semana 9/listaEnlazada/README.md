**Como pasar una lista enlazada por parámetro a una función**  
Rellenamos nuestra lista en main  
main()
{
    tipoNodo lista;
    .
    .
    .
    funcion(lista); // Se pasa la lista por valor -> un puntero al primer elemento de la lista (no modificamos la lista)
    funcion(&lista); // Para pasarla la lista por referencia  
}
######
// tipoNodo * raiz == listaEnlazada raiz (valor que hay en los ejemplos de esta sesion)  
// Aqui si modificamos raiz no será modificada la lista  
// Para poder modificarla habría que pasar la lista por referencia, para que raiz apunte a la direccion de memoria de lista es: tipoNodo ** raiz (un puntero a lista) == tipoListaRef raiz 
// lista == *raiz  
// Acceder a los datos de la lista sería (*raiz)->info  
######
funcion(tipoNodo ** raiz)  
{  
    nuevo = maloc()....
    nuevo->sig = *raiz;
    raiz = nuevo;
}  

**Examen**
Insertar Ordenada suele caer  
Con dos limites inf y superior y recorrer los nodos del campo info trabajar con ellos  
Por ejemplo mcoger los que valen 1000 y 3000 ir viendo los valores y sacandolos a otra lista  
Insertarlos en orden segun esta lista  