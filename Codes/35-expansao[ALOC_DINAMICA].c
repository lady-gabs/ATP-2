/*Faça um programa que dado um vetor, crie um novo vetor expandido, seguindo o seguinte
exemplo:
    entrada:
        v = {1, 3, 6, 2}
    saída:
        s = {1, 3, 3, 3, 6, 6, 6, 6, 6, 6, 2, 2}
Note que o valor do elemento E é expandido, de modo que o novo vetor conterá E elementos
com o valor E.
-Entrada:
    A primeira linha de entrada contém um inteiro N, representando o tamanho do vetor. A segunda
    linha de entrada contém N inteiros Ei, representando os elementos desse vetor.
-Saída:
    Usando múltiplas realocações dinâmicas, crie um novo vetor como explicado na introdução.
    Por fim, printe este vetor na main
Restrições:
    1 ≤ N < 100.
    1 ≤ Ei < 10. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, x, i, j;
    int *vet;
    int tam=0;

    scanf(" %d", &n);

    vet = (int *) malloc (sizeof(int));

    for(i = 0; i < n; i++){

        scanf("%d", &x);

        if(i==0) vet[i] = x;

        else vet[tam] = x;
        
        tam = tam + x;

        vet = realloc(vet, (tam * sizeof(int)+1));

        for(j = 1; j <= x; j++) vet[(tam-j)] = x;

    }

    for(int i=0;i<tam;i++) printf("%d ", vet[i]);

    free(vet);

    return 0;
    
}