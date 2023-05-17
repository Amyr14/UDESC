
#include <stdio.h>

float harm_iter(int n);

float harm_recur(int n);

int main(){
	int n;
	scanf("%d", &n);
	printf("%f\n", harm_iter(n));
	printf("%f", harm_recur(n));
	return 0;
}

float harm_iter(int n){
	float soma = 0;
	int i;
	for(i = 1; i <= n; i++)
		soma += (float)1/i;
	return soma;
}

float harm_recur(int n){
	if (n == 1)
		return 1;
	return (float)1/n + harm_recur(n - 1);
}
