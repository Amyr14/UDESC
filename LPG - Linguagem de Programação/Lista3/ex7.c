
#include <stdio.h>

int soma_especial(int n, int k , int x);

int main(){
	int n, k, x;
	scanf("%d %d %d", &n, &k, &x);
	printf("%d", soma_especial(n, k, x));
	return 0;
}

int soma_especial(int n, int k, int x){
	int soma = 0;
	int termos = 0;
	int i;
	for(i = x; termos < n; i++)
		if (i % k == 0){
			soma += i;
			termos++;
		}
	return soma;
}
