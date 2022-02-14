/*Escreva um programa que receba uma mensagem codificada
em língua do P e printe a mensagem decodificada.

Restrições:

   - A mensagem contém apenas letras maiúsculas e minúsculas e espaços em branco.
   - O tamanho máximo da mensagem é de 1000 caracteres.
   - Não há dois espaços em branco consecutivos na mensagem.
*/

#include <stdio.h>

int main() {

    char mensagem[1000];
    int auxiliar=1, i;

    scanf(" %[^\n]%*c", mensagem);

    for ( i = 0; ; i++){

        if (mensagem[i] == '\0'){
            break;
        }

        if (mensagem[i]==' '){
            printf("%c", mensagem[i]);
        }

        else{

            if (auxiliar%2==0){
                printf("%c", mensagem[i]);
            } 
            auxiliar++;
            
        }

    }   

}