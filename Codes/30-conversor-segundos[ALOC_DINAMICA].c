/*Faça uma função que, usando struct e seguindo o protótipo abaixo,
receba S como parâmetro e usando alocação dinâmica retorne um struct
contendo as horas, minutos e segundos que representam esse tempo S.
Por fim, na main, printe essa estrutura como mostrado no exemplo.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int segundo;
    int minuto;
    int hora;
    
}TEMPO;

TEMPO *time_conversor(int s);

int main() {

    int segundos;
    TEMPO *resultado;

    scanf("%d", &segundos);

    resultado=time_conversor(segundos);

    printf("H: %d\n", resultado->hora);
    printf("M: %d\n", resultado->minuto);
    printf("S: %d", resultado->segundo);

    free(resultado);

    return 0;

}

TEMPO *time_conversor(int s) {

    TEMPO *conversor;
    int resto;

    conversor=malloc(sizeof(TEMPO));

    (*conversor).hora=s/3600;
    resto=s%3600;
    (*conversor).minuto=resto/60;
    (*conversor).segundo=resto%60;

    return conversor;

}