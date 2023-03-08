#include <stdio.h>
#include <string.h>

int main(){
    char texto[251];
    char vogais[] = "AaEeIiOoUu";
    int i, j;
    int numVogais = 0;
    fgets(texto, 251, stdin);
    for(i = 0; i < 251; i++){
        if(texto[i] == '\0'){
            break;
        }
        for(j = 0; j < strlen(vogais); j++){
            if(texto[i] == vogais[j]){
                numVogais++;
            }
        }
    }
    printf("%d", numVogais);
    return 0;
}