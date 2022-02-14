#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char letra; // chave
    int index;  //aponta para a posição na tabela principal

} INDEX;

typedef struct{

    int index; //posicao
    char letra_fun;
    float salario;

} TABELA;

void busca(char letra_busca, INDEX* indices, int tam_indice, TABELA* tab, int tam_tabela);

int main() {

    int tam_indice, i, tam_tabela;
    INDEX *indices;
    TABELA *tab;
    char letra_busca;

    scanf(" %d", &tam_indice);

    indices=(INDEX*) malloc (tam_indice*sizeof(INDEX));

    for ( i = 0; i < tam_indice; i++){
        
        scanf(" %c %d", &indices[i].letra, &indices[i].index);

    }
    
    scanf(" %d", &tam_tabela);

    tab=(TABELA*) malloc (tam_tabela*sizeof(TABELA));

    for ( i = 0; i < tam_tabela; i++){
        
        scanf(" %d %c %f", &tab[i].index, &tab[i].letra_fun, &tab[i].salario); // mudar!!!

    }
    
    scanf(" %c", &letra_busca);

    busca(letra_busca, indices, tam_indice, tab, tam_tabela);

    free(indices);
    free(tab);

    return 0;

}

void busca(char letra_busca, INDEX* indices, int tam_indice, TABELA* tab, int tam_tabela){

    int i, sup, j=0;

    for ( i = 0; i < tam_indice; i++){

        if (letra_busca == indices[i].letra && i != tam_indice-1){
            
            sup = indices[i+1].index;
            break;

        }

        else if(i==tam_indice-1){
            
            sup=tab[tam_tabela-1].index;
            break;

        }

    }
    
    for ( j = indices[i].index-1; j < sup; j++){
        
        if(tab[j].letra_fun == indices[i].letra){

            printf("%.2f\n", tab[j].salario);

        }

    }
    
    return;
    
}