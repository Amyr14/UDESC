
#include <stdio.h>
#include <string.h>

void trim(char str[]);
void apaga_comeco(char str[]);
void apaga_final(char str[]);

int main(){
	char str[] = "    Alo  Mundo!   ";
	trim(str);
	printf("%s", str);
	return 0; 
}

void aux(char str[], int pos){
	int i;
	for(i = pos; str[i] != '\0'; i++)
		str[i] = str[i + 1];
}

void apaga_comeco(char str[]){
	while(str[0] == ' ')
		aux(str, 0);
}

void apaga_final(char str[]){
	int i;
	for(i = strlen(str) - 1; str[i] == ' '; i--)
		aux(str, i);
}


void trim(char str[]){
	apaga_comeco(str);
	apaga_final(str);
}


