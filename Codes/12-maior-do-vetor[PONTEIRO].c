#include <stdio.h>

int maior(int* array, int tamanho);

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
            
            printf("Numero %d: ", i+1);
            scanf(" %d", array+i);
        
        }

        printf("O maior numero eh: %d", maior(array, tamanho));

        return 0;

    }

}

int maior(int* array, int tamanho){

    int i, maior_vetor=0;

    for ( i = 0; i < tamanho; i++){

        if( *(array+i) > maior_vetor){

            maior_vetor = *(array+i);
            
        }

    }
    
    return maior_vetor;

}