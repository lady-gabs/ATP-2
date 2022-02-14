/*Exercicio OBI - 2014: Cartas*/
#include <stdio.h>

char ordenacao(int* cartas, int tam);

int main() {

    int cartas[5];
    int i;
    char result;

    for ( i = 0; i < 5; i++){
        
        scanf(" %d", &cartas[i]);

    }
    
    result = ordenacao(cartas, 5);

    printf("%c", result);

    return 0;

}

char ordenacao(int* cartas, int tam){

    int i, c=0, d=0;

    for ( i = tam-1; i >=1; i--){
        
        if (cartas[i]> cartas[i-1]) {

            c++;
        
        }

        else if (cartas[i]< cartas[i-1]){

            d++;

        }

    }

    if (c >= 4){
        
        return 'C';

    }
    else if (d >= 4){
        
        return 'D';

    }
    else {
        
        return 'N';

    }

}