
#include <stdio.h>

void troca_valor(float *x, float *y);

int main(){
    float x, y;
    scanf("%f", &x);
    scanf("%f", &y);
    printf("x : %.2f, y : %.2f\n", x, y);
    troca_valor(&x, &y);
    printf("x : %.2f, y : %.2f", x, y);
    return 0;
}

void troca_valor(float *x, float *y){
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}