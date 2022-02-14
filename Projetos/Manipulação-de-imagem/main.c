/*Projeto realizado por Gabriella Alves de Oliveira*/

#include <stdio.h>
#include <stdlib.h>
#define LIMIAR 150

typedef struct{

    char tipo_arq[3];  //tipo do arquivo expresso em 2 caracteres. Ex: "P2", tipo_arq[3]='\0'
    int num_colunas;
    int num_linhas;
    int max_tom_cinza;
    int *matriz_img; //numero de pixels; "do pixel superior esquerdo ao pixel inferior direito"

}IMAGEM; //caracteristicas da imagem

void limiarizacao(IMAGEM image);
void negativo(IMAGEM image);
void histograma(IMAGEM image);

int main() {

    FILE *fp;
    IMAGEM image; //pegar infos da imagem
    int i, j;

    fp = fopen("saturn.pgm", "r");

    if (fp == NULL){
        
        printf("ERRO: Arquivo nao encontrado!\n");
        return 0;

    }

    fscanf(fp, "%s\n", image.tipo_arq);
    fscanf(fp, "%d ", &image.num_colunas);
    fscanf(fp, "%d\n", &image.num_linhas);
    fscanf(fp, "%d\n", &image.max_tom_cinza);
    
    image.matriz_img = (int*) malloc (image.num_colunas * image.num_linhas * sizeof(int));

    for ( i = 0; i < image.num_linhas; i++){

        for ( j = 0; j < image.num_colunas; j++){
            
            fscanf(fp, " %d", (image.matriz_img + ((i * image.num_colunas) + j)));

        }
        
    }

    limiarizacao(image);
    negativo(image);
    histograma(image);

    free(image.matriz_img);

    return 0;
    
}

void limiarizacao(IMAGEM image){

    FILE *file_lim;
    int i, j, aux;

    file_lim = fopen("thresholding.pgm", "w");

    fprintf(file_lim, " %s\n", image.tipo_arq);
    fprintf(file_lim, " %d ", image.num_colunas);
    fprintf(file_lim, " %d\n", image.num_linhas);
    fprintf(file_lim, " %d\n", image.max_tom_cinza);

    for ( i = 0; i < image.num_linhas; i++){

        for ( j = 0; j < image.num_colunas; j++){

            aux = *(image.matriz_img + (i * image.num_colunas) + j);

            if (aux <= LIMIAR){

                fprintf(file_lim, "%d ", 0);

            }

            if (aux > LIMIAR){

                fprintf(file_lim, "%d ", 255);

            }
            
        }
        
        fprintf(file_lim, "\n");

    }
    
    printf("SUCESSO: Limiarizacao thresholding.pgm criado!\n");
    fclose(file_lim);

}

void negativo(IMAGEM image){

    FILE *file_neg;
    int i, j, v;

    file_neg = fopen("negative.pgm", "w");

    fprintf(file_neg, "%s\n", image.tipo_arq);
    fprintf(file_neg, "%d ", image.num_colunas);
    fprintf(file_neg, "%d\n", image.num_linhas);
    fprintf(file_neg, "%d\n", image.max_tom_cinza);

    for ( i = 0; i < image.num_linhas; i++){

        for ( j = 0; j < image.num_colunas; j++) {

            v = *(image.matriz_img + (i * image.num_colunas) + j);
            v = 255 - v;

            fprintf(file_neg, "%d ", v);
            
        }

        fprintf(file_neg, "\n");
        
    }
    
    printf("SUCESSO: Negativo negative.pgm criado!\n");
    fclose(file_neg);

}

void histograma(IMAGEM image){

    FILE *file_hist;
    int i, j, k;
    int array [256] = {0}; 

    file_hist = fopen("histogram.txt", "w");

    fprintf(file_hist, "%s\n", image.tipo_arq);
    fprintf(file_hist, "%d ", image.num_colunas);
    fprintf(file_hist, "%d\n", image.num_linhas);
    fprintf(file_hist, "%d\n", image.max_tom_cinza);

    for ( i = 0; i < image.num_linhas; i++){

        for ( j = 0; j < image.num_colunas; j++){

            k = *(image.matriz_img + i * image.num_colunas + j);
            
            array[k]++;

        }

    }

    for ( i = 0; i < 256; i++) {

        fprintf(file_hist, "Tonalidade %d: %d\n", i, array[i]);

    }
    
    printf("SUCESSO: Histograma histogram.txt criado!");

    free(array);
    fclose(file_hist);

}
