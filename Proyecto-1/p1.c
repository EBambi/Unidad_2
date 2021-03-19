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

    for (q=1;q<i-1;q++)
    {
        for (j=0; j < i-1-q ;j++)
        {
            if (vals[j] > vals[j+1])//Condicion mayor-menor
            {
                temp=vals[j];
                vals[j]=vals[j+1];
                vals[j+1]=temp;

                strcpy(tempC,keys[j]);
                strcpy(keys[j],keys[j+1]);
                strcpy(keys[j+1],tempC);
            }
        }
    }
    outFile = fopen(argv[2],"w");
    for (int r = 0; r < i; r++)
    {
        fprintf(outFile,"%s %d\n",keys[r],vals[r]);
    }
    fclose(outFile);

    return EXIT_SUCCESS;
}