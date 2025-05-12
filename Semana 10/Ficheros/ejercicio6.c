#include <stdio.h>

int main (void)
{
    FILE *fp, *fp2;
    char c;
    int estadistica[256] = {0};
    int i;

    fp = fopen("frases.txt","r");
    if (fp == NULL)
    {
        fprintf(stderr, "ERROR abriendo fichero.\n");
        return -1;
    }
    fp2 = fopen("copia.txt","w");
    if (fp2 == NULL)
    {
        fprintf(stderr, "ERROR abriendo fichero.\n");
        return -1;
    }

   /* while ((c = fgetc(fp)) != EOF)
    {
        fprintf(stdout, "%c", c);
        fprintf(fp2, "%c", c);
    }*/
    
    c = fgetc(fp);
    while(!feof(fp))
    {
        fprintf(stdout, "%c", c);
        fprintf(fp2, "%c", c);
        estadistica[c]++; // Para ver cuantas veces a aparecido cada caracter en el codigo ascii
        c = fgetc(fp);
    }

    for (i = 0; i < 256; i++)
    {
        printf("%d\t%c\t%d\n", i, i, estadistica[i]);
    }

    fclose(fp);
    fclose(fp2);
    return 0;
}