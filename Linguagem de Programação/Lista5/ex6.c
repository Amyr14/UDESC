
#include <stdio.h>

int so_digitos(char str[]);

int main(){
	char str[] = "123a";
	printf("%d", so_digitos(str));
	return 0;
}

int so_digitos(char str[]){
	int i;
	for(i = 0; str[i] != '\0'; i++)
		if (!(str[i] >= 48 && str[i] <= 57))
			return 0;
	return 1;
}
