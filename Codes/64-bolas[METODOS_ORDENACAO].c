#include <stdio.h>
#include <stdbool.h>

bool ordenacao(int* array, int N);

int main() {

    int num_bolas[8];
    int i;
    bool result;

    for ( i = 0; i < 8; i++){
        
        scanf(" %d", &num_bolas[i]);

    }
    
    result = ordenacao(num_bolas, 8);

    if (result == true) printf("S");
    else printf("N");

    return 0;

}

bool ordenacao(int* array, int N){

    int i, j, trocas;

    for(i = 0; i < N-1; i++){

        trocas=0;

        for (j = 1; j < N; j++){

            if(array[i] == array[j]) trocas++;

        }

        if(trocas > 4) return false;

    }

    return true;

}