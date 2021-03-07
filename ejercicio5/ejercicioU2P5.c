#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[]) {

    char *p;
    int num, vNums[argc], prom=0, min=1000000, max=0;
    long conv;

    errno = 0;

    for (int i = 1; i < argc; i++)
    {
        conv = strtol(argv[i], &p, 10);

        if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
            printf("Argumento no válido\n");
        } else {
            num = conv;
            //printf("%d\n", num);
            vNums[i-1] = num;
            prom = prom + num;
            if (num<min) min = num;
            if (num>max) max = num;
        }
    }
    printf("El promedio es de %d\n",prom/(argc-1));
    printf("El int máx fue %d\nEl int min fue %d\n",max,min);
    printf("Este es el vector de los argumentos\n");
    for (int i = 0; i < argc-1; i++)
    {
        printf("%d\n",vNums[i]);
    }
    
    exit(EXIT_SUCCESS);
}