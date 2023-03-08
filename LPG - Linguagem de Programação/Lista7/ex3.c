
#include <stdio.h>
#include <stdlib.h>

int main(){
    float *v, *v_media, soma, media;
    int n, i, cont = 0;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    v = malloc( sizeof(float) * n );
    for ( i = 0; i < n; i++ ) {
        printf("v[%d] = ", i);
        scanf("%f", &v[i]);
        soma = soma + v[i];
    }
    media = soma / n;
    printf("Media = %f\n", media);
    for ( i = 0; i < n; i++ ) {
        if ( cont == 0 && v[i] >= media ) {
            v_media = malloc( sizeof(float) );
            v_media[0] = v[i];
            printf("v_media[0] = %f\n", v_media[0]);
            cont++;
        }
        else if ( v[i] >= media ) {
            v_media = realloc( v_media, sizeof(float) * cont + 1 );
            v_media[cont] = v[i];
            printf("v_media[%d] = %f", cont, v_media[cont]);
            cont++;
        }
    }
    free(v);
    free(v_media);
    return 0;
}