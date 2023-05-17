#include <stdio.h>

int main()
{
    int i, n1, n2, j, aviso;
    aviso = 0;
    scanf("%d", &n1);
    scanf("%d", &n2);
    for (i = n1; i <= n2; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0){
                aviso = 1;
                break;
            }
        }
       if(aviso == 0){
           printf("%d ", i);
       }
       else{
           aviso = 0;
       }
    }
    return 0;
}