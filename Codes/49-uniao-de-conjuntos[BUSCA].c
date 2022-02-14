#include <stdio.h>
#include <stdlib.h>

int RemoveRepetido(int tam,int *uniao);

int main() {

    int numA, numB, i, num; //numA e numB = numero de elementos de A e B
    int *A, *B, *uniao;

    scanf(" %d %d", &numA, &numB);

    num=numA+numB;

    A = (int*) malloc (numA*sizeof(int));
    B = (int*) malloc (numB*sizeof(int));
    uniao = (int*) malloc ((numA+numB)*sizeof(int));


    for (i = 0; i < numA; i++){
        
        scanf(" %d", &A[i]);

    }
    
    for (i = 0; i < numB; i++){
        
        scanf(" %d", &B[i]);

    }

    // A = ordenar(numA, A);
    // B = ordenar(numB, B);

    for ( i = 0; i < numA; i++){

        uniao[i]=A[i];
        
    }

    for ( i = 0; i < numB; i++){

        uniao[numA+i]=B[i];
        
    }   

    int tam = RemoveRepetido(num, uniao);

    uniao[tam]='\0';

    for(i = 0; i < tam; i++){

        printf("%d ",uniao[i]);
    
    }

    return 0;

}

// int *ordenar(int N, int *conjunto){

//     int i, j, aux;

//     for (i=0;i<N; i++){

//         for(j = i+1; j<N; j++){

//             if (conjunto[i]>conjunto[j]){

//                 aux=conjunto[i];
//                 conjunto[i]=conjunto[j];
//                 conjunto[j]=aux;

//             }

//         }

//     }

//     return conjunto;

// }

int RemoveRepetido(int tam,int *uniao){

    int i,j,k;

    for(i=0;i<tam;i++){

        for(j=i+1;j<tam;){

            if(uniao[i]==uniao[j]){

                for(k=j;k<tam;k++){

                    uniao[k]=uniao[k+1];

                }

                tam--;

            } else{

                j++;

            }

        }

    }

    return tam;

}


