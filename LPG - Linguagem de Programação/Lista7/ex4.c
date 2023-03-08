
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v, tam, i, tam_vp = 0, tam_vn = 0, *vp, *vn;
    printf("Defina o tamanho do vetor: ");
    scanf("%d", &tam);
    v = malloc( sizeof(int) * tam);
    for ( i = 0; i < tam; i++ ) {
        printf("v[%d] = ", i);
        scanf("%d", v + i);
    }
    vp = malloc( sizeof(int) );
    vn = malloc( sizeof(int) );
    for ( i = 0; i < tam; i++ ) {
        if ( v[i] > 0 ) {
            tam_vp++;
            vp = realloc( vp, sizeof(int) * tam_vp);
            vp[tam_vp - 1] = v[i];
        }
        else if ( v[i] < 0 ) {
            tam_vn++;
            vn = realloc( vn, sizeof(int) * tam_vn);
            vn[tam_vn - 1] = v[i];
        }
    }
    printf("v = [");
    for ( i = 0; i < tam; i++ ) 
        printf(" %d ", v[i]);
    printf("]\n");
    printf("vp = [");
    for ( i = 0; i < tam_vp; i++ )
        printf(" %d ", vp[i]);
    printf("]\n");
    printf("vn = [");
    for ( i = 0; i < tam_vn; i++ )
        printf(" %d ", vn[i]);
    printf("]");
    return 0;
}