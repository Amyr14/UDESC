
#include <stdio.h>

void concatena(char str1[], char str2[]);

int main(){
	char str1[10] = {'a', 'b', 'c', 'd'};
	char str2[6] = {'e', 'f', 'g', 'h','i'};
	concatena(str1, str2);
	printf("%s", str1);
	return 0;
}

void concatena(char str1[], char str2[]){
	int i = 0, j = 0, iterando = 1;
	while(str1[i] != '\0')	
		i++;
	while(iterando){
		str1[i] = str2[j];
		iterando = !(str2[j] == '\0');
		i++;
		j++;
	}
}
