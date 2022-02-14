#include <stdio.h>
#include <stdlib.h>

int strlength(char *str);

int main() {

    char *string;

    string = (char*) malloc (sizeof(char));

    scanf(" %[^\n]%*c", string);

    printf("%d", strlength(string));

    return 0;

}

int strlength(char *str){

    static int n=0;

    if (*str != '\0'){

        n++;
        strlength(str+1);

    }
    
    return n;

}