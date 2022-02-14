/*Seguindo o protótipo abaixo, e utilizando alocação dinâmica, escreva uma função que receba
um byte c (que pode representar um caractere ASCII, por exemplo) e transforme-o em uma string,
ou seja, devolva uma string de comprimento 1 tendo c como único elemento.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *charToString(char c);

int main() {

    char caractere;
    char *pointer;

    scanf("%c", &caractere);

    pointer = charToString(caractere);

    printf("%s", pointer);

    free(pointer);

    return 0;

}

char *charToString(char c) {

    char *string;
    int i;

    string = (char *) malloc (sizeof(char));
    
    for (i = 0; i < sizeof(*string); i++) {

        string[i]=c;

    }
    
    string[i]='\0';

    return string;

}