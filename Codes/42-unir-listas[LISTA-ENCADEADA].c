#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct item{

    int num;
    struct item *proximo;

}item;

typedef struct{

    item *primeiro;
    item *ultimo;
    item *current;

}list;

list *criar_lista();
item *criar_item(int num);
bool vazio(list *lista);
bool fim(list *lista, item **Item);
void inserir_fim(list *l, item *Item);
bool inserir_comeco(list *lista, item **Item);
bool proximo(list *lista, item **Item);
void print(list *lista);
void destruir(list **lista);
int tamanho(list *lista);
list *unir(list *lista1, list *lista2);

int main(){

    list *aux = criar_lista();
    list *aux2 = criar_lista();
    list *uniao;
    int num;

    do{

        scanf(" %d", &num);

        if (num != 0){

            inserir_fim(aux, criar_item(num));

        }

    } while (num != 0);

    do{

        (scanf(" %d", &num));

        if (num != 0){

            inserir_fim(aux2, criar_item(num));

        }

    } while (num != 0);

    uniao = unir(aux, aux2);
    print(uniao);

    return 0;

}

list *criar_lista(){

    list *new;

    new = (list*) malloc(sizeof(list));

    if(new != NULL){
        
        new->primeiro = NULL;
        new->ultimo = NULL;
        new->current = NULL;

    }

    return new;

}

item *criar_item(int num){

    item *new;

    new = (item*) malloc(sizeof(item));

    if(new != NULL){
        
        new->num = num;
        new->proximo = NULL;

    }


    return new;

}

bool vazio(list *lista){

    return lista->primeiro == NULL;

}

bool fim(list *lista, item **Item){

    if (vazio(lista)){

        return 0;

    }

    lista->current = lista->ultimo;
    *Item = lista->current;

    return 1;

}

void inserir_fim(list *lista, item *Item){

    item *aux;

    if (vazio(lista)){

        lista->primeiro = Item;

    }

    else{

        fim(lista, &aux);
        aux->proximo = Item;

    }

    lista->ultimo = Item;
    lista->current = Item;

}

bool inserir_comeco(list *lista, item **Item){

    lista->current = lista->primeiro;
    *Item = lista->current;
    return true;

}

bool proximo(list *lista, item **Item){

    lista->current = lista->current->proximo;

    *Item = lista->current;

    return true;

}

void print(list *lista){

    item *i = lista->primeiro;

    do{

        printf("[%d] -> ", i->num);
        i = i->proximo;

    } while (i != NULL);

    printf("[NULL]");

}

void destruir(list **lista){

    item *temp;

    if (!vazio(*lista)){

        item *aux = (*lista)->primeiro;

        while (aux != NULL){

            temp = aux;
            aux = aux->proximo;
            free(temp);

        }

    }

    free(lista);

}

int tamanho(list *lista){

    int count = 0;

    item *aux = lista->primeiro;

    while (aux != NULL){

        count++;
        aux = aux->proximo;

    }

    return count;

}

list *unir(list *lista1, list *lista2){

    list *uniao = criar_lista();

    item *aux = lista1->primeiro;
    item *aux2 = lista2->primeiro;

    do{

        if (aux == NULL){

            break;

        }

        inserir_fim(uniao, criar_item(aux->num));
        aux = aux->proximo;

    } while (aux);

    do{

        if (aux2 == NULL){

            break;

        }

        inserir_fim(uniao, criar_item(aux2->num));
        aux2 = aux2->proximo;

    }while (aux2);

    return uniao;

}
