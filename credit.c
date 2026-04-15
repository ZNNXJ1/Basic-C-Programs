#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (void){
    // Variaveis que vão pegar os numeros "sujos" e ttransformar em números limpos
    char entrada[50];
    char so_numeros[20];

    int j = 0;
    int valido = 0;

    printf("Digite o número do seu cartão: ");

    // Loop que obriga o usúario a colocar entre 13 a 16 números inteiros
    do {
        fgets(entrada, sizeof(entrada), stdin);

        for(int i = 0; i < (int)strlen(entrada); i++){
            if(isdigit(entrada[i])){
                so_numeros[j] = entrada[i];
                j++;
            }
        }
        if(j >= 13 && j <= 16){
            valido = 1;
        } else {
            printf("Erro! O carão deve ter entre 13 e 16 dígitos: ");
            j = 0;
            continue;
        }
    } while(!valido);
    so_numeros[j] = '\0';

    // Variavel para guardar todo os numeros limpos, e long long pois o número ultrapassa a memória
    long long numero_final = atoll(so_numeros);

    // Variaveis para guardar valores e usar depois
    long long n = numero_final;
    long long primeiro_digito = numero_final;
    long long segundo_digito = numero_final;

    int soma =0;

    // Loop que verifica se o numero dado existe ou é inválido
    while(n > 0){
        int ultimo = n % 10;
        soma += ultimo;
        n = n / 10;

        if(n > 0){
            int penultimo = n % 10;
            int dobro = penultimo * 2;

            soma += (dobro % 10) + (dobro / 10);

            n = n / 10;
        }
    }
    if (soma % 10 == 0) {
        while (primeiro_digito >= 10) {
            primeiro_digito /= 10;
        }
        while (segundo_digito >= 100) {
            segundo_digito /= 10;
        }

        // Verifica de onde o cartão é
        if (j == 15 && (segundo_digito == 34 || segundo_digito == 37)) {
            printf("AMEX\n");
        }
        else if (j == 16 && (segundo_digito >= 51 && segundo_digito <= 55)) {
            printf("MASTERCARD\n");
        }
        else if ((j == 13 || j == 16) && primeiro_digito == 4) {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }  else {
        printf("INVALID\n");
    }

    // Exibe o número completo e o número de digítos
    printf("Numero limpo: %I64d\n", numero_final);
    printf("Quantidade de digitos: %d\n", j);

    return 0; 
}
