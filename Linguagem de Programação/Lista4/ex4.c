
#include <stdio.h>
#define N 5

void busca_todos(int v[], int n, int chave, int indices[]);

int main(){
	int v[N] = {1, 2, 3, 4, 5};
	int indices[N];
	int i;
	busca_todos(v, N, 3, indices);
	for(i = 0; i < N; i++)
		printf("%d ", indices[i]);
	return 0;
}

void busca_todos(int v[], int n, int chave, int indices[]){
	int i, cont;
	cont = 0;
	for(i = 0; i < n; i++)
		if (v[i] == chave) {
			indices[cont] = i;
			cont++;
		}
	for(; cont < n; cont++)
		indices[cont] = -1;
}


