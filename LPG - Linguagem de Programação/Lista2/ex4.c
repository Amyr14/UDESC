
#include <stdio.h>

double fatorial(int x);

int main(){
	int n, i;
	double soma;
	soma = 0;
	scanf("%d", &n);
	
	for(i = 0; i <= n; i++) 
		soma += (double)1/fatorial(i);
		
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
