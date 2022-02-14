/*Desenvolva um programa em C usando Repeticao que encontre a primeira letra maiúscula em uma string.
Exemplo:
    - Entrada -> Escreva uma string que contenha 1 ou mais letras maiúsculas: testeString
    - Saída -> A primeira letra maiúscula é: S, na posição 6.
*/

#include <stdio.h>

int main(){

    char palavra[50];
    int i;

    printf("Escreva uma string que contenha 1 ou mais letras maiusculas: ");
    scanf(" %s", &palavra);

    printf("A primeira letra maiuscula eh:\n");

    for ( i = 0; i < 50; i++){

        if (palavra[i] != '\0'){
            
            if (palavra[i] > 64 && palavra[i]<91){

                printf("=> %c, na posicao %d\n", palavra[i], i+1);

                break;
            
            }

        }
        
    }
    
    return 0;

}