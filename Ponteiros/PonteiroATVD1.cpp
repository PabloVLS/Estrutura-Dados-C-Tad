/*1. Escreva um programa que contenha duas variaveis inteiras.
Leia essas vari�veis do teclado. Em seguida, compare seus endere�os e exiba o conteudo do maior endere�o.*/


#include <stdio.h>


void teste(int *a, int *b){
    printf("%d %d",a,b);
    if(a>b){
        printf("%d",*a);
    }else{
        printf("%d",*b);
    }
}

int main(){
    int a,b;

    scanf("%d %d",&a, &b);

    teste(&a,&b);

    return 0;
}
