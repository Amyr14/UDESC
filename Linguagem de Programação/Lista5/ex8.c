
#include <stdio.h>

int eh_digito(char a);

int main(){
	char str[] = "02/10/2002";
	int i, soh_digito = 1, dia, mes, ano;
	int formatado = str[2] == '/' && str[5] == '/';
	
	for(i = 0; str[i] != '\0'; i++)
		if ( i != 2 && i != 5 && !eh_digito(str[i]))
			soh_digito = 0;
			
	if (soh_digito && formatado){
		dia = (str[0] - 48) * 10 + (str[1] - 48);
		mes = (str[3] - 48) * 10 + (str[4] - 48);
		ano = (str[6] - 48) * 1000 + (str[7] - 48) * 100 + (str[8] - 48) * 10 + str[9] - 48;
	}
	printf("%d %d %d", dia, mes, ano);
	return 0;
}

int eh_digito(char a){
	return a >= 48 && a <= 57;
}





