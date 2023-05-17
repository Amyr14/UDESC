#include <stdio.h>
#include <math.h>

 int cubo(int a, int b, char op);

int main(){
    int a, b, result;
    char op;
        scanf("%d", &a);
        scanf("%d", &b);
        scanf(" %c", &op);
        result = cubo(a, b, op);
        printf("O valor calculado foi: %d", result);
        return 0;
    }

    int cubo(int a, int b, char op){
        if(op == 'S')
            return pow(a, 3) + (3 * pow(a, 2) * b) + (3 * a * pow(b, 2)) + pow(b, 3);
        else if(op == 'D')
            return pow(a, 3) - (3 * pow(a, 2) * b) + (3 * a * pow(b, 2)) - pow(b, 3);
    }
    