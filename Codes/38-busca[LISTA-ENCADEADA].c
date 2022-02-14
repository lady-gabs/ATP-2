/*Entrada:
A primeira linha de entrada contém 2 inteiros N e B, representando, respectivamente,
a quantidade de valores inteiros a serem inseridos e o valor a ser buscado.

A segunda linha de entrada contém N valores inteiros a serem inseridos no início
na lista encadeada.

Saída:
Faça uma lista encadeada capaz de armazenar inteiros e, usando uma função recursiva,
itere e busque o inteiro B. Ao final printe "S" caso o elemento esteja presente na
lista, ou printe "N" caso contrário.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int num;
    struct lista *prox;
}LISTA_STRUCT;

LISTA_STRUCT* inserir_primeiro(int item, LISTA_STRUCT* lista);
char procura(int n, LISTA_STRUCT* lista);

int main(){

    int N, B, item;
    LISTA_STRUCT* lista;

    do{

        scanf("%d", &N);
        
    }while(N > 1000 || N < 1);

    scanf("%d", &B);

    lista =(LISTA_STRUCT*) malloc (sizeof(LISTA_STRUCT));

    lista->prox = NULL;

    for (int i=0; i<N; i++) {

        scanf("%d", &item);
        lista = inserir_primeiro(item, lista);

    }

    printf("%c", procura(B, lista));

    return 0;

}

LISTA_STRUCT* inserir_primeiro(int item, LISTA_STRUCT* lista){

    LISTA_STRUCT* novo;

    novo =(LISTA_STRUCT*) malloc (sizeof(LISTA_STRUCT));
    novo->num = item;
    novo->prox = lista;

    return novo;
    
}

char procura(int n, LISTA_STRUCT* lista){

    if(lista->num == n)
        return 'S';
    else if(lista->prox == NULL)
        return 'N';
    else
        return procura(n, lista->prox);

}

