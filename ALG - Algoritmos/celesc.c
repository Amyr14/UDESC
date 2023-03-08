#include <stdio.h>
int main(){
    int bandeira;
    float medidor, acrescimo, valorTotal, valor;
    printf("Insira a quantidade de Kws indicada no medidor: ");
    scanf("%f", &medidor);
    valor = medidor * 0.45;
    printf("\nSelecione a bandeira:");
    printf("\n1 - VERDE");
    printf("\n2 - AMARELA");
    printf("\n3 - VERMELHA 1");
    printf("\n4 - VERMELHA 4\n");
    scanf("%d", &bandeira);
    switch(bandeira){
        case 1 : 
            acrescimo = 0;
            valorTotal = valor;
            break;
        case 2 :
            acrescimo = 1.5 * (int)(medidor / 100);
            valorTotal = valor + acrescimo;
            break;
        case 3 :
            acrescimo = 3 * (int)(medidor / 100);
            valorTotal = valor + acrescimo;
            break;
        case 4 :
            acrescimo = 4.5 * (int)(medidor / 100);
            valorTotal = valor + acrescimo;
            break;
    } 
    printf("Valor total: %.2f", valorTotal);
    if(bandeira == 1)
        printf("\nBandeira usada: Verde");
    else if(bandeira == 2)
        printf("\nBandeira usada: Amarela");
    else if(bandeira == 3)
        printf("\nBandeira usada: Vermelha 1");
    else
        printf("\nBandeira usada: Vermelha 2");
    return 0;
}