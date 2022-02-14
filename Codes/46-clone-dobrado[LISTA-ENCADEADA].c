#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *prox;
}list;

list* inserir_fim(int item, list* lista);
void print(list* lista);
list* dobra(list* antigo);

int main(){
    
    list* lista, *dobrado, *aux;
    int item;

    lista = malloc (sizeof(list));

    lista->prox = NULL;

    aux = lista;

    do{

        scanf("%d", &item);
        if(item == 0) break;
        aux = inserir_fim(item, aux);

    }while(item != 0);

    dobrado = dobra(lista->prox);

    print(lista->prox);

    printf("\n");
    
    print(dobrado);

    return 0;

}

list* inserir_fim(int item, list* lista){

    list* novo;

    novo = malloc (sizeof(list));
    novo->num = item;
    novo->prox = NULL;
    lista->prox = novo;

    return novo;
}

void print(list* lista){

    if(lista->prox == NULL){

        printf("[%d] -> [NULL]", lista->num);
        return;

    }
    else{

        printf("[%d] -> ", lista->num);
        print(lista->prox);

    }

}

list* dobra(list* antigo){

    list* dobrado;

    dobrado = (list*) malloc(sizeof(list));

    dobrado->num = 2 * antigo->num;

    if(antigo->prox != NULL){

        dobrado->prox = dobra(antigo->prox);

    }

    else dobrado->prox = NULL;

    return dobrado;

}