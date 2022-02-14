#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA{

    int num;
    struct LISTA *proximo;

}LISTA;

LISTA* insertFirst(int item, LISTA* LISTA);
void print(LISTA* LISTA);

int main () {

    int numero, item;
    LISTA* lista = NULL;

    do{

        scanf("%d", &numero);

    }while(numero>30 || numero<0);

    lista = malloc (sizeof(LISTA));
    lista->proximo = NULL;

    for(int i=0; i<numero; i++) {

        scanf("%d", &item);
        lista = insertFirst(item, lista);

    }

    print(lista);

    free(lista);
    return 0;

}

LISTA* insertFirst(int n, LISTA* lista) {

    LISTA* novo;

    novo = malloc (sizeof(LISTA));
    novo->num = n;
    novo->proximo = lista;

    return novo;

}

void print(LISTA* lista) {

    if(lista->proximo == NULL) {

        printf("[NULL]");
        return;

    }
    else {

        printf("[%d] -> ", lista->num);
        print(lista->proximo);

    }

}