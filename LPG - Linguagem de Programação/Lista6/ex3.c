
#include <stdio.h>

void calcula_circulo(float raio, float *pPerimetro, float *pArea);

int main(){
    float raio, perimetro, area;
    printf("Digite o raio: ");
    scanf("%f", &raio);
    calcula_circulo(raio, &perimetro, &area);
    printf("Perimetro: %.2f", perimetro);
    printf("\nArea: %.2f", area);
    return 0;
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    *pPerimetro = 2 * 3.14 * raio;
    *pArea = 3.14 * (raio * raio);
}
