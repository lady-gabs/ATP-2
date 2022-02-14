/*Desenvolva um programa em C usando Repeticao para printar somente os números ímpares e pares de uma sequência pré-determinada.
Por exemplo:
    - Printar números no intervalo: 1 : 10
    - Todos os números pares de 1 à 10 são: 2 4 6 8 10
    - Todos os números ímpares de 1 à 10 são: 1 3 5 7 9
*/
#include <stdio.h>

int main(){

    int numero1, numero2, i;

    printf("Defina o inicio do intervalo: ");
    scanf(" %d", &numero1);
    printf("Defina o fim do intervalo: ");
    scanf(" %d", &numero2);

    printf("Todos os numeros pares de %d a %d sao: ", numero1, numero2);
    for ( i = numero1; i < numero2; i++){

        if (i % 2 == 0){

            printf("%d ", i);

        }
        
    }

    printf("\nTodos os numeros impares de %d a %d sao: ", numero1, numero2);
    for ( i = numero1; i < numero2; i++){

        if (i % 2 != 0){

            printf("%d ", i);

        }
        
    }

    return 0;

}