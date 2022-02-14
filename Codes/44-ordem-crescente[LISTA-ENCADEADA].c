#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

    int num;
    struct lista *proximo;

} list;

list* inserir_fim(int item, list* lista);
int ordem_crescente(list* lista);

int main (){

    int item;
    list* lista = NULL;
    list* temp;

    lista = malloc (sizeof(list));
    lista->proximo = NULL;
    temp = lista;

    do{

        scanf("%d", &item);

        if(item == 0) break;

        lista = inserir_fim(item, lista);

    }while(item !=0);

    lista = temp;

    if(ordem_crescente (lista->proximo)) printf("S");

    else printf("N");
    
    return 0;

}

list* inserir_fim(int item, list* lista){

    list* novo;

    novo = (list*) malloc (sizeof(list));

    novo->num = item;
    novo->proximo = NULL;
    lista->proximo = novo;

    return novo;

}

int ordem_crescente(list* lista){

    if(lista->proximo != NULL){

        if(lista->num <= (lista->proximo)->num){

            return ordem_crescente(lista->proximo);

        }

        else return 0;

    }

    else return 1;

}