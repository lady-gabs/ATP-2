/*Crie uma função RECURSIVA que, seguindo o protótipo abaixo, receba uma cadeia de caracteres
e modifique-a para maiusculo. Por fim, na main, imprima-a a string modificada.

                        void str_upper(char *str);

Restrições: - A entrada contém apenas letras minúsculas e espaços em branco;
            - O tamanho máximo da entrada é de 50 caracteres.
*/
#include <stdio.h>
#include <stdlib.h>

void str_upper(char *str);

int main() {

    char *palavra;

    palavra = (char*) malloc (sizeof(char));

    scanf(" %[^\n]%*c", palavra);

    str_upper(palavra);

    free(palavra);

    return 0;

}

void str_upper(char *str){

    if (*str == '\0'){

        return;

    }

    if (*str > 96 && *str < 123){

        printf("%c", *str-32);

    }
    
    if (*str == ' '){

        printf("%c", *str);

    }

    str_upper(str+1);

}