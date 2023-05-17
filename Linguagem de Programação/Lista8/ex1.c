
#include <stdio.h>
#include <stdlib.h>

int *diagonal_secundaria( int **matriz, int ordem );

int main(){
    int **matriz, *diagonal_sec, ordem, i, j;
    printf("Informe a ordem da matriz quadrada: ");
    scanf("%d", &ordem);
    matriz = malloc( sizeof(int*) * ordem );
    for ( i = 0; i < ordem; i++ )
       matriz[i] = malloc( sizeof(int) * ordem); 
    for ( i = 0; i < ordem; i++ )
        for ( j = 0; j < ordem; j++ ) {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    diagonal_sec = diagonal_secundaria( matriz, ordem );
    for ( i = 0 ; i < ordem; i++ )
        free( *(matriz + i) );
    free( matriz );
    for ( i = 0; i < ordem; i++ )
        printf("diagonal_sec[%d] = %d\n", i, diagonal_sec[i]);
    free( diagonal_sec );
    return 0;
}

int *diagonal_secundaria( int **matriz, int ordem ) {
     int i, j, *diagonal_sec;
     diagonal_sec = malloc( sizeof(int) * ordem );
     for ( i = 0, j = ordem - 1; i < ordem; i++ )
        diagonal_sec[i] = matriz[i][j - i];
    return diagonal_sec; 
}