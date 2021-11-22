#include <stdio.h>

float calculaMediaPonderada(float array[], int size){
    float total = 0;
    for(int i=0;i<size;i++){
        total+=array[i];
    }
    return total/size; 
}

float calculaMS(float media){
    return media*1.1;
}

float calculaMI(float media){
    return media*0.9;
}

int lista2A(float array[], int size, float ms, float mi){
    int cont = 0;
    for(int i=0; i<size; i++){
        if(array[i]<mi || array[i]>ms){
            cont++;
        }
    }
    return cont*100/size;
}

int main(){

    float notas[] = {10.0, 6.8, 8.5, 7.0, 6.8, 7.5, 8.2, 10.0, 10.0,8.5, 7.0, 9.5, 9.5};
    float mediaPonderada, ms, mi;

    mediaPonderada = calculaMediaPonderada(notas, sizeof(notas)/4);
    ms = calculaMS(mediaPonderada);
    mi = calculaMI(mediaPonderada);
    
    printf("prob: %d%%\n", lista2A(notas, sizeof(notas)/4, ms, mi));

    printf("media ponderada: %.2f\nMS: %.2f\nMI: %.2f\n", mediaPonderada, ms, mi);

    return 0;
}