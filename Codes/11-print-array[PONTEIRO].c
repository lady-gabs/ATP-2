#include <stdio.h>

int main(){

    int *array;
    int tamanho, i;

    do{

        printf("Insira o tamanho do vetor: ");
        scanf(" %d", &tamanho);

    }while(tamanho<=0);
    
    array= (int *) malloc (sizeof(int) * tamanho);
    
    if (array == NULL){

        printf("Erro de alocacao");
        return 1;

    }
    else{

        for ( i = 0; i < tamanho; i++){
            
            printf("Insira o elemento da posicao %d: ", i+1);
            scanf(" %d", array+i);
        
        }

        for ( i = 0; i < tamanho; i++){
            
            printf("Elemento da posicao %d: %d\n", i+1, *(array+i));

        }

        return 0;

    }

}