/*3. Escreva uma fun��o que dado um n�mero real passado como par�metro,
retorne a parte inteira e a parte fracion�ria deste n�mero. Escreva um programa que chama esta fun��o.*/

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
