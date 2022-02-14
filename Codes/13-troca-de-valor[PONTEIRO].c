#include <stdio.h>

void swapNumbers(int* x, int* y, int* z);

int main(){

    int numero1, numero2, numero3;

    printf("Insira o primeiro numero: ");
    scanf(" %d", &numero1);
    printf("Insira o segundo numero: ");
    scanf(" %d", &numero2);
    printf("Insira o terceiro numero: ");
    scanf(" %d", &numero3);

    swapNumbers(&numero1, &numero2, &numero3);

    return 0;

}

void swapNumbers(int* x, int* y, int* z){

    int aux=0;

    printf("Os valores ANTES da troca sao:\nELEMENTO 1: %d\nELEMENTO 2: %d\nELEMENTO 3: %d\n", *x, *y, *z);

    aux = x;
    x = z;
    z = y;
    y = aux;

    printf("Os valores DEPOIS da troca sao:\nELEMENTO 1: %d\nELEMENTO 2: %d\nELEMENTO 3: %d\n", *x, *y, *z);

}