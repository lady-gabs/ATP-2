#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE *fp;
    char array1[60], array2[60];
    
    fp = fopen("bloco-de-nota", "w");

    if(fp == NULL) {

        printf("Nao foi possivel abrir o arquivo");

    }

    scanf(" %[^\n]%*c", array1);

    fputs(array1, fp);
    fclose(fp);

    fp = fopen("bloco-de-nota", "r");
    
    while (!feof(fp)) {

        fscanf(fp, "%s", array2);
        printf("%s ", array2);

    }

    fclose(fp);

}