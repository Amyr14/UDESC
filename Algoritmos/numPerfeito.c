#include <stdio.h>
#include <math.h>

int main()
{   
        long int x, N;
        x = 0;
        int i;
        scanf("%ld", &N);
        for(i = 1; x < N; i++){
            x = pow(2, i - 1) * (pow(2, i) - 1);
        }
        if(x == N){
            printf("PERFEITO");
        }
        else{
            printf("NAO PERFEITO");
        }
    return 0;
  }