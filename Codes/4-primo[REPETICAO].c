/*Escreva um programa em C para checar se um número é primo usando Repetição.
Exemplo:
    - Entre um número inteiro positivo: 7
    - Saída: O número 7 é primo
*/

int primo();

int main(){

    int numero, i;
    int divisores=0;

    printf("Insira um numero inteiro e positivo: ");
    scanf(" %d", &numero);

    for ( i = 2; i <= numero/2 ; i++){
        
        if (numero%i == 0){
            divisores++;
        }
        
    }
    
    if (divisores == 0){
        printf("O numero %d eh primo", numero);
    }
    else{
        printf("O numero %d nao eh primo", numero);
    }
    
    return 0;
}