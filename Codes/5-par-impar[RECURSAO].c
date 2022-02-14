/*Desenvolva um programa em C usando Recursao para printar somente os números ímpares e pares de uma sequência pré-determinada.
Por exemplo:
    - Printar números no intervalo: 1 : 10
    - Todos os números pares de 1 à 10 são: 2 4 6 8 10
    - Todos os números ímpares de 1 à 10 são: 1 3 5 7 9
*/
#include <stdio.h>

int par(int numero1, int numero2);
int impar(int numero1, int numero2);

int main(){

    int numero1, numero2;

    printf("Defina o inicio do intervalo: ");
    scanf(" %d", &numero1);
    printf("Defina o fim do intervalo: ");
    scanf(" %d", &numero2);

    printf("Todos os numeros pares de %d a %d sao: ", numero1, numero2);
    par(numero1, numero2);

    printf("\nTodos os numeros impares de %d a %d sao: ", numero1, numero2);
    impar(numero1, numero2);

    return 0;

}
int par(int numero1, int numero2){

    if (numero1 > numero2){

        return;

    }

    if (numero1 % 2 == 0){

        printf("%d ", numero1);

        par(numero1+2, numero2);

    }
    else{

        par(numero1+1, numero2);

    }
    
}
int impar(int numero1, int numero2){

    if (numero1 > numero2){

        return;

    }

    if (numero1 % 2 != 0){

        printf("%d ", numero1);

        impar(numero1+2, numero2);

    }

    else{

        impar(numero1+1, numero2);
    
    }
    
}