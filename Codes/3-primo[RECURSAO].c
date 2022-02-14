/*  Escreva um programa em C para checar se um número é primo usando Recursão.
Exemplo:
    - Entre um número inteiro positivo: 7
    - Saída: O número 7 é primo   */
int primo(int numero, int i);

int main(){

    int numero, verificador;
    printf("Insira um numero inteiro e positivo: ");
    scanf(" %d", &numero);

    verificador = primo(numero, numero/2); // é numero/2 pq 2 é o menor numero primo

    if (verificador == 1){
        printf("O numero %d eh primo", numero);
    }
    else{
        printf("O numero %d nao eh primo", numero);
    }
    
    return 0;
    
}

int primo(int numero, int i){

    
    if(i == 1){

        return 1;

    }

    else{

        if(numero%i == 0){
            return 0;
        }

        else{
            primo(numero, i-1);
        }

    }

}