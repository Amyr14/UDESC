
#include <stdio.h>

int compara(float a[], float b[], int n);

int main(){
	float a[] = {1, 2, 3};
	float b[] = {1, 2, 3};
	printf("%d", compara(a, b, 3));
	return 0;
}

int compara(float a[], float b[], int n){
	int i ;
	for(i = 0; i < n; i++)
		if ( a[i] != b[i] ) 
			return 0;
	return 1;
}


