#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inFile;
int ch;

int main(int argc, char const *argv[]) {
    int i=0, edad[100], valor, n=100, q, j, temp;
    char nombres[100][20], nombre[20], ocupaciones[100][20], ocupacion[20], tempC[20];

    inFile = fopen(argv[1],"r");
    if(inFile == NULL){
        printf("No se puede abrir %s\n",argv[1]);
        exit(8);
    }
    while (!feof(inFile))
    {
        if(ch != EOF){
            fscanf(inFile,"%s %s %d",nombre,ocupacion,&edad[i]);
            strcpy(nombres[i],nombre);
            strcpy(ocupaciones[i],ocupacion);
            printf("%s %s %d\n",nombres[i],ocupaciones[i],edad[i]);
            i++;
        }
    }
    fclose(inFile);
    return EXIT_SUCCESS;
}