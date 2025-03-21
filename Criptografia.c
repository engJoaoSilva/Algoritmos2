#include <stdio.h>
#include <string.h>

/**********************************************
*  Trabalho N1                                *
*  Nome: Joao Marcos da Silva                 *
*  Curso: Sistemas de Informação              *
*  Objetivo: Criptografar uma mensagem        *
**********************************************/

int main() {
    char frase[100];
    printf("Informe uma frase terminando com (;) : ");
    
    // Forçando o usuario a digitar uma frase terminando em (;)
    while(1) {
        scanf("%[^\n]", frase);
        if(frase[strlen(frase) - 1] == ';')
            break;
        else {
            __fpurge(stdin);
            printf("ERROR! frase precisa terminar com ;\n");
            printf("Informe uma frase novamente: ");
        } 
    }

    printf("Frase original: %s\n", frase);

    // Criptografando a frase digitada
    for(int i = 0; i < strlen(frase); i++) {
        if(frase[i] != ';') {
            frase[i] = (5 * frase[i] + 100) % 256;
        }
    }

    // Imprimindo a frase criptografada
    printf("Frase criptograda: ");
    printf("%s", frase);
    printf("\nTamanho da frase: %ld\n", strlen(frase));

    return 0;
}
