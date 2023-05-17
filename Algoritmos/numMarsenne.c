
#include <stdio.h>
#include <math.h>

int main(){
    int p, contP, aviso, i, input; 
    long int alvo, numPerfeito;
    int parametros[5];
    scanf("%d", &input);
    contP = 0;
    for(p = 2; contP < 5; p++){
        aviso = 0;
        alvo = pow(2, p) - 1;
        for(i = alvo - 1; i > 1; i--){
            if(alvo % i  == 0){
                aviso = 1; //Número não é primo
                break; 
            }
        }
        if(aviso == 0){ //Se o número for primo
            parametros[contP] = p;
            contP++;
        }
    }
    for(i = 0; i < input; i++){
        p = parametros[i];
        numPerfeito = pow(2, p - 1) * (pow(2, p) - 1);
        printf("%ld\n", numPerfeito);
    }
    
    return 0;
}