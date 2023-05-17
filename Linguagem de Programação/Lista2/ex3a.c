
#include <stdio.h>
#include <math.h>

int main(){
	int n, i, denom;
	float soma;
	scanf("%d", &n);
	denom = 1;
	soma = 0;
	for(i = 1; i <= n; i++) {
		if (i % 2 != 0)
			soma += (float)4/denom;
		else
			soma -= (float)4/denom;	
			
		denom += 2;
	}
	printf("%f", soma);
	return 0;
}
