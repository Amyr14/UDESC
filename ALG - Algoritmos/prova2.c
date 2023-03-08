#include <stdio.h>

int main()
{
    int vetor[8] = {1, 3, 2, 1, 4, 4, 3, 5};
    int casasDup[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int i, j, numDup, i3, duplicata, repete, aviso, aviso2;
    numDup = 0;
    aviso = 0; 
    aviso2 = 0; 
    repete = 0;
    for(i = 0; i < 8; i++){
        for(i3 = 0; i3 < numDup;  i3++){
            if(i == casasDup[i3]){
                aviso2 = 1;
                break;
            }
        }
        if(aviso2 == 1){ 
        aviso2 = 0;
        continue;
        }
        for(j = i + 1; j < 8; j++){
            if(vetor[i] == vetor[j]){
                duplicata = vetor[i];
                casasDup[numDup] = j;
                numDup++;
                repete++;
                aviso = 1;
            }
        }
        if(aviso == 1){
        printf("%d: ocorre %d vezes\n", duplicata, repete + 1);
        aviso = 0;
        repete = 0;
        }
    }
    printf("Novo vetor:");
    for(i = 0; i < 8; i++){
        for(i3 = 0; i3 < numDup; i3++){
            if(i == casasDup[i3]){
             aviso2 = 1;
             break;
            }
        }
        if(aviso2 == 1){
            aviso2 = 0;
            continue;
        }
        printf(" %d", vetor[i]);
    }
    return 0;
}