
#include <stdio.h>

int eh_digito(char x);

int main(){
    char input;
    scanf("%c", &input);
    printf("\n%d", eh_digito(input));
    return 0;
}

int eh_digito(char x){
    if (x >= 48 && x <= 57) {
         int digito = x - 48;
         printf("%d", digito);
         return 1;
    }
    return 0;
}
