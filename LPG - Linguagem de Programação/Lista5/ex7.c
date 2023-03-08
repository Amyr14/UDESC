
#include <stdio.h>
#include <string.h>

int digito_inteiro(char str[]);

int main(){
	char str[] = "1234";
	printf("%d", digito_inteiro(str));
	return 0;
}

int digito_inteiro(char str[]){
	int i, tam, valor = 0, base = 1;
	tam = strlen(str);
	for(i = tam - 1; i >= 0; i--, base *= 10)
		valor += (str[i] - 48) * base;
	return valor;
}



