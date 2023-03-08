
#include <stdio.h>

int main(){
	int x, y, i, somaImp;
	somaImp = 0;
	scanf("%d", &x);
	scanf("%d", &y);
	
	if (x < y) {
		for(i = x + 1; i < y; i++) 
			if (i % 2 != 0)
				somaImp += i;
	}
	else if (x > y) 
		for(i = y + 1; i < x; i++)
			if (i % 2 != 0)
				somaImp += i;
	
	printf("%d", somaImp);
	return 0;
}
