/*2. Crie um programa que contenha um array de
float contendo 10 elementos. Imprima o endere�o de cada posi��o do array.*/


#include <stdio.h>


void teste(float *vetor){
    printf("%d \n",vetor);
}

int main(){
    float vetor[10];

    for(int i=0; i< 10; i++){
        scanf("%lf",&vetor[i]);
        teste(&vetor[i]);
    }


    return 0;
}
