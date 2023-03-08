
#include <stdio.h>
#include <stdlib.h>

int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );

int main() {
    int v1[] = { 1, 2, 3, 4 }, v2[] = { 1, 7, 3 };
    int *v_uniao, card_uniao, i;
    v_uniao = uniao( v1, 4, v2, 3, &card_uniao );
    for ( i = 0; i < card_uniao; i++ )
        printf("v_uniao[%d] = %d\n", i, v_uniao[i]);
    return 0;
}


int *uniao( int *v1, int n1, int *v2, int n2, int *p3 ) {
    int i, j, cont, *uniao, intersec = 0;
    uniao = malloc( sizeof(int) * (n1 + n2) );
    for ( i = 0; i < n1; i++ )
        uniao[i] = v1[i];
    for ( j = 0; j < n2; j++ ) {
        if ( busca_seq(v1, n1, v2[j]) != -1 )
            intersec++;
        else {
            uniao[i] = v2[j];
            i++;
        }      
    }
    uniao = realloc( uniao, sizeof(int) * (n1 + n2) - intersec );
    *p3 = (n1 + n2) - intersec;
    return uniao;
}

int busca_seq(int *v, int n, int chave){
	int i;
	for(i = 0; i < n; i++)
		if ( v[i] == chave )
			return i;
	return -1;
}