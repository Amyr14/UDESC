
#include <stdio.h>

void apaga_ocorr(char s[], char c);
void aux(char s[], int pos);

int main(){
	char s[] = "abcdefg";
	apaga_ocorr(s, 'c');
	printf("%s", s);
	return 0;
}

void aux(char s[], int pos){
	int i;
	for(i = pos; s[i] != '\0'; i++)
		s[i] = s[i + 1];
}

void apaga_ocorr(char s[], char c){
	int i;
	for(i = 0; s[i] != '\0'; i++)
		if (s[i] == c){
			aux(s, i);
			i--;
		}
}


