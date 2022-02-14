#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct item {
    int num;
    struct item *proximo;
}item;

typedef struct lista {
    item *primeiro;
    item *ultimo;
    item *current;
}list;

list *criarlista();
item *criaritem(int num);
bool esvaziar(list *lista);
bool final(list *lista, item **Item);
void inserirnofim(list *lista, item *Item);
bool inserircomeco(list *lista, item **Item);
bool proximo(list *lista, item **i);
void print(list *lista);
void destroy(list **lista);
int size(list *lista);
list *intercalar(list *lista1, list *lista2);

int main(void){
    list *interc;
    int num;
    list *base = criarlista();
    list *base2 = criarlista();

    do{

        scanf("%d", &num);

        if (num != 0){

            inserirnofim(base, criaritem(num));

        }

    }while (num != 0);

    do{

        scanf("%d", &num);

        if (num != 0){

            inserirnofim(base2, criaritem(num));

        }

    } while (num != 0);

    interc = intercalar(base, base2);

    print(interc);

    return 0;
}

list *criarlista(){

    list *novo;

    novo = (list*) malloc(sizeof(list));

    if(novo){
        
        novo->primeiro = NULL;
        novo->ultimo = NULL;
        novo->current = NULL;

    }

    return novo;

}

item *criaritem(int num){

    item *new;

    new = (item*) malloc(sizeof(item));

    if(new){

        new->num = num;
        new->proximo = NULL;

    }

    return new;
}

bool esvaziar(list *lista){

    return lista->primeiro == NULL;

}

bool final(list *lista, item **Item){

    if (esvaziar(lista)){

        return 0;

    }

    lista->current = lista->ultimo;
    *Item = lista->current;

    return 1;

}

void inserirnofim(list *lista, item *Item){

    item *aux;

    if (esvaziar(lista)){

        lista->primeiro = Item;

    }
    else{

        final(lista, &aux);
        aux->proximo = Item;

    }

    lista->ultimo = Item;
    lista->current = Item;


}

bool inserircomeco(list *lista, item **Item){

    lista->current = lista->primeiro;
    *Item = lista->current;
    return 1;

}

bool proximo(list *lista, item **i){

    lista->current = lista->current->proximo;
    *i = lista->current;

    return 1;

}

void print(list *lista){

    item *i = lista->primeiro;

    do{

        printf("[%d] -> ", i->num);
        i = i->proximo;

    } while (i != NULL);

    printf("[NULL]");

    return;

}

void destroy(list **lista){

    item *aux1;
    item *aux2;

    if (!esvaziar(*lista)){
        aux2 = (*lista)->primeiro;

        while (aux2 != NULL){

            aux1 = aux2;
            aux2 = aux2->proximo;
            free(aux1);

        }
    }

    free(lista);

}

int size(list *lista){

    int i = 0;
    item *aux = lista->primeiro;

    while (aux != NULL){

        i++;
        aux = aux->proximo;

    }

    return i;

}

list *intercalar(list *lista1, list *lista2){

    list *intercala = criarlista();

    item *aux = lista1->primeiro;
    item *aux2 = lista2->primeiro;

    do{
        if (aux == NULL && aux2 == NULL){
            break;
        }

        inserirnofim(intercala, criaritem(aux->num));
        aux = aux->proximo;
        inserirnofim(intercala, criaritem(aux2->num));
        aux2 = aux2->proximo;

    } while (aux != NULL);

    return intercala;

}
