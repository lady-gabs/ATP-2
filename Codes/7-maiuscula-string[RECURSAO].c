/*Desenvolva um programa em C usando Recursao que encontre a primeira letra maiúscula em uma string.
Exemplo:
    - Entrada -> Escreva uma string que contenha 1 ou mais letras maiúsculas: testeString
    - Saída -> A primeira letra maiúscula é: S, na posição 6.
*/
#include <stdio.h>

void maiuscula(char* palavra, int n);

int main(){

    char palavra[50]={0};
    int n=0;

    printf("Escreva uma string que contenha 1 ou mais letras maiusculas: ");
    scanf(" %s", &palavra);

    printf("A primeira letra maiuscula eh: ");
    //printf("A(s) letra(s) maiuscula(s) da string eh(sao):\n");    !para saber todas as letras maiúsculas!
    maiuscula(palavra, n);

    return 0;

}

void maiuscula(char* palavra, int n){

    if (n>50){

        return;

    }

    if (palavra[n] != '\0'){
        
        if (palavra[n] > 64 && palavra[n]<91){

            printf("=> %c, na posicao %d\n", palavra[n], n+1);

            return;
            
        }

    }
    
    maiuscula(palavra, n+1);

}