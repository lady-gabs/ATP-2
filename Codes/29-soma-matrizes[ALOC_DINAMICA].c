/*Para realizar a soma entre matrizes A e B, elas devem ser de mesma ordem, ou seja,
devem possuir o mesmo número de linhas e colunas. Agora, para efetuar a operação,
temos que somar termo a termo da matriz, isto é, elemento correspondente a elemento
correspondente.

-Entrada:
    A primeira linha de entrada contém um inteiro N, indicando a ordem das matrizes
    quadradas A e B.
    As próximas N linhas possuem N inteiros cada uma, separados por espaço, indicando
    os elementos da matriz A.
    Finalmente, as próximas N linhas possuem N inteiros cada uma, separados por espaço,
    indicando os elementos da matriz B.

-Saída:
    Faça uma função que, seguindo o protótipo abaixo, receba N, A e B como parâmetros
    e usando alocação dinâmica retorne uma matriz de ordem N, representando a soma da
    matriz A e B. Por fim, printe essa matriz, como mostrado no exemplo.*/

#include <stdio.h>
#include <stdlib.h>

int **somar_matrizes(int n, int **a, int **b);

int main() {

    int n, i, j, k;
    int **a;
    int **b;
    int **matriz_soma;

    scanf("%d", &n); // ordem matriz

    // Alocação inicial de "a"
    a= malloc (n * sizeof (int*));
    for (k = 0; k < n; k++){

        a[k] = malloc(n * sizeof (int));
    
    }
    // Preencher matriz
    for (i=0; i < n; i++){

        for (j=0; j < n; j++){

            scanf("%d", &a[i][j]);
        
        }

    }
    // Alocação inicial de "b"
    b= malloc (n * sizeof (int*));
    for (k = 0; k < n; k++){

        b[k] = malloc(n * sizeof (int));
    
    }
    // Preencher matriz
    for (i=0; i < n; i++){

        for (j=0; j < n; j++){

            scanf("%d", &b[i][j]);
        
        }
    }

    matriz_soma=somar_matrizes(n, a, b);

    for (i=0; i < n; i++){

        for (j=0; j < n; j++){

            printf("%d ", matriz_soma[i][j]);
        
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(matriz_soma);

    return 0;

}

int **somar_matrizes(int n, int **a, int **b) {

    int **c;
    int i, j, k;

    c = malloc (n * sizeof (int*));
    for (i = 0; i < n; i++){

        c[i] = malloc(n * sizeof (int));
    
    }

    for ( j = 0; j < n; j++){

        for ( k = 0; k < n; k++){

            c[j][k] = a[j][k] + b[j][k];
            
        }
        
    }

    return c;

}