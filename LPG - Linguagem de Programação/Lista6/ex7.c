
#include <stdio.h>

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);

int main(){
    float mat[3][4], min;
    int i, j, I, J;
    for ( i = 0; i < 3; i++ )
        for ( j = 0; j < 4; j++ ) {
           printf("mat[%d][%d] = ", i, j);
           scanf("%f", &mat[i][j]);
        }
    min_matriz(mat, &min, &I, &J);
    printf("min : %.2f\nI : %d\nJ : %d", min, I, J);
    return 0;
}

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    int i, j, I = 0, J = 0;
    float min = mat[0][0];
    for ( i = 0; i < 3; i++ )
        for ( j = 0; j < 4; j++ )
            if ( mat[i][j] < min ) {
                min = mat[i][j];
                I = i;
                J = j;
            }
    *pMin = min;
    *pI = I;
    *pJ = J;
}