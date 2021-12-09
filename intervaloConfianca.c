#include <stdio.h>
#include <math.h>

void leArr(float* arr, int size){
    printf("\n\tNOTAS: [");
    for(int i=0;i<size;i++){
        printf(" %.2f;", arr[i]);
    }
    printf(" ]\n");
}

int main(){

    float notas[] = {10.0, 6.8, 8.5, 7.0, 6.8, 7.5, 8.2, 10.0, 10.0,8.5, 7.0, 9.5, 9.5};
    float notasB[] = {10.0, 8.5, 7.0, 7.5, 8.2, 10.0, 10.0,8.5, 7.0, 9.5, 9.5};
    int tamanhaAmostra=sizeof notas/sizeof notas[0], gl=tamanhaAmostra-1;
    int tamanhaAmostraB=sizeof notasB/sizeof notasB[0], glB=tamanhaAmostraB-1;
     
    float significancia=0.05, media=8.4, mediaB=8.7, desvioPadrao=1.29, desvioPadraoB=1.17, tc=2.179, tcB=2.201, intervaloConfianca[2], intervaloConfiancaB[2]; 
    float erroDeEstimativa=tc*desvioPadrao/sqrt(tamanhaAmostra);
    float erroDeEstimativaB=tcB*desvioPadraoB/sqrt(tamanhaAmostraB);
    intervaloConfianca[0]=media+erroDeEstimativa;
    intervaloConfianca[1]=media-erroDeEstimativa;
    intervaloConfiancaB[0]=mediaB+erroDeEstimativaB;
    intervaloConfiancaB[1]=mediaB-erroDeEstimativaB;

    printf("\n\t\t\t\t\t\tLISTA 4\n\n");
    printf("Questao A)\n");
    leArr(notas, tamanhaAmostra);
    printf("\tN = %d\n", tamanhaAmostra);
    printf("\tGL = %d\n", gl);
    printf("\tsignificancia = %.2f\n", significancia);
    printf("\tMedia = %.2f\n", media);
    printf("\tDesvio Padrao = %.2f\n", desvioPadrao);
    printf("\tTC = %.3f\n", tc);
    printf("\te(Erro de estimativa) = Tc * S / raiz(N)\n\te = %.2f\n", erroDeEstimativa);
    printf("\tIC(intervalo de confianca) = Media +- e\n\tIC = {%.2f; %.2f}\n", intervaloConfianca[0], intervaloConfianca[1]);

    printf("\nQuestao B)\n");
    leArr(notasB, tamanhaAmostraB);
    printf("\tN = %d\n", tamanhaAmostraB);
    printf("\tGL = %d\n", glB);
    printf("\tsignificancia = %.2f\n", significancia);
    printf("\tMedia = %.2f\n", mediaB);
    printf("\tDesvio Padrao = %.2f\n", desvioPadraoB);
    printf("\tTC = %.3f\n", tcB);
    printf("\te(Erro de estimativa) = Tc * S / raiz(N)\n\te = %.2f\n", erroDeEstimativaB);
    printf("\tIC(intervalo de confianca) = Media +- e\n\tIC = {%.2f; %.2f}\n", intervaloConfiancaB[0], intervaloConfiancaB[1]);
    printf("Aluno: Cristiano Antonio Caverzan\nCadastro: 2011100017\n\n");

    return 0;
}