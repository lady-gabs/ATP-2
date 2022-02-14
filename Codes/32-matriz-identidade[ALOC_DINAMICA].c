/*Seja M uma matriz quadrada de ordem N. A matriz M é chamada de Matriz Identidade
de ordem M quando os elementos da diagonal principal são todos iguais a 1 e os
elementos restantes são iguais a zero.

Faça uma função que retorne um matriz identidade de ordem N.

Entrada:
A primeira e única linha de entrada contém um inteiro N, representando a ordem da
matriz.

Saída:
Faça uma função, que seguindo o protótipo abaixo e usando alocação dinâmica,
retorne uma matriz identidade de ordem N. Por fim, na main, printe essa matriz,
como mostrado no exemplo.*/

#include <stdio.h>
#include <stdlib.h>

int **matriz_identidade(int n);

int main() {

    int ordem, i, j;
    int **identidade;

    scanf(" %d", &ordem);

    identidade=matriz_identidade(ordem);

    for ( i = 0; i < ordem; i++){

        for ( j = 0; j < ordem; j++) {

            printf("%d ", identidade[i][j]);

        }
        
        printf("\n");
       
    }
    
    free(identidade);

    return 0;

}

int **matriz_identidade(int n){

    int **identidade;
    int i, j;

    identidade= malloc (n * sizeof (int*));
    for (i = 0; i < n; i++){

        identidade[i] = malloc(n * sizeof (int));
    
    }

    for ( i = 0; i < n; i++) {
        
        for ( j = 0; j < n; j++) {
            
            if (i==j)
                identidade[i][j]=1;
            
            else
                identidade[i][j]=0;

        }

    }
    
    return identidade;

}