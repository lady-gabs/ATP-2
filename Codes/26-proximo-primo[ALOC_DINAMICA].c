/*Faça uma função que, seguindo o protótipo [int *prox_primo(int n)], receba a entrada N como parâmetro
e retorne um ponteiro para inteiro de um endereço alocado dinamicamente contendo o próximo primo a partir
daquele N. Por fim, na main, receba este endereço e printe o valor vínculado ao endereço armazenado pelo
ponteiro.*/

#include <stdio.h>
#include <stdlib.h>

int *prox_primo (int n);

int main() {

    int N;
    int *primo;

    scanf("%d", &N);

    primo = prox_primo(N);

    printf("%d", *primo);

    free(primo);

    return 0;

}

int *prox_primo (int n){

    int j;
    int divisores=0;
    int *i;

    i = (int *) malloc (sizeof(int));

    for (*i = n+1; ; (*i)++){

        divisores=0;

        for ( j = 1; j <= *i; j++){

            if ((*i)%j==0){

                divisores++;
                
            }
            
        }

        if (divisores == 2){

            return i;
            
        }  
        
    }

}