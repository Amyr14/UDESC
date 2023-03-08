
#include <stdio.h>

int maiorValor(int x, int y, int z);

int main(){
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	printf("%d", maiorValor(x, y, z));
	return 0;
}

int maiorValor(int x, int y, int z){
	int vetor[3] = {x, y, z};
	int maior = vetor[0];
	int i, j;
	for(i = 1; i <= 2; i++)
		if (vetor[i] > maior)
			maior = vetor[i];
	return maior;
}
