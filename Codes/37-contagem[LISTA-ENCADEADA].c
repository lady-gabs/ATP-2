#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int num;
    struct list *prox;
}LISTA;

LISTA* inserir_comeco(int item, LISTA* lista);
int contar(LISTA* lista);

int main() {

    int item=1;
    LISTA* lista;

    lista = malloc (sizeof(LISTA));
    lista->prox = NULL;

    while(1){

        scanf("%d", &item);
        if(item == 0)
            break;
        lista = inserir_comeco(item, lista);

    }

    printf("%d", contar(lista));

}

LISTA* inserir_comeco(int item, LISTA* lista) {

    LISTA* new;

    new = malloc (sizeof(LISTA));
    new->prox = lista;
    new->num = item;

    return new;
    
}

int contar(LISTA* lista) {

    if(lista->prox != NULL) return contar(lista->prox)+1;

    else return 0;

}