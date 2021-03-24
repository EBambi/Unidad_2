#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

FILE *inFile;
int ch, i=0;

struct persona *bDatos;

struct persona
{
    char nombre[20];
    char ocupacion[20];
    int edad;
};

void* ordenInverso(void* file){
    FILE *outFile;
    outFile = fopen(file,"w");
    for (int r = i-1; r >= 0; r--)
    {
        fprintf(outFile,"%s %s %d\n",(bDatos+r)->nombre,(bDatos+r)->ocupacion,(bDatos+r)->edad);
        // printf("%s %s %d\n",(bDatos+r)->nombre,(bDatos+r)->ocupacion,(bDatos+r)->edad);
    }
    fclose(outFile);
    return NULL;
}

void* ordenAlfa(void* file){
    FILE *outFile;
    char temp[20];
    int tempE, q, j;
    outFile = fopen(file,"w");
    for(int j=0; j<i-1; j++) {
        for(int q=j+1; q<i; q++) {
            if(strcmp((bDatos+j)->ocupacion, (bDatos+q)->ocupacion) > 0) {

                strcpy(temp,(bDatos+j)->ocupacion);
                strcpy((bDatos+j)->ocupacion,(bDatos+q)->ocupacion);
                strcpy((bDatos+q)->ocupacion,temp);

                strcpy(temp,(bDatos+j)->nombre);
                strcpy((bDatos+j)->nombre,(bDatos+q)->nombre);
                strcpy((bDatos+q)->nombre,temp);

                tempE = (bDatos+j)->edad;
                (bDatos+j)->edad = (bDatos+q)->edad;
                (bDatos+q)->edad = tempE;
            }
        }
    }
    for (int r = 0; r < i; r++)
    {
        fprintf(outFile,"\n%s %s %d",(bDatos+r)->ocupacion,(bDatos+r)->nombre,(bDatos+r)->edad);
    }
    fclose(outFile);
    return NULL;
}

int main(int argc, char const *argv[]) {
    int edad[100];
    char nombres[100][20], nombre[20], ocupaciones[100][20], ocupacion[20], tempC[20],c;
    FILE *salida;

    bDatos = malloc(sizeof(struct persona)*100);

    inFile = fopen(argv[1],"r");
    if(inFile == NULL){
        printf("No se puede abrir %s\n",argv[1]);
        exit(8);
    }
    while (!feof(inFile))
    {
        if(ch != EOF){
            fscanf(inFile,"%s %s %d",(bDatos+i)->nombre,(bDatos+i)->ocupacion,&(bDatos+i)->edad);
            i++;
        }
    }
    fclose(inFile);
    printf("-----Estructura-----\n");
    for (int j = 0; j < i; j++)
    {
        printf("%s %s %d\n",(bDatos+j)->nombre,(bDatos+j)->ocupacion,(bDatos+j)->edad);
    }

    pthread_t id_hilo_1;
    pthread_t id_hilo_2;

    char nombre1[20], nombre2[20];
    strcpy(nombre1,argv[2]);
    strcpy(nombre2,argv[3]);

    pthread_create(&id_hilo_1, NULL, &ordenInverso, &nombre1);
    pthread_create(&id_hilo_2, NULL, &ordenAlfa, &nombre2);

    pthread_join (id_hilo_1, NULL);
    pthread_join (id_hilo_2, NULL);

    salida = fopen(argv[2],"r");
    if(salida == NULL){
        printf("No se puede abrir %s\n",argv[2]);
        exit(8);
    }
    printf("-----Datos Invertidos-----\n");
    while (!feof(salida))
    {
        printf("%c",c);
        c=fgetc(salida);
    }
    fclose(salida);

    salida = fopen(argv[3],"r");
    if(salida == NULL){
        printf("No se puede abrir %s\n",argv[3]);
        exit(8);
    }
    printf("-----Datos Ordenados por Ocupación-----");
    while (!feof(salida))
    {
        printf("%c",c);
        c=fgetc(salida);
    }
    fclose(salida);

    return EXIT_SUCCESS;
}