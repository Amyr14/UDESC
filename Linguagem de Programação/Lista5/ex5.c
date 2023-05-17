
#include <stdio.h>

void minusc_maiusc(char str[]);

int main(){
	char str[] = "abcdefg";
	minusc_maiusc(str);
	printf("%s", str);
	return 0;
}


void minusc_maiusc(char str[]){
	int i;
	for(i = 0; str[i] != '\0'; i++)
		if(str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
}


