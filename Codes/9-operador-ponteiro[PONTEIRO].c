#include <stdio.h>

int main(){

    int *b=NULL;
    int a=1;

    b=&a;

    printf("conteudo de a: %d\n", a);
    printf("conteudo de b: %d\n", b);
    printf("endereco de a: %d\n", &a);
    printf("endereco de b: %d\n", &b);
    printf("onde b aponta: %d\n", *b);

    return 0;
    
}