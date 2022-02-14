#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *prox;
}LISTA_STRUCT;

LISTA_STRUCT* inserir_prim(int item, LISTA_STRUCT* lista);
int comparar(LISTA_STRUCT* prim_lista, LISTA_STRUCT* seg_lista);
int procurar(int n, LISTA_STRUCT* lista);

int main()
{
    LISTA_STRUCT* prim_lista, * seg_lista;
    int item;

    prim_lista = malloc (sizeof(LISTA_STRUCT));
    seg_lista = malloc (sizeof(LISTA_STRUCT));
    prim_lista->prox = NULL;
    seg_lista->prox = NULL;

    while(1){

        scanf("%d", &item);

        if(item == 0) break;
        
        prim_lista = inserir_prim(item, prim_lista);

    }

    while(1) {

        scanf("%d", &item);

        if(item == 0) break;

        seg_lista = inserir_prim(item, seg_lista);

    }

    if(comparar(prim_lista, seg_lista)) {

        printf("S");

        return 0;

    }
    
    else if (comparar(seg_lista, prim_lista)){

        printf("S");
        return 0;

    }

    printf("N");
    return 0;

}

LISTA_STRUCT* inserir_prim(int item, LISTA_STRUCT* lista){

    LISTA_STRUCT* novo;

    novo =(LISTA_STRUCT*) malloc (sizeof(LISTA_STRUCT));
    novo->num = item;
    novo->prox = lista;

    return novo;

}

int comparar(LISTA_STRUCT* prim_lista, LISTA_STRUCT* seg_lista){

    if(prim_lista->prox != NULL){

        if(procurar(prim_lista->num, seg_lista)){

            return comparar(prim_lista->prox, seg_lista);

        }
        else return 0;
    }

    return 1;

}
int procurar(int n, LISTA_STRUCT* lista){

    if(lista->num == n) return 1;

    if(lista->prox == NULL) return 0;

    else return procurar(n, lista->prox);

}