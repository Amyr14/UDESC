
#include <stdio.h>

int main(){
	int N, i;
	float x, y, z, media;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%f %f %f", &x, &y, &z);
		media = (2 * x + 3 * y + 5 * z) / 10;
		printf("%.1f\n", media);
	}
	return 0;
}
