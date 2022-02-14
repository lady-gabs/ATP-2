#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strconcat(char *dest, char *src);

int main() {

    char string1[50];
    char string2[50];
    int size1, size2;

    //string1 = (char*) malloc (sizeof(char));
    //string2 = (char*) malloc (sizeof(char));

    scanf(" %[^\n]%*c", string1);
    scanf("  %[^\n]%*c", string2);

    size1=strlen(string1);
    *(string1+size1) = '\0';
    
    size2=strlen(string2);
    *(string2+size2) = '\0';

    strconcat(string1, string2);

    printf("%s", string1);

    // free(string1);
    // free(string2);
    
    return 0;

}

void strconcat(char *dest, char *src){

    int i=0, j=0;

    while(*(dest+i)!='\0') {

        i++;

    }
    while(*(src+j)!='\0') {

        *(dest+i)=*(src+j);     //para rodar no windows
        //*(dest+i-1)=*(src+j);     para rodar no linux
        j++;
        i++;

    }
    
    *(dest+i)='\0';

    return;
}