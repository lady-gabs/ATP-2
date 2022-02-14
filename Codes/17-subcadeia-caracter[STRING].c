#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

bool substring(char *str, char *substr);

int main(){

    char *palavra1;
    char *palavra2;
    int s_ou_n=0;
    int i, j, k, l=0, m=0;
    
    palavra1 = (char*) malloc (sizeof(char));
    palavra2 = (char*) malloc (sizeof(char));

    scanf(" %[^\n]%*c", palavra1);
    scanf(" %[^\n]%*c", palavra2);

    j = strlen(palavra1);
    k = strlen(palavra2);

    for(i = 0; i<j; i++){

        if (*(palavra1+i) != '\0' && *(palavra1+i) != ' '){

            *(palavra1+l) = tolower(*(palavra1+i));
            l++;

        }

    }

    *(palavra1+l) = '\0';

    for(i = 0; i<k; i++){

        if (*(palavra2+i) != '\0' && *(palavra2+i) != ' '){

            *(palavra2+m) = tolower(*(palavra2+i));
            m++;

        }

    }

    *(palavra2+m) = '\0';

    s_ou_n = substring(palavra1, palavra2);

    if (s_ou_n == 0){

        printf("N");
    
    }
    if (s_ou_n == 1){

        printf("S");

    }
    
    return 0;

}

bool substring(char *str, char *substr){

    bool b;

    if (strstr(str, substr)!= NULL){

        b = true;

    }
    else{

        b = false;

    }
    
    return b;

}