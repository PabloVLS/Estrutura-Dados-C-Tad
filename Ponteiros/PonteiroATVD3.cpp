/*3. Escreva uma função que dado um número real passado como parâmetro,
retorne a parte inteira e a parte fracionária deste número. Escreva um programa que chama esta função.*/

#include <stdio.h>

void teste(float a,int *inteiro, float *fracao){
    *inteiro = (int)a;
    *fracao = (a-*inteiro)*100;

}



int main(){

    float a,fracao;
    int inteiro;
    scanf("%f",&a);
    teste(a,&inteiro,&fracao);
    printf("%d \n%0.f\n",inteiro , fracao);



    return 0;
}
