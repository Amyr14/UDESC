
#include <stdio.h>

void max_min(int vet[], int tam, int *pMin, int *pMax);

int main(){
    int vet[5] = {3, 1, 7, 2, 4};
    int max, min;
    max_min(vet, 5, &min, &max);
    printf("max : %d\nmin : %d", max, min);
    return 0;
}

void max_min(int vet[], int tam, int *pMin, int *pMax){
    int i, maior = vet[0], menor = vet[0];
    for ( i = 0; i < tam; i++ ) 
        if ( vet[i] > maior )
            maior = vet[i];
    for ( i = 0; i < tam; i++ )
        if ( vet[i] < menor )
            menor = vet[i];
    *pMax = maior;
    *pMin = menor;
}