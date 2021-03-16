#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[]) {

    char *p;
    int min=2147483647,num;
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
            if (num<min) min = num;
        }
    }
    printf("Mínimo: %d\n", min);

    exit(EXIT_SUCCESS);
}