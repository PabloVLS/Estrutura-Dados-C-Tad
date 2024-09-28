/*2. Crie um programa que contenha um array de
float contendo 10 elementos. Imprima o endereço de cada posição do array.*/


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
