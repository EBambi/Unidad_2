#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[]) {

    char *p;
    int max=0,num;
    long conv;
    errno = 0;

    for (int i = 1; i < argc; i++)
    {
        conv = strtol(argv[i], &p, 10);
        if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN)
        {
            printf("Argumento no válido\n");
        }
        else
        {
            num = conv;
            if (num>max) max = num;
        }
    }
    printf("Mínimo: %d\n", max);

    exit(EXIT_SUCCESS);
}