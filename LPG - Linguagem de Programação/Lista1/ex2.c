
#include <stdio.h>
#include <math.h>

int main(){
	double vetor[3];
	double A, B, C, temp;
	int i, j;
	
	for(i = 0; i < 3; i++) 
		scanf("%lf", &vetor[i]);
	
	for(i = 0; i < 2; i++) { 
		for(j = i + 1; j < 3; j++) {
			if (vetor[i] < vetor[j]) {
				temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
	
	A = vetor[0];
	B = vetor[1];
	C = vetor[2];
	double Apow2 = pow(A, 2);
	double Bpow2 = pow(B, 2);
	double Cpow2 = pow(C, 2);
	
	if (A >= B + C)
		printf("Nao forma triangulo");
		
	else {
		if (A == B && B == C)
			printf("Triangulo equilatero\n");
		
		else if (A == B && A != C || A == C && A != B || B == C && B != A)
			printf("Triangulo isosceles\n");
	
		if (Apow2 == Bpow2 + Cpow2)
			printf("Triangulo retangulo\n");
		
		else if (Apow2 > Bpow2 + Cpow2)
			printf("Triangulo obtusangulo\n");
	
		else if (Apow2 < Bpow2 + Cpow2)
			printf("Triangulo acutangulo\n");
	}
	
	return 0;
}
