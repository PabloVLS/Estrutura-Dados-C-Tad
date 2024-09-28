/*4. Implemente uma função que calcule a
área da superfície e o volume de uma esfera de raio R. A area da superfície e o volume são dados, respectivamente, por:

A = 4 * p * R^2
V = 4/3 * p * R^3
*/
#include <stdio.h>
#include <math.h>
#define pi 3.14

void teste(float R, float *volume, float *area){
    *area = 4*pi*pow(R,2);
    *volume = (4.0/3.0) * pi * (R*R*R);

}


int main(){
    float R,area, volume;


    scanf("%f",&R);
    teste(R,&volume,&area);
    printf("Area= %.2f\nVolume= %.2f",area, volume);
    return 0;
}
