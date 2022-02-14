#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selection(int* array, int N);

int main() {

    int tam, i;
    int *notas;

    scanf(" %d", &tam);

    notas = (int*) malloc (tam * sizeof(int));

    for ( i = 0; i < tam; i++){
        
        scanf(" %d", &notas[i]);

    }
    
    selection(notas, tam);

    for ( i = 0; i < tam; i++){
        
        if (notas[i]<50){
            
            printf("%d ", notas[i]);
        
        }

    }
    
    free(notas);

    return 0;

}

void selection(int* array, int N){

    int i, j, k, aux;
    bool troca;

    for ( i = 0; i < N-1; i++){
        
        troca = false;
        k = i;
        aux = array[i];

        for ( j = i+1; j < N; j++){
            
            if (array[j] < aux){
                
               k = j;
               aux = array[j];
               troca = true; 

            }
            
        }

        if (troca){
            
            array[k] = array[i];
            array[i] = aux;

        }

    }
    
    return;

}