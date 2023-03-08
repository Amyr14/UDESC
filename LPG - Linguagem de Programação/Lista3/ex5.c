
#include <stdio.h>
#include <math.h>

int verif_primo(int n);

int main(){
    int k, n, i, primos;
    primos = 0;
    scanf("%d %d", &k, &n);
    for (i = k + 1; primos != n; i++){
        int eh_primo = verif_primo(i);
        if (eh_primo) {
            printf("%d\n", i);
            primos++;
        }
    }
    return 0;
}

int verif_primo(int n){
    int i;
    for(i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
