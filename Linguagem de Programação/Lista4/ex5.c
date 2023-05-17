
#include <stdio.h>
#define N 3

int busc_seq_rec(int v[], int n, int chave);

int main(){
	int v[] = {1, 2, 3};
	printf("%d", busc_seq_rec(v, N, 3));
	return 0;
}

int busc_seq_rec(int v[], int n, int chave){
	int i = n - 1;
	
	if (i == -1)
		return -1;
	
	if (v[i] == chave)
		return chave;
	
	return busc_seq_rec(v, i, chave);
}
