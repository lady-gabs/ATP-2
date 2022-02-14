#include <stdio.h>
#include <stdlib.h>

void quick_sort(char* array, int esquerda, int direita);

int main() {

    int tam, i;
    char *baralho;

    scanf(" %d", &tam);

    baralho = (char*) malloc (tam * sizeof(char));

    for ( i = 0; i < tam; i++){
        
        scanf(" %c", &baralho[i]);

    }

    baralho[tam] = '\0';
    
    quick_sort(baralho, 0, tam);

    for ( i = 0; i < tam; i++){

        printf("%c ", baralho[i]);

    }
    
    return 0;

}

void quick_sort(char* array, int esquerda, int direita){

    int i, j, pivo, aux;

	i = esquerda;
	j = direita-1;
	pivo = array[(esquerda + direita) / 2];

	while(i <= j)
	{
		while(array[i] > pivo && i < direita)
		{
			i++;
		}
		while(array[j] < pivo && j > esquerda)
		{
			j--;
		}
		if(i <= j)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			i++;
			j--;
		}
	}

	if(j > esquerda)
		quick_sort(array, esquerda, j+1);
	if(i < direita)
		quick_sort(array, i, direita);
      
    return;

}