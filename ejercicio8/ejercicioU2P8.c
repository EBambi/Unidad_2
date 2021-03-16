#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    pid_t pid_hijo;
    char puntoExe[3][15] = {"./promedio.exe", "./min.exe", "./max.exe"};
    for (int i = 0; i < 3; i++)
    {
        pid_hijo = fork();
        if (pid_hijo == 0){
            execv(puntoExe[i],argv);
        }
        else wait(NULL);
    }
    return 0;
}