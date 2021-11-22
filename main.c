#include <stdio.h>

float calculaMediaPonderada(float array[], int size){
    float total = 0;
    for(int i=0;i<size;i++){
        total+=array[i];
    }
    return total/size; 
}

float calculaMS(float media){
    printf("MS = MEDIA PONDERADA + 10%%\nMS = %.2f * 1.1 = %.2f\n", media, media*1.1);
    return media*1.1;
}

float calculaMI(float media){
    printf("MI = MEDIA PONDERADA - 10%%\nMI = %.2f * 0.9 = %.2f\n", media, media*0.9);
    return media*0.9;
}

float lista2A(float array[], int size, float ms, float mi){
    int cont = 0;
    for(int i=0; i<size; i++){
        if(array[i]<mi || array[i]>ms){
            cont++;
        }
    }
    return cont*100/size;
}

float lista2B(float array[], int size, float nota){
    int cont = 0;
    for(int i=0;i<size;i++){
        if(array[i]==nota){
            cont++;
        }
    }
    cont--;
    return cont*100/(size-1);
}

float calculaMP(float array[], int size){
    float cont=0;
    printf("MEDIA PONDERADA = (");
    for(int i=0;i<size;i++){
        cont+=array[i];
        if(i==(size-1)){
            printf("%.1f) / %d = %.2f\n", array[i], size, cont/size);
        }else{
            printf("%.1f + ", array[i]);
        }
    }
    return cont/size;
}

void lista2_A(float array[], int size){
    float mp, ms, mi;
    mp = calculaMP(array, size);
    ms = calculaMS(mp);
    mi = calculaMI(mp);
}

int main(){

    float notas[] = {10.0, 6.8, 8.5, 7.0, 6.8, 7.5, 8.2, 10.0, 10.0,8.5, 7.0, 9.5, 9.5};
    
    lista2_A(notas, sizeof(notas)/4);
    /*
    float mediaPonderada, ms, mi;

    mediaPonderada = calculaMediaPonderada(notas, sizeof(notas)/4);
    ms = calculaMS(mediaPonderada);
    mi = calculaMI(mediaPonderada);
    
    printf("media ponderada: %.2f\nMS: %.2f\nMI: %.2f\n", mediaPonderada, ms, mi);
    printf("probA: %.2f%%\n", lista2A(notas, sizeof(notas)/4, ms, mi));
    printf("probB: %.2f%%\n", lista2B(notas, sizeof(notas)/4, 10));
    */

    return 0;
}