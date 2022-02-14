#include <stdio.h>

char ordem_bolas(int* array, int tam);

int main(){

    int array[8];
    int i;

    for ( i = 0; i < 8; i++) {
        
        scanf(" %d", &array[i]);

    }
    
    printf("%c", ordem_bolas(array, 8));

    return 0;

}

char ordem_bolas(int* array, int tam){

    

}