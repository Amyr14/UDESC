
#include <stdio.h>

int soma_impares(int comeco, int fim);

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", soma_impares(x, y));
    return 0;
}

int soma_impares(int comeco, int fim){
    int i;
    int soma = 0;
    if (comeco > fim) {
        int temp = comeco;
        comeco = fim;
        fim = temp;
    }
    for (i = comeco + 1; i < fim; i++)
        if ( i % 2 == 1 ) 
            soma += i;

    return soma;
}