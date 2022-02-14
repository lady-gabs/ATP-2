#include <stdio.h>
#include <stdlib.h>

int *cria_sequencia(int R, int N, int* Ai);
int busca_termo(int N, int* Ai, int* progressao);

int main() {

    int R, N; //R= razão PA, N= numero de termos que Gabriela escreveu
    int *sequencia_gabi, *sequencia_real;
    int i, indice_perdido;

    scanf(" %d %d", &R, &N);

    sequencia_gabi = (int*) malloc (N*sizeof(int));
    sequencia_real = (int*) malloc (N*sizeof(int));
    
    for ( i = 0; i < N; i++){
        
        scanf(" %d", &sequencia_gabi[i]);

    }
    
    sequencia_gabi[N]='\0';

    sequencia_real=cria_sequencia(R,N,sequencia_gabi);

    indice_perdido = busca_termo(N, sequencia_gabi, sequencia_real);

    if(indice_perdido != -1) printf("%d", sequencia_real[indice_perdido]);
    //if(indice_perdido == -1) printf("Progressão correta");

    free(sequencia_gabi);
    free(sequencia_real);

    return 0;

}

int *cria_sequencia(int R, int N, int* Ai){

    int *progressao;
    int i;
    int a1 = Ai[0];

    progressao = (int *) malloc (N*sizeof(int));

    for ( i = 0; i <= N; i++){

        progressao[i]=a1+(i*R);

    }
    
    return progressao;

}

int busca_termo(int N, int* Ai, int* progressao){

    int i;

    for ( i = 0; Ai[i] == progressao[i]; i++){
        
        if (i >= N){
            return -1;
        }       

    }
    
    return i;

}