#include <stdio.h>
#include <stdlib.h>

int ordenacao(int N, int* idades);

int main() {

    int N, i, result;
    int *idades;

    scanf(" %d", &N);

    idades = (int*) malloc (N * sizeof(int));

    for ( i = 0; i < N; i++) {
        
        scanf(" %d", &idades[i]);

    }

    idades[N] = '\0';

    result = ordenacao(N,idades);

    printf("%d", result);

    free(idades);
    return 0;

}

int ordenacao(int N, int* idades){

    int errados=0;
    int i;

    
    for ( i = N-1; i >= 1; i--){

        if (idades[i-1] > idades[i]){

            errados++;
        
        }
        
    }

    return errados;

}