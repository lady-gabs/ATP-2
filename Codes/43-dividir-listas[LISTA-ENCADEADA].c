#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
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
bool limpar(list *lista);
bool fim(list *lista, item **Item);
void inserir_fim(list *lista, item *Item);
bool inserir_comeco(list *lista, item **Item);
bool proximo(list *lista, item **Item);
void print(list *lista);
void destruir(list **lista);
int tamanho(list *lista);
void dividir(list *lista, int divisao);

int main(){

    int divisao, num;
    list *aux = criar_lista();

    scanf("%d", &divisao);

    do{

        scanf("%d", &num);

        if (num != 0){

            inserir_fim(aux, criar_item(num));

        }

    } while (num != 0);

    dividir(aux, divisao);

    return 0;

}

list *criar_lista(){

    list *novo;
    
    novo = (list*) malloc(sizeof(list));

    if(novo != NULL){
        
        novo->primeiro = NULL;
        novo->ultimo = NULL;
        novo->current = NULL;

    }

    return novo;
}

item *criar_item(int num){

    item *novo;
    
    novo = (item*) malloc(sizeof(item));
    
    if(novo != NULL){

        novo->num = num;
        novo->proximo = NULL;

    }

    return novo;

}

bool limpar(list *lista){
 
    return lista->primeiro == NULL;

}

bool fim(list *lista, item **Item){

    if (limpar(lista)){

        return 0;

    }

    lista->current = lista->ultimo;
    *Item = lista->current;

    return 1;

}

void inserir_fim(list *lista, item *Item){
    
    item *aux;

    if (limpar(lista)){

        lista->primeiro = Item;

    }
    else{

        fim(lista, &aux);
        aux->proximo = Item;

    }

    lista->ultimo = Item;
    lista->current = Item;

    return;

}

bool inserir_comeco(list *lista, item **Item){

    lista->current = lista->primeiro;
    *Item = lista->current;

    return 1;

}

bool proximo(list *lista, item **Item){

    lista->current = lista->current->proximo;
    *Item = lista->current;

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

void destruir(list **lista){

    item *temp;
    item *aux;

    if (!limpar(*lista)){

        aux = (*lista)->primeiro;

        while (aux){

            temp = aux;
            aux = aux->proximo;
            free(temp);

        }

    }

    free(lista);
    return;

}

int tamanho(list *lista){

    int n = 0;

    item *aux = lista->primeiro;

    while (aux != NULL){

        n++;
        aux = aux->proximo;

    }

    return n;

}

void dividir(list *lista, int divisao)
{
    int count = 1;
    item *aux = lista->primeiro;
    item *aux2 = lista->primeiro;
    list *lista2 = criar_lista();

    do{

        if (count >= divisao){

            inserir_fim(lista2, criar_item(aux->num));

        }

        aux = aux->proximo;
        count++;

    } while (aux);

    count = 1;

    do{

        if (divisao == 1){

            lista->primeiro = NULL;
            break;

        }
        if (count >= divisao - 1){

            aux2->proximo = NULL;

        }

        aux2 = aux2->proximo;
        count++;

    } while (aux2 != NULL);

    if (divisao == 1){

        printf("[NULL]");
        printf("\n");
        print(lista2);

    }
    else{

        print(lista);
        printf("\n");
        print(lista2);

    }

    return;

}
