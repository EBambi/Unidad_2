#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
    int hijo=0, facto=1;
    pid_t pid_hijo;
    printf("Soy el padre: %d\n",(int)getpid());

    for (int i = 1; i <= 3; i++)
    {
        hijo++;
        pid_hijo = fork();
        if(pid_hijo == 0)
        {
            printf("Hola soy el hijo(%d): %d\n",hijo,(int)getpid());
            hijo++;
            break;
        }
        else{ 
            wait(NULL);
        }
    }
    if(pid_hijo == 0)
    {
        for (int i = 1; i <= 10; i++)
        {
            if ((int)pid_hijo == 0){
                facto = facto*i;
                printf("HIJO%d: fact(%d) = %d\n",hijo-1, i, facto);
            }
        }
    }
    printf("Terminó proceso número: %d\n",(int)getpid());
    exit(EXIT_SUCCESS);
}