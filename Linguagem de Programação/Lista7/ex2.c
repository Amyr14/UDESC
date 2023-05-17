
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor( char *s, int n );

int main(){
    char s[] = "Teste", *nova_s;
    int n = 3;
    nova_s = repetidor( s, n );
    puts(nova_s);
    free(nova_s);
    return 0;
}

char *repetidor( char *s, int n ){
    int i, j, tam = strlen(s) * n;
    char *nova_s = malloc( sizeof(char) * tam + 1);
    nova_s[tam] = '\0';
    for ( i = 0, j = 0; j < tam; i++ ) {
        if ( s[i] == '\0' )
            i = -1;
        else {
            nova_s[j] = s[i];
            j++;
        }
    }
    return nova_s;
}