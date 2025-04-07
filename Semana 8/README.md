En memoria dinámica, si accedemos a un valor apuntado con un puntero:  
    matFloat * temp; 
Accedemos a los valores de estos mediante:  
    temp->m;  
    temp->numCol;  
    tem->numFil;  

**En matrices**
    tamp->m[i * temp->numCol + j]; // Le sumo al indice el numero de elementos anteriores. Elegimos el numero de filas y le sumamos el numero de columnas    
    Malloc siempre un puntero al tipo de elemento por eso m en este caso debe ser un puntero a float

**Funcion Obtener Máximo**  
    Suele caer en examen

Si nuestro puntero es:  
    float(*m)[COL]  
Se accede a sus valores por:  
    temp->m[i][j];  

Si nuestro puntero es:   
    float **m  
Acceder a sus valores:
    temp->m[i][j]  
Lo mas complicado es su reserva de memoria. Debo reservar 3 veces memoria para la estructura, la fila y luego para la columna
