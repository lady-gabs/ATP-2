#include <stdio.h>

int main (){

    int numero1, numero2;
    int *a, *b;

    printf("Entre com o primeiro numero: ");
    scanf(" %d", &numero1);
    printf("Entre com o segundo numero: ");
    scanf(" %d", &numero2);

    a=&numero1;
    b=&numero2;

    printf("Resultado: %d", *a+*b);

    return 0;

}