#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool palindromo(char *str_inicio, char *str_fim);

int main(){

    char palavra[50]={0};
    char invertido[50]={0};
    int s_ou_n=0, j=0, k=0;
    int i;

    scanf(" %[^\n]%*c", palavra);
    k=strlen(palavra);

    for(i = 0; i<strlen(palavra); i++){

        if (palavra[i] != '\0' && palavra[i] != ' '){

            palavra[j] = tolower(palavra[i]);
            j++;

        }

    }
    palavra[j]='\0';

    k=strlen(palavra);
   
    strcpy(invertido, palavra);

    strrev(invertido);

    /*for ( i = 0; i < k; i++){

        invertido[i]=palavra[k-i-1];

    }*/
    
    invertido[k]='\0';
    
    s_ou_n = palindromo(palavra, invertido);

    if (s_ou_n == false){

        printf("N");

    }
    
    if (s_ou_n == true){

        printf("S");
    
    }
    
    return 0;

}

bool palindromo(char *str_inicio, char *str_fim){

    bool value;
        
    if (strcmp(str_inicio, str_fim)==0){
        
        value = true;

    }
        
    else{

        value = false;
    }

    return value;

}