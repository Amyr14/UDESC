
#include <stdio.h>

void inc_dec(int *a, int *b);

int main(){
    int a = 1, b = 1;
    inc_dec(&a, &b);
    printf("%d %d", a, b);
    return 0;
}

void inc_dec(int *a, int *b){
    (*a)++;
    (*b)--;
}

