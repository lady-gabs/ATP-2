#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int num;
    struct lista *prox;
}LISTA_STRUCT;

LISTA_STRUCT* insertFirst(int n, LISTA_STRUCT* lista);
char comparar(LISTA_STRUCT* prim_lista, LISTA_STRUCT* seg_lista);

int main() {

    LISTA_STRUCT *prim_lista, *seg_lista;
    int n;

    prim_lista = malloc (sizeof(LISTA_STRUCT));
    seg_lista = malloc (sizeof(LISTA_STRUCT));

    prim_lista->prox = NULL;
    seg_lista->prox = NULL;

    while(1) {

        scanf("%d", &n);
        if(n == 0)
            break;
        prim_lista = insertFirst(n, prim_lista);

    }

    while(1) {

        scanf("%d", &n);
        if(n == 0)
            break;
        seg_lista = insertFirst(n, seg_lista);

    }

    printf("%c", comparar(prim_lista, seg_lista));

    free(prim_lista);
    free(seg_lista);
    return 0;

}

LISTA_STRUCT* insertFirst(int n, LISTA_STRUCT* lista) {

    LISTA_STRUCT* novo;

    novo = malloc (sizeof(LISTA_STRUCT));
    novo->num = n;
    novo->prox = lista;

    return novo;

}

char comparar(LISTA_STRUCT* prim_lista, LISTA_STRUCT* seg_lista){

    if(prim_lista->num == seg_lista->num){

        return 'S';

    }

    if((seg_lista->prox==NULL && prim_lista->prox!=NULL) || (prim_lista->prox==NULL && seg_lista->prox!=NULL) || (prim_lista->num != seg_lista->num)) {

        return 'N';

    }

    if(prim_lista->num == seg_lista->num && seg_lista->prox != NULL) {

        return comparar(prim_lista->prox, seg_lista->prox);

    }
    return '\0';

}