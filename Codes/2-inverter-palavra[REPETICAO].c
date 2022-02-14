/*  Escreva um programa em C que reverta uma String utilizando Repeticao.
Exemplo:
    - Dado como entrada: w3resource
    - Tenha como saída: ecruoser3w    */
#include <stdio.h>

int main(){

    int i;
    //const int maximo=500;
    int n=1024;
    char palavra[1024] = {0};

    scanf(" %s", &palavra);

    for ( i = 0; i <= n; i++){

        if (palavra[n-i] != 0){

            printf("%c", palavra[n-i]);

        }   

    }
    
    return 0;
    
}