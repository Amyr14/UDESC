
#include <stdio.h>
#include <string.h>

int string_contem(char str[], char c);

int main(){
	char c = 'd';
	char str[] = {'a', 'b', 'c', 'd'};
	printf("%d", string_contem(str, c));
	return 0;
}
	


int string_contem(char str[], char c){
	int i = 0;
	for(i = 0; str[i] != '\0'; i++)
		if ( str[i] == c )
			return 1;
	return 0;
}


