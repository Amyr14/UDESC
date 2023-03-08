#include <stdio.h>

int main()
{
    int num1, num2, num3, menor, meio, maior;
    char naipe1, naipe2, naipe3;
    do
    {
        scanf(" %c%d", &naipe1, &num1);
    } while ((naipe1 != 'C' && naipe1 != 'E' && naipe1 != 'P' && naipe1 != 'O') || (num1 > 13 || num1 < 1));
    do
    {
        scanf(" %c%d", &naipe2, &num2);
    } while ((naipe2 != 'C' && naipe2 != 'E' && naipe2 != 'P' && naipe2 != 'O') || (num2 > 13 || num2 < 1));
    do
    {
        scanf(" %c%d", &naipe3, &num3);
    } while ((naipe3 != 'C' && naipe3 != 'E' && naipe3 != 'P' && naipe3 != 'O') || (num3 > 13 || num3 < 1));

    if (num1 > num2 && num1 > num3)
    {
        maior = num1;
        if (num2 > num3)
        {
            meio = num2;
            menor = num3;
        }
        else
        {
            meio = num3;
            menor = num2;
        }
    }
    else if (num2 > num1 && num2 > num3)
    {
        maior = num2;
        if (num1 > num3)
        {
            meio = num1;
            menor = num3;
        }
        else
        {
            meio = num3;
            menor = num1;
        }
    }
    else
    {
        maior = num3;
        if (num1 > num2)
        {
            meio = num1;
            menor = num2;
        }
        else
        {
            meio = num2;
            menor = num1;
        }
    }
    if (naipe1 == naipe2 && naipe1 == naipe3)
    {
        if (maior - meio == 1 && meio - menor == 1)
        {
            printf("SEQUENCIA");
        }
        else
        {
            printf("NADA");
        }
    }
    else
    {
        printf("NADA");
    }
    return 0;
}
