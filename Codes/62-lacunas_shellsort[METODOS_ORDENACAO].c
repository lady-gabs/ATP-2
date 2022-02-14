/*for(i=1; pow(2,i)-1>tam; i++) printf("%d ", array[pow(2,i)-1]);*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void shell(int* array, int N);

int main() {

    int tam, i;
    int aux=1, a=0;
    int *array;

    scanf(" %d", &tam);

    array = (int*) malloc (tam * sizeof(int));

    for ( i = 0; i < tam; i++) {
        
        scanf(" %d", &array[i]);

    }

    array[tam] = '\0';
    
    shell(array, tam);
    
    while(array[a]<array[tam-1]){

        a = (pow(2,aux)-1);

        if (a>tam) break;

        printf("%d ", array[a-1]);
        aux++;  

    }

    printf("\n");

    for ( i = 0; i < tam; i++) printf("%d ", array[i]);
        
    free(array);

    return 0;

}

void shell(int* array, int N){

    int i, j, value;
    int h = 1;

    while(h < N) {
        h = 3*h+1;
    }

    while (h > 0) {
        for(i = h; i < N; i++) {
            value = array[i];
            j = i;
            while (j > h-1 && value <= array[j - h]) {
                array[j] = array[j - h];
                j = j - h;
            }
            array[j] = value;
        }
        h = h/3;
    }

}