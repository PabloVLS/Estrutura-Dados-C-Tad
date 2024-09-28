/*Crie uma função que receba por parâmetro um vetor de números inteiros, o
tamanho do vetor e os endereços de duas variáveis inteiras (que podemos chamar de min e max).
Ao passar essas variáveis para a função seu programa deverá analisar qual é o maior e o menor
elemento do vetor e depositar esses elementos nas variáveis do parâmetro.*/


#include <stdio.h>

void teste(int *vetor, int *mini, int *maxi){

        if(*vetor> *maxi){
            *maxi = *vetor;
        }
        if(*vetor < *mini){
            *mini = *vetor;
        }
}

int main(){
    int a,b,tamanho,mini=999999,maxi=-9999999;
    int vetor[10];
    scanf("%d",&tamanho);
    for(int i = 0; i <tamanho;i++){
        scanf("%d",&vetor[i]);
        teste(&vetor[i],&mini, &maxi);
    }

    //teste(&vetor[i], tamanho,&mini,&maxi);
    printf("Menor:%d\nMaior:%d",mini,maxi);


    return 0;
}
