#include <stdio.h>

int main(){
    float notas[10], ajuste[10];
    float maior = 0;
    int i, posMaior;
    for (i = 0; i < 10; i++)
    {
        scanf("%f", &notas[i]);
    }
    for (i = 0; i < 10; i++)
    {
        if(notas[i] > maior){
            maior = notas[i];
            posMaior = i;
        }
    }
    for (i = 0; i < 10; i++)
    {
        ajuste[i] = notas[i] * (10 / maior);
    }
    ajuste[posMaior] = 10;
    printf("%.1f\n", maior);
    printf("%d\n", posMaior);
    printf("%.3f\n", 10 / maior);
    printf("Notas Originais | Notas Ajustadas\n");
    for (i = 0; i < 10; i++)
    {
        printf("%.1f | %.1f\n", notas[i], ajuste[i]);
    }
    
    return 0;
}