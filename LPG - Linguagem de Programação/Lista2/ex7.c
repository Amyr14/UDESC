
#include <stdio.h>

double pot(int base, int exp);
double fatorial(int x);

int main(){
	int n, i, x;
	double soma;
	soma = 0;
	scanf("%d", &x);
	scanf("%d", &n);
	for(i = 0; i <= n; i++)
		soma += pot(-1, i) * pot(x, 2 * i) / fatorial(2 * i);
		
	printf("%lf", soma);
	return 0;
}

double pot(int base, int exp){
	double soma = 1;
	int i;
	for(i = 0; i < exp; i++){
		soma *= base;
	}
	return soma;
}

double fatorial(int x){
	double soma = 1;
	int i;
	for(i = 1; i <= x; i++) 
		soma *= i;
	return soma;
}
