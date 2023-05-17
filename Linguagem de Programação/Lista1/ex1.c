
#include <stdio.h>

int main(){
    float x, y;
    scanf("%f %f", &x, &y);
    if (y == 0 && x == 0)
        printf("Origem");
    else if (y == 0)
        printf("Eixo X");
    else if (x == 0)
        printf("Eixo Y");
    else if (y > 0 && x > 0) 
        printf("Q1");
    else if (y > 0 && x < 0)
        printf("Q2");
    else if (y < 0 && x < 0)
        printf("Q3");
    else 
        printf("Q4");
    return 0;
}