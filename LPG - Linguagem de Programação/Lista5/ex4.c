
#include <stdio.h>
#include <string.h>

int palindrome(char str[]);

int main(){
	char str[6] = "ARARA";
	printf("%d", palindrome(str));
	return 0; 
}

int palindrome(char str[]){
	int n, i;
	for(i = 0, n = strlen(str) - 1 ; n > i; i++, n--)
		if (str[i] != str[n])
			return 0;
	return 1;
}


