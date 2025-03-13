#include <stdio.h>

int main(){
    int vetor[10] = {5,6,4,22,33,0,9,2,10,20};

    for(int i=0; i < 10; i++){
        for(int j=0; j < 10-i; j++){
            if(vetor[j]> vetor[j+1]){
                int aux = vetor[j];
                vetor[j]= vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }

    for(int i = 0 ; i < 10; i++){
            printf("%d ",vetor[i]);
    }

}
