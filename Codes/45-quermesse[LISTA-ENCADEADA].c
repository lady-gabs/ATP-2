#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

    int num;
    struct lista *proximo;

}list;

int quermesse(list* lista, int* cont);
list* inserir_fim(int item, list* lista);

int main(){

    int item, numero, i, ingresso;
    int contador=0;
    list* lista;
    list* aux;

    lista = (list*) malloc (sizeof(list));

    scanf("%d", &numero);

    lista->num = 1;
    lista->proximo = NULL;

    aux = lista;

    for(i=0; i<numero; i++){

        scanf("%d", &item);
        aux = inserir_fim(item, aux);
        
    }

    ingresso = quermesse(lista, &contador);

    printf("%d", ingresso);

    return 0;

}

int quermesse(list* lista, int* contador){

    if(lista->num == (*contador)){

        return (*contador);

    }

    if(lista->proximo != NULL){

        (*contador)++;

        return quermesse(lista->proximo, contador);

    }

    else return 0;

}

list* inserir_fim(int item, list* lista){

    list* novo;

    novo = (list*) malloc (sizeof(list));

    novo->num = item;
    novo->proximo = NULL;

    lista->proximo = novo;

    return novo;

}