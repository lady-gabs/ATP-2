/*Progressão aritmética (PA) é uma sequência numérica que possui a seguinte definição:
a diferença entre dois termos consecutivos é sempre igual a uma constante, geralmente
chamada de razão R da PA.

-Entrada:
A primeira e única linha de entrada contém 3 inteiros N, R e A1 indicando,
respectivamente, o número de elementos, a razão da PA e o primeiro elemento
da sequência.

-Saída:
Faça uma função que, seguindo o protótipo [int *elementos_PA(int n, int r, int a1)],
receba N, R e A1 como parâmetros e usando alocação dinâmica retorne um vetor de N
elementos, representando os elementos, em sequência, de uma PA de razão R.

Por fim, na main, receba este vetor e printe cada posição com um espaço simples à direita.*/

#include <stdio.h>
#include <stdlib.h>

int *elementos_PA(int n, int r, int a1);

int main() {

    int num_elementos, razao, a1, i;
    int *pointer;

    scanf("%d %d %d", &num_elementos, &razao, &a1);

    pointer=elementos_PA(num_elementos, razao, a1);

    for (i = 0; i < num_elementos; i++){

        printf("%d ", pointer[i]);
        
    }

    free(pointer);
    
    return 0;

}

int *elementos_PA(int n, int r, int a1) {

    int *progressao;
    int i;

    progressao = (int *) malloc (n * sizeof(int));

    for ( i = 0; i < n; i++){

        progressao[i]=a1+(i*r);

    }
    
    return progressao;

}