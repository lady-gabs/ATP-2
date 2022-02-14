#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool formar_palavra(int N, char* letras, int size, char* palavra);

int main() {

    int quantidade, i;
    char *letras, *palavra;
    bool answer;

    scanf(" %d", &quantidade);

    letras=(char*) malloc (quantidade*sizeof(char));
    palavra=(char*) malloc (quantidade*sizeof(char));

    for ( i = 0; i < quantidade; i++){

        scanf(" %c", &letras[i]);
    
    }

    letras[quantidade]='\0';

    scanf(" %[^\n]%*c", palavra);

    int size=strlen(palavra);
    palavra[size]='\0';

    answer = formar_palavra(quantidade, letras, size, palavra);

    if(answer==true) printf("S");
    else if(answer==false) printf("N");

    free(letras);
    free(palavra);

    return 0;
    
}

bool formar_palavra(int N, char* letras, int size, char* palavra){

    int i, j;
    bool boolean;

    for ( i = 0; i < size; i++){ 

        boolean=false;

        for ( j = 0; j < N; j++){
            
            if (letras[j]==palavra[i]){

                boolean = true;
                letras[j]=' ';
                break;
            
            }

        }
        
    }

    return boolean;
    
}