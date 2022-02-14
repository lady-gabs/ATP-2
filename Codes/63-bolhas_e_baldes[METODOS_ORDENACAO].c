#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool bubble(int *array, int N);

int main(){

    int tam;
    int *array;

    scanf("%d", &tam);

    array = (int*) malloc (tam * sizeof(int));

    for(int i=0; i<tam; i++){

        scanf(" %d", &array[i]);
    
    }
    
    if(bubble(array, tam) == true) printf("Marcelo");
    else  printf("Carlos");
    
    free(array);

    return 0;

}

bool bubble(int *array, int N){

    int i, j, aux, contador=0;

    for ( i = 1; i < N; i++)
        for ( j = N-1; j >= i; j--) {
            
            if (array[j]<array[j-1]){
                
                contador++;
                aux = array[j-1];
                array[j-1] = array[j];
                array[j] = aux;

            }
            
        }    

    if(contador%2==0) return false;

    else return true;

}