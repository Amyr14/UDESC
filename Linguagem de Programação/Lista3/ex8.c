
#include <stdio.h>

int soma_iterativa(int n);
int soma_recursiva(int n);

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", soma_iterativa(n));
	printf("\n%d", soma_recursiva(n));
	return 0;
}

int soma_iterativa(int n){
	int soma = 0;
	int i;
	for(i = 1; i <= n; i++)
		soma += i;
	return soma;
}

int soma_recursiva(int n){
	if (n == 1)
		return 1;
	return n + soma_recursiva(n - 1);
}
