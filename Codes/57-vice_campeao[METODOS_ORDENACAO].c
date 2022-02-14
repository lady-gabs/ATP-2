#include <stdio.h>
#include <stdlib.h>

int bubble(int* pontuacoes, int tam);

int main() {

    int num_players, i;
    int *points;

    scanf(" %d", &num_players);

    points = (int*) malloc (num_players*sizeof(int));

    for ( i = 0; i < num_players; i++){
        
        scanf(" %d", &points[i]);

    }
    
    printf("%d", bubble(points, num_players));

    free(points);

    return 0;

}

int bubble(int* pontuacoes, int tam){

    int i, j, aux;

    for ( i = 0; i < tam-1; i++)
        for ( j = 1; j < tam-i; j++){

            if (pontuacoes[j] < pontuacoes[j-1]){

                aux = pontuacoes[j];
                pontuacoes[j] = pontuacoes[j-1];
                pontuacoes[j-1] = aux;
            
            }
            
        }
    return pontuacoes[tam-2];

}