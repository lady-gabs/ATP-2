#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strcopy(char *dest, char *src); //não da pra mandar uma variavel char pra main com uma subrotina do tipo int (??)

int main() {

    char *string, *copia;
    int i;

    string = (char*) malloc (sizeof(char));
    copia = (char*) malloc (sizeof(char));

    scanf(" %[^\n]%*c", string);
    i=strlen(string);
    *(string+i)='\0';

    strcopy(copia, string);

    free(string);
    free(copia);

    return 0;

}

int strcopy(char *dest, char *src){

    int i;

    for ( i = 0; i < strlen(src); i++){
        
        *(dest+i) = *(src+i);
        printf("%c", *(dest+i));

    }
    
    return 0;

}