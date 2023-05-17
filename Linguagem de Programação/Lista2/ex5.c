
#include <stdio.h>
#include <math.h>

double fatorial(int x);

int main(){
	int n, i, x;
	double soma;
	soma = 0;
	scanf("%d", &x);
	scanf("%d", &n);
	for(i = 0; i <= n; i++){
		soma += pow(x, i) / fatorial(i);
	}
	printf("%lf", soma);
	return 0;
}

double fatorial(int x){
	double soma = 1;
	int i;
	for(i = 1; i <= x; i++) 
		soma *= i;
	return soma;
}
