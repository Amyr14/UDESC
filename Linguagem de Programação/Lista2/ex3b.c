
#include <stdio.h>

int main(){
	int n, i, d;
	double soma = 3;
	d = 4;
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++) {
		if (i % 2 != 0) 
			soma += (double)4/(d * d - 1 * d - 2);
		else 
			soma -= (double)4/(d * d - 1 * d - 2);
		
		d += 2;
	}
	
	printf("%lf", soma);
	return 0;
}
