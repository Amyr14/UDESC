
#include <stdio.h>
#include <stdlib.h>

int **mult_matriz( int **A, int **B, int *ordem_A, int *ordem_b );
int soma_linha_coluna( int **A, int **B, int i, int j, int n );
void inicializa_matriz( int **matriz, int *ordem );

int main() {
	int **A, **B, **produto, ordem_A[2], ordem_B[2], i, j;
	printf("Informe quantas linhas tem A: ");
	scanf("%d", &ordem_A[0]);
	printf("Informe quantas colunas tem A: ");
	scanf("%d", &ordem_A[1]);
	printf("Informe quantas linhas tem B: ");
	scanf("%d", &ordem_B[0]);
	printf("Informe quantas colunas tem B: ");
	scanf("%d", &ordem_B[1]);
	
	A = malloc( sizeof( int* ) * ordem_A[0] );
	B = malloc( sizeof( int* ) * ordem_B[0] );
	
	for ( i = 0; i < ordem_A[0]; i++ )
		A[i] = malloc( sizeof( int ) * ordem_A[1] );
		
	for ( i = 0; i < ordem_B[0]; i++ )
		B[i] = malloc( sizeof( int ) * ordem_B[1] );
	
	printf("Inicializando a matriz A: \n");
	inicializa_matriz( A, ordem_A );
	printf("Inicializando a matriz B: \n");
	inicializa_matriz( B, ordem_B );
	
	produto = mult_matriz( A, B, ordem_A, ordem_B );
	
	if ( produto == NULL ) 
		printf("As matrizes nao podem ser multiplicadas");
	else {
		printf("Produto de A com B:\n");
		for( i = 0; i < ordem_A[0]; i++ ) {
			for ( j = 0; j < ordem_B[1]; j++ )
				printf("%d ", produto[i][j]);
			printf("\n");
		}
		free_matriz( produto, ordem_A[0] );
	}

	free_matriz( A, ordem_A[0] );
	free_matriz( B, ordem_B[0] );
		
	return 0;
}

int **mult_matriz( int **A, int **B, int *ordem_A, int *ordem_B ) {
	if ( ordem_A[1] != ordem_B[0] )
		return NULL;
	int linhas = ordem_A[0], colunas = ordem_B[1], i, j;
	int **produto = malloc( sizeof( int* ) * linhas );
	
	for ( i = 0; i < linhas; i++ )
		produto[i] = malloc( sizeof( int ) * colunas );
		
	for ( i = 0; i < linhas; i++ )
		for ( j = 0; j < colunas; j++ )
			produto[i][j] = soma_linha_coluna( A, B, i, j, ordem_A[1] );
			
	return produto;
}

int soma_linha_coluna( int **A, int **B, int linha, int col, int n ) {
	int soma = 0, i, j;
	for ( i = 0, j = 0; i < n && j < n; i++, j++ )
			soma = soma + A[linha][j] * B[i][col];
	return soma;
}

void inicializa_matriz( int **matriz, int *ordem ) {
	int i, j, linhas = ordem[0], col = ordem[1];
	for ( i = 0; i < linhas; i++ )
		for ( j = 0; j < col; j++ ) {
			printf("[%d][%d] = ", i, j);
			scanf("%d", &matriz[i][j]);
		}
}



