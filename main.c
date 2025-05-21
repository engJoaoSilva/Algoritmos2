/********************************
* Nome: Joao Marcos da Silva    *
* Curso: Sistemas de Informacao *
* Disciplina: Algoritmos II     *
********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação (Bubble Sort)
void ordenar(int v[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// Verifica se o número já está no vetor
int jaExiste(int v[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (v[i] == valor) {
            return 1; // já existe
        }
    }
    return 0; // não existe
}

int main() {
    int i = 0, num, n;

    printf("Informe quantos cheques a empresa gerou? ");
    scanf("%d", &n);

    // Forçar o usuario a digitar um valor valido
    while(1) {
        if(n > 1 && n <= 100)
            break;
        
        else {
            printf("\nNumero invalido de cheques!\n");
            printf("Informe quantos cheques a empresa gerou? ");
            scanf("%d", &n);
        }
    }

    // Cria o vetor com a quantidade exata de cheques
    int cheques[n];

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera números únicos de cheques entre 1 e 100
    while (i < n) {
        num = rand() % 100 + 1;
        if (!jaExiste(cheques, i, num)) {
            cheques[i] = num;
            i++;
        }
    }

    // Exibe os cheques antes da ordenação
    printf("Cheques antes da ordenacao:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", cheques[i]);
    }

    ordenar(cheques, n);

    // Exibe os cheques após a ordenação
    printf("\n\nCheques apos a ordenacao:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", cheques[i]);
    }
    
    return 0;
}
