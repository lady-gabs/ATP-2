/* Escreva um programa em C que reverta uma String utilizando Recursão.
Exemplo:
    - Dado como entrada: w3resource
    - Tenha como saída: ecruoser3w        */

#include <stdio.h>

void reverso (char* palavra, int n);

int main(){
    int n=0;
    char palavra[50] = {0};

    scanf(" %s", &palavra);
    reverso(palavra, n);

    return 0;
}

void reverso (char* palavra, int n){
    
    if (n > 50){

        return;

    }

    reverso(palavra, n+1);

    if (palavra[n] != '\0'){

        printf("%c", palavra[n]);
        
    }

}