
#include <stdio.h>

int main(){
	int N, temp, pos, neg, impares, pares, i;
	pos = 0;
	neg = 0;
	impares = 0;
	pares = 0;
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &temp); 
		if (temp > 0)
			pos++;
		else if (temp < 0)
			neg++;
		if (temp % 2 == 0)
			pares++;
		else 
			impares++;
	}

	printf("%d valor(es) par(es)\n", pares);
	printf("%d valor(es) impar(es)\n", impares);
	printf("%d valor(es) positivo(s)\n", pos);
	printf("%d valor(es) negativo(s)\n", neg);
	
	return 0;
}
