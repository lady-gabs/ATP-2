/*Entrada:
A primeira linha de entrada contém um inteiro N representando a quantidade de
elementos do vetor V. A segunda linha de entrada contém N inteiros array[i],
separados por espaço, representando os elementos do vetor. (use malloc).

Saída:
Utilize alocação dinâmica para armazenar os elementos de entrada do vetor.
Em seguida, utilizando realocação dinâmica, dobre o tamanho do vetor, bem
como os valores, de modo que:
    V[N] receba V[0] * 2
    V[N + 1] receba V[1] * 2
    ...
    V[N * 2 -1] receba V[N - 1] * 2
Ao final, printe o novo vetor completo, como mostrado no exemplo.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, i;
    int *array;

    scanf(" %d", &N);

    array = malloc (N * sizeof(int));

    for ( i = 0; i < N; i++){

        scanf(" %d", &array[i]);
        
    }
    
    array= realloc(array, 2 * N * sizeof(int));

    for ( i = N; i < 2*N; i++){

        array[i]= 2 * array[i-N];

    }
    
    for ( i = 0; i < 2*N; i++){
        
        printf("%d ", array[i]);

    }
    
    free(array);

    return 0;

}