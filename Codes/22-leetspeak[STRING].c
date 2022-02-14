#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void leetConverter(char *str);

int main() {

    char *palavra;
    int i;

    palavra = (char*) malloc (sizeof(char));

    scanf(" %[^\n]%*c", palavra);

    i=strlen(palavra);
    *(palavra+i) = '|';

    leetConverter(palavra);

    free(palavra);

    return 0;

}

void leetConverter(char *str) {

    switch (*str){

        case '|':
            return;

        case '4':{
            printf("A");
            break;
        }
        case '9':{
            printf("G");
            break;
        }
        case '7':{
            printf("T");
            break;
        }
        case '8':{  
            printf("B");
            break;
        }
        case '3':{
            printf("E");
            break;
        }
        case '#':{
            printf("H");
            break;
        }
        case '1':{
            printf("I");
            break;
        }
        case '/':{
            printf("L");
            break;
        }
        case '0':{
            printf("O");
            break;
        }
        case '?':{
            printf("P");
            break;
        }
        case '5':{
            printf("S");
            break;
        }
        case '2':{
            printf("Z");
            break;
        }
        default:{
            *str = toupper(*str);
            printf("%c", *str);
            break;
        }
    }

    leetConverter(str + 1);

}

