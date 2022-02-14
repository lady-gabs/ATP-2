#include <stdio.h>
#include <stdlib.h>

void batalha_naval(int N, char** tabuleiro);

int main() {

    int tam_tabuleiro, i, j;
    char **tabuleiro;
    
    scanf(" %d", &tam_tabuleiro);

    tabuleiro =(char**) malloc (tam_tabuleiro*tam_tabuleiro*sizeof(char*));

    for (i=0; i < tam_tabuleiro; i++) tabuleiro[i] = malloc (tam_tabuleiro * sizeof (int)) ;

    for ( i = 0; i < tam_tabuleiro; i++){

        for ( j = 0; j < tam_tabuleiro; j++){

            scanf(" %c", &tabuleiro[i][j]);

        }

    }

    batalha_naval(tam_tabuleiro, tabuleiro);

    free(tabuleiro);

    return 0;

}

void batalha_naval(int N, char** tabuleiro){

    int i, j, cont_mais=0, submarino=0;

    for(i=0;i<N;i++){

        for(j=0;j<N;j++){

            if(tabuleiro[i][j] == '+') cont_mais++;

            if(tabuleiro[i][j] != '+'){

                if(cont_mais==2) submarino++;

            }

        }

        if(cont_mais==2) submarino++;

        cont_mais=0;
        
    }

    for(j=0;j<N;j++) {

        for(i=0;i<N;i++){

            if(tabuleiro[i][j]=='+') cont_mais++;

            if(tabuleiro[i][j]!='+'){

                if(cont_mais==2) submarino++;

            }

        }

        if(cont_mais==2) submarino++;

        cont_mais=0;

    }

    printf("%d", submarino);
    return;

}
