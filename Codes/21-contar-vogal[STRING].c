#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarVogais(char *str);

int main() {

    char *string;

    string = (char*) malloc (sizeof(char));

    scanf(" %[^\n]%*c", string);

    printf("%d", contarVogais(string));

    free(string);

    return 0;

}

int contarVogais(char *str) {

    int i;
    int j = strlen(str), k=0;

    for ( i = 0; i < j; i++){
        
        if (*(str+i) == 65 || *(str+i) == 69 || *(str+i) == 73 || *(str+i) == 79 || *(str+i) == 85){
            
            k++;

        }

        if (*(str+i) == 97 || *(str+i) == 101 || *(str+i) == 105 || *(str+i) == 111 || *(str+i) == 117){
            
            k++;

        }

    }
    
    return k;

}