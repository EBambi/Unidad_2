#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

FILE *inFile;
int ch;

int main(int argc, char *argv[])
{
    pid_t pid_hijo;
    char puntoExe[3][15] = {"./p1.exe", "./p2.exe"};
    char c;
    for (int i = 0; i < 2; i++)
    {
        pid_hijo = fork();
        if (pid_hijo == 0){
            execv(puntoExe[i],argv);
        }
    }
    wait(NULL);
    wait(NULL);
    for (int i = 2; i < 4; i++)
    {
        inFile = fopen(argv[i],"r");
        if(inFile == NULL){
            printf("No se puede abrir %s\n",argv[i]);
            exit(8);
        }
        c = fgetc(inFile);
        while (!feof(inFile))
        {
            printf("%c",c);
            c=fgetc(inFile);
        }
        fclose(inFile);
        printf("----------------------\n");
    }
    return 0;
}