/*Toda fração pode ser representada por um numerador inteiro N (parte que será dividida)
e um denominador inteiro D (número que dividirá a parte).

Faça uma função que receba um vetor F de frações (cada uma com numerador e denominador) e
retorne um novo vetor de P apenas como as frações positivas.

Entrada:
    A primeira linha de entrada contém um inteiro K representando a quantidade de elementos
    do vetor. As próximas K linhas de entrada contém dois inteiros Ni e Di, separados por espaço,
    representando, respectivamente, o numerador e o denominador que formam aquela fração.

Saída:
    Faça uma função que, usando struct e seguindo o protótipo abaixo, receba K e F como parâmetros
    e, usando alocação e realocação, retorne um novo vetor P de struct contendo as frações positivas.
    Por fim, na main, printe este vetor */
#include <stdio.h>
#include <stdlib.h>

typedef struct{

    float numerador;
    float denominador;
    
}FRACAO;

FRACAO *fracoesPositivas(int k, FRACAO *f);

int main() {

    int qtdd_elementos, i;
    FRACAO *fracoes_inicial;
    FRACAO *fracoes_final;
    float divisao;

    scanf(" %d", &qtdd_elementos);

    fracoes_inicial=calloc(qtdd_elementos, sizeof(FRACAO));

    for ( i = 0; i < qtdd_elementos; i++) {
        
        scanf(" %f %f", &fracoes_inicial[i].numerador, &fracoes_inicial[i].denominador);

    }

    fracoes_final=fracoesPositivas(qtdd_elementos, fracoes_inicial);
    
    for ( i = 0; fracoes_final[i].denominador!=0; i++){
        
        divisao = fracoes_final[i].numerador/fracoes_final[i].denominador;
        printf("%.f/%.f=%.2f\n", fracoes_final[i].numerador, fracoes_final[i].denominador, divisao);

    }
    
    free(fracoes_final);

    return 0;

}

FRACAO *fracoesPositivas(int k, FRACAO *f){

    int i, j=0;
    
    for ( i = 0; i < k; i++){
        
        if (f[i].numerador/f[i].denominador > 0){
    
            f[j].numerador = f[i].numerador;
            f[j].denominador = f[i].denominador;
            j++;

        }

    }

    f = realloc (f, j * sizeof(FRACAO));

    f[j].numerador=0;
    f[j].denominador=0;

    return f;

}