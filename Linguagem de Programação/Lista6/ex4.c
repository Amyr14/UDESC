
#include <stdio.h>

void calcula_hora(int totalMinutos, int *ph, int *pm);

int main(){
    int totalMinutos, horas, minutos;
    printf("Digite quantos minutos se passaram desde as 00:00h: ");
    scanf("%d", &totalMinutos);
    calcula_hora(totalMinutos, &horas, &minutos);
    printf("Hora corrente: %d:%d", horas, minutos);
    return 0;
}

void calcula_hora(int totalMinutos, int *ph, int *pm){
    int horas = (totalMinutos / 60) % 24;
    *ph = horas;
    *pm = totalMinutos % 60;
}