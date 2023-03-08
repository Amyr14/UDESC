
#include <stdio.h>

int main() {
	int N, x, y, cont1, cont2, somaImp;
	scanf("%d", &N);
	
	for (cont1 = 0; cont1 < N; cont1++) {
		scanf("%d %d", &x, &y);
		somaImp = 0;
		if (x < y) {
			for (cont2 = x + 1 ; cont2 < y; cont2++) 
				if (cont2 % 2 != 0)
					somaImp += cont2;
		}
		else if (x > y) {
			for (cont2 = y + 1; cont2 < x; cont2++)
				if (cont2 % 2 != 0)
					somaImp += cont2;
		}
		printf("%d\n", somaImp);
	}
	return 0;
}
