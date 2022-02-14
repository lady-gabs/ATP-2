#include <stdio.h>
#include <stdlib.h>

void insertion(int* array, int N);

int main() {

    int tam, i;
    int *figurinhas;

    scanf(" %d", &tam);

    figurinhas = (int*) malloc (tam * sizeof(int));

    for ( i = 0; i < tam; i++){

        scanf(" %d", &figurinhas[i]);

    }

    insertion(figurinhas, tam);
    
    for ( i = 0; i < tam; i++) printf("%d ", figurinhas[i]);
    
    free(figurinhas);

    return 0;

}

void insertion(int* array, int N){

    int i, j, aux;

    for ( i = 1; i < N; i++){
        
        aux = array[i];

        for ( j = i-1; j>=0 && aux < array [j]; j--){
            
            array[j+1] = array[j];

        }
        
        array[j+1] = aux;

    }
    
    return;

}