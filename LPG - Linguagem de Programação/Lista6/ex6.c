
#include <stdio.h>

void max_vetor(float vet[], int tam, float *pMax, int *pIndice);

int main(){
    float v[] = {2, 3, 1, 5, 4}, max;
    int indice;
    max_vetor(v, 5, &max, &indice);
    printf("max : %.2f\nindice: %d", max, indice);
    return 0;
}

void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
    int i, indice = 0;
    float max = vet[0];
    for ( i = 0; i < tam; i++ ) 
        if ( vet[i] > max ) {
            max = vet[i];
            indice = i;
        }
    *pMax = max;
    *pIndice = indice;
}