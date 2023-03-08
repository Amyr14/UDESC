
#include <stdio.h>
#define N 10

int eh_primo(int n);

int soma_primos(int v[], int n);

int main(){
	int vetor[N] = {2, 3, 5, 6};
	printf("%d", soma_primos(vetor, N));
	return 0;
}

int eh_primo(int n){
	int i;
	for(i = n - 1; i != 1; i--)
		if (n % i == 0)
			return 0;
	return 1;
}

int soma_primos(int v[], int n){
	int i, soma;
	soma = 0;
	for(i = 0; i < n; i++)
		if (eh_primo(v[i]))
			soma += v[i];
	return soma;
}
