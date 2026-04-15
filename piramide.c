#include <stdio.h>

int main (void) {
    // Define variável de contagem
    int quant;
    printf("Digite um número: ");

    // Loop para aceitar somente números inteiros
    while (scanf("%d", &quant) != 1) {
        printf("Erro! Isso não é um número inteiro. Tente Novamente: ");

        while (getchar() != '\n');
    }

    // Contar as linhas
    for(int l = 0; l < quant; l++) {
        // Prencher a esquerda com espaços
        for(int s = 0; s < (quant - l - 1); s++){
            printf(" ");
        }
        // Prencher o resto com # e formar a piramide
        for(int c = 0; c < (2 * l + 1); c++) {
            printf("#");
        }
        // Proxima linha
        printf("\n");
    }
}
