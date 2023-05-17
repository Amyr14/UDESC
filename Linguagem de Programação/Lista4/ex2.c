
#include <stdio.h>
#define N 10

void fibonacci(int v[], int n);

int main(){
	int v[N], i;
	fibonacci(v, N);
	for(i = 0; i < N; i++)
		printf("%d\n", v[i]);
	return 0;
}

void fibonacci(int v[], int n){
	int i, soma, termo, temp;
	soma = 1;
	termo = 1;
	for(i = 0; i < n; i++){
		v[i] = soma;
		temp = soma;
		soma = soma + termo;
		termo = temp;
	}
}
