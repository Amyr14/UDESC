
#include <stdio.h>

int main(){
	int k, i;
	float soma;
	soma = 0; 
	scanf("%d", &k);
	
	for(i = 1; i <= k; i++) {
		printf("1/%d\n", i);
		soma += ((float)1)/i;
	}
	
	printf("%.3f", soma);
	return 0;
}
