#include <stdio.h>

float calculaMS(float media){
    printf("\tMS = MEDIA PONDERADA + 10%%\n\tMS = %.2f * 1.1 = %.2f\n", media, media*1.1);
    return media*1.1;
}

float calculaMI(float media){
    printf("\tMI = MEDIA PONDERADA - 10%%\n\tMI = %.2f * 0.9 = %.2f\n", media, media*0.9);
    return media*0.9;
}

float calculaMP(float array[], int size){
    float cont=0;
    printf("\tMEDIA PONDERADA = (");
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
    float mp, ms, mi, prob;
    printf("Questao A)\n");
    mp = calculaMP(array, size);
    ms = calculaMS(mp);
    mi = calculaMI(mp);
    int contMS=0, contMI=0;
    for(int i=0;i<size;i++){
        if(array[i]>ms){
            contMS++;
        }
        else if(array[i]<mi){
            contMI++;
        }
    }
    prob = (contMI+contMS)*100/size;
    printf("\tprobabilidade que uma nota sorteada da amostra seja menor que MI ou maior que MS:\n");
    printf("\tQuantidade de notas menores que MI: %d\n", contMI);
    printf("\tQuantidade de notas maiores que MS: %d\n", contMS);
    printf("\tQuantidade total de notas: %d\n", size);
    printf("\tCalculo de porcentagem: \n\t\t(%d+%d)*100/(%d) = %.2f%%\n", contMS, contMI, size, prob);
}

void lista2_B(float array[], int size, float nota){
    printf("\nQuestao B)\n");
    int cont = 0;
    float prob;
    for(int i=0;i<size;i++){
        if(array[i]==nota){
            cont++;
        }
    }
    cont--;
    prob = cont*100/(size-1);
    printf("\tNota repetida: %.1f\n", nota);
    printf("\tNumero de notas iguais a repetida: %d\n", cont);
    printf("\tCalculo de porcentagem: \n\t\t%d*100/(%d-1) = %.2f%%\n", cont, size, prob);
}

int main(){

    float notas[] = {10.0, 6.8, 8.5, 7.0, 6.8, 7.5, 8.2, 10.0, 10.0,8.5, 7.0, 9.5, 9.5};
    float notaRepetida=10;
    
    printf("\n\t\t\t\t\t\tLISTA 2\n\n");
    lista2_A(notas, sizeof(notas)/4);
    lista2_B(notas, sizeof(notas)/4, notaRepetida);
    
    return 0;
}