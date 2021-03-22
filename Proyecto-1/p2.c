#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inFile, *outFile;
int ch;

int main(int argc, char const *argv[]) {
    int i=0, vals[100], valor, n=100, q, j, temp;
    char keys[100][20], key[20], tempC[20];

    inFile = fopen(argv[1],"r");
    if(inFile == NULL){
        printf("No se puede abrir %s\n",argv[1]);
        exit(8);
    }
    while (!feof(inFile))
    {
        if(ch != EOF){
            fscanf(inFile,"%s %d",key,&vals[i]);
            strcpy(keys[i],key);
            //printf("Clave: %s Valor: %d\n",keys[i],vals[i]);
            i++;
        }
    }
    fclose(inFile);
    outFile = fopen(argv[3],"w");
    for (int r = i-1; r >= 0; r--)
    {
        fprintf(outFile,"%s %d\n",keys[r],vals[r]);
    }
    fclose(outFile);

    return EXIT_SUCCESS;
}