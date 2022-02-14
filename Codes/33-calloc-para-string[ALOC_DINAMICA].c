/*Sua tarefa será desenvolver uma função que receba o tamanho L de uma
string e um caracter C e retorne uma string de L caracteres com todas
as posições preenchidas com o caracter C.

Entrada:
    A primeira e única linha de entrada contém dois inteiros L e C, representando,
    respectivamente, o tamanho da string e o caracter a ser usado para preencher
    a string.

Saída:
    Faça uma função, que seguindo o protótipo abaixo e usando alocação dinâmica,
    retorne uma string de L caracteres C. Por fim, na main, printe essa string,
    utilizando "%s", como mostrado no exemplo.*/
#include <stdio.h>
#include <stdlib.h>

char *strcalloc(int l, char c);

int main() {

    int tamanho;
    char caractere;
    char *string;

    scanf(" %d %c", &tamanho, &caractere);

    string = strcalloc(tamanho, caractere);

    printf("%s", string);

    free(string);

    return 0;    

}

char *strcalloc(int l, char c) {

    char *retorno;
    int i;

    retorno=calloc(l, sizeof(int));

    for ( i = 0; i < l; i++) {
        
        retorno[i] = c;

    }
    
    retorno[l]='\0';

    return retorno;

}