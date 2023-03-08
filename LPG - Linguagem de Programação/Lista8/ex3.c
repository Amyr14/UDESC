
#include <stdio.h>
#include <stdlib.h>

int **constroi_matriz( int linhas, int valores[] );
int *acha_divisores( int valor );
void free_matriz( int **matriz, int linhas );


int main() {
     int **matriz, *valores, N, i, j;
     printf("Digite a quantidade de valores: ");
     scanf("%d", &N);
     valores = malloc( sizeof( int ) * N );
     for ( i = 0; i < N; i++ ) {
          printf("Insira o %d* valor: ", i + 1);
          scanf("%d", &valores[i]);
     }
     matriz = constroi_matriz( N, valores );
     for ( i = 0; i < N; i++ ) {
          printf("Divisores de %d: ", matriz[i][0]);
          for ( j = 1; matriz[i][j] != 0; j++ )
               printf("%d ", matriz[i][j]);
          printf("\n");
     }
     free( valores );
     free_matriz( matriz, N );
     return 0;
}

int **constroi_matriz( int linhas, int valores[] ) {
     int **matriz, i;
     matriz = malloc( sizeof( int* ) * linhas );
     for ( i = 0; i < linhas; i++ )
          matriz[i] = acha_divisores( valores[i] );
     return matriz;
}

int *acha_divisores( int valor ) { 
     if ( valor == 0 )
          return NULL;
     int i, tam = 1, *divisores;
     divisores = malloc( sizeof( int ) );
     divisores[0] = valor;
     for ( i = 1; i <= valor; i++ )
          if ( valor % i == 0 ) {
               tam++;
               divisores = realloc( divisores, sizeof( int ) * tam + 1 );
               divisores[ tam - 1 ] = i;
          }
     divisores[ tam ] = 0;
     return divisores;
} 

void free_matriz( int **matriz, int linhas ) {
	int i;
	for ( i = 0; i < linhas; i++ )
		free( matriz[i] );
	free( matriz );
}