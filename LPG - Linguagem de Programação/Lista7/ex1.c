
#include <stdio.h>
#include <stdlib.h>

float *clone( float *v, int n );

int main(){
    int n, i;
    float *v, *clone_v;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    v = malloc( sizeof(float) * n );
    for ( i = 0; i < n; i++) {
        printf("Posicao %d: ", i);
        scanf("%f", &v[i]);
    }
    clone_v = clone( v, n );
    for( i = 0; i < n; i++ )
        printf("clone_v[%d]: %f\n", i, clone_v[i]);
    free(v);
    free(clone_v);
    return 0;
}


float *clone( float *v, int n ) {
    float *clone_v = malloc( sizeof(float) * n );
    int i;
    for ( i = 0; i < n; i++ )
        *(clone_v + i) = *(v + i);
    return clone_v;
}

