#include <pthread.h>
#include <stdio.h>

//Usamos las estructura para pasar parámetros a el hilo
struct parametros_hilo{
    char caracter; //Caracter a imprimir
    int contador; //Número de veces que se desea imprimir
};

//Esta función imprime un número de caracteres a la salida de error, como lo indica el parámetro de la función
void* imprimir_caracter(void* parametros){
    //Se hace un cast al tipo de dato correcto que le entra en el parámetro
    struct parametros_hilo* p = (struct  parametros_hilo*) parametros;
    int i;
    for (i = 0; i < p->contador; i++)
    {
        fputc(p->caracter, stderr);
    }
    return NULL;
}

int main(){
    pthread_t id_hilo_1;
    pthread_t id_hilo_2;
    struct parametros_hilo hilo1_param;
    struct parametros_hilo hilo2_param;

    //Crea un hilo para imprimir 30000 'x'
    hilo1_param.caracter = 'x';
    hilo1_param.contador = 30000;
    pthread_create(&id_hilo_1, NULL, &imprimir_caracter, &hilo1_param);

    //Crea un hilo para imprimir 20000 'o'
    hilo2_param.caracter = 'o';
    hilo2_param.contador = 20000;
    pthread_create(&id_hilo_2, NULL, &imprimir_caracter, &hilo2_param);

    pthread_join (id_hilo_1, NULL);
	pthread_join (id_hilo_2, NULL);
    
    return 0;    
}