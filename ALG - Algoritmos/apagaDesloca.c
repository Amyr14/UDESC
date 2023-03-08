
#include <stdio.h>

int main()
{
    int vetor[10];
    int N;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetor[i]);
    }
    scanf("%d", &N);
    for (int i = N; i < 10; i++)
    {
        vetor[i] = vetor[i + 1];
    }
    for (int i = 0; i < 9; i++)
    {
        printf("%d", vetor[i]);
        printf("\n");
    }
}

