
#include <stdio.h>

int main(){
	int comeco, fim, duracao;
	scanf("%d %d", &comeco, &fim);
	
	if (comeco > fim) 
		duracao = 24 - comeco + fim;
		
	else if (fim > comeco)
		duracao = fim - comeco;
		
	else if (comeco == fim)
		duracao = 24;
	
	printf("O jogo durou %d horas", duracao);
	return 0;
}
