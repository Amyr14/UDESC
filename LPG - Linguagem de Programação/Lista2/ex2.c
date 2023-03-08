
#include <stdio.h>
#include <math.h>

int main(){
	int n, i;
	float soma;
	soma = 0;
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++) {
		if (i % 2 == 0)
			printf("Termo %d: -1/%d\n", i, i);
		else
			printf("Termo %d: 1/%d\n", i, i);
				
		soma += pow(-1, i + 1)/i;
	}
	printf("%f", soma);
	return 0;
}
