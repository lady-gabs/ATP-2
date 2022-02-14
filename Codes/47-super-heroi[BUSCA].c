#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int derrotados;
    int soma_derrotados;

} MONSTERS;

MONSTERS derrotados(int P, int N, int* Hi);

int main() {

    int P, N, i; // P=poder Mr. Cateto, N=numero de monstros
    int *Hi; // Hi= poder dos N monstros
    MONSTERS num;

    scanf(" %d %d", &P, &N);

    Hi = (int*) malloc (N*sizeof(int));

    for ( i = 0; i < N; i++){

        scanf(" %d", &Hi[i]);
        
    }

    Hi[N]='\0';

    num = derrotados(P,N,Hi);

    printf("%d %d", num.derrotados, num.soma_derrotados);

    free(Hi);

    return 0;
    
}

MONSTERS derrotados(int P, int N, int* Hi){

    MONSTERS num;
    int i;

    num.derrotados=0;
    num.soma_derrotados=0;

    for ( i = 0; i < N; i++){
        
        if (Hi[i] <= P){
            
            num.derrotados ++;
            num.soma_derrotados = num.soma_derrotados + Hi[i];
        
        }

    }
    
    return num;

}