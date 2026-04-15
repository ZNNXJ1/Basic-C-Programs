#include <stdio.h>
#include <math.h>

int main (void) {
    // Variavel para pegar o valor em real
    float valor_real;
    // Variavel da contagem de moedas totais
    int moeda = 0; 
    printf("Digite sua dívida: ");

    // Loop para aceitar somente números
    while(scanf("%f", &valor_real) != 1){
        printf("Erro! Caractere Inválido. Tente Novamente: ");

        while(getchar() != '\n');
    }

    // Se o valor for negativo ou 0, ent n tem dívida
    if(valor_real <= 0){
        printf("Sem Dívidas!");
        return 0;
    }

    // transformar número real em inteiro arrendondando
    int valor_final = round(valor_real * 100);
    int valor_inicial = valor_final;

    // Início dos loops, onde tira 25 até n dar mais, depois 10 e por ai vai
    while(valor_final >= 25){
        valor_final = valor_final - 25;
        moeda++;
    }
    while(valor_final >= 10){
        valor_final = valor_final - 10;
        moeda++;
    }
    while(valor_final >= 5){
        valor_final = valor_final - 5;
        moeda++;
    }
    while(valor_final >= 1){
        valor_final = valor_final - 1;
        moeda++;
    }

    // Mostrar a divida em número real,divida em numeros inteiro e em centavos e quantas moedas serào necessarias
    printf("Sua dívida: %.2f\nSua dívida em centavo(s): %d\nTotal de moedas necessárias: %d", valor_real, valor_inicial, moeda);
}
