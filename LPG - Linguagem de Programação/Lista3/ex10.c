
#include <stdio.h>

float euler_iter(int n);
float euler_recur(int n);
float div_fat(int n);

int main(){
	int n;
	scanf("%d", &n);
	printf("%f", euler_recur(n));
	printf("\n%f", euler_iter(n));
	return 0;
}

float euler_iter(int n){
	float soma, termo;
	int i, j;
	soma = 1;
	for(i = 1; i <= n - 1; i++){
		termo = 1;
		for(j = 1; j <= i; j++)
			termo *= (float)1/j;
		soma += termo;
	}
	return soma;
}

float euler_recur(int n){
	if (n == 0)
		return 1;
	return div_fat(n) + euler_recur(n - 1);
}

float div_fat(int n){
	if (n == 0)
		return 1;
	return (float)1/n * div_fat(n - 1);
}




