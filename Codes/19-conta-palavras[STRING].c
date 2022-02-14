#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countwords(char *str);

int main() {

    char *frase;

    frase = (char*) malloc (sizeof(char));

    scanf(" %[^\n]%*c", frase);

    printf("%d", countwords(frase));

    free(frase);

    return 0;

}

int countwords(char *str){

    int i;
    int n=1;

    for ( i = 0; i < strlen(str); i++){
        
        if (*(str+i) == ' '){

            n++;

        }
    
    }

    return n;

}