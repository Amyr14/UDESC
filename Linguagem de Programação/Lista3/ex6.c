
#include <stdio.h>

int fibo(int n);

int main(){
	int n, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		printf("%d\n", fibo(i));
	return 0;
}

int fibo(int n){
	int i, soma, n1, n2, temp;
	if (n == 1)
		return 1;
	n1 = 0;
	n2 = 1;
	for(i = 2; i <= n; i++){
		soma = n1 + n2;
		temp = n2;
		n1 = temp;
		n2 = soma;
	}
	return soma;
}
