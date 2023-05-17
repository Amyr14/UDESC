
#include <stdio.h>
#include <string.h>

int str_ocorr_char(char str[], char c);

int main(){
	char c = 'd';
	char str[] = {'a', 'b', 'c', 'd', 'd'};
	printf("%d", str_ocorr_char(str, c));
	return 0;
}

int str_ocorr_char(char str[], char c){
	int i = 0, ocorr = 0;
	for(i = 0; str[i] != '\0'; i++)
		if ( str[i] == c )
			ocorr++;
	return ocorr;
}


