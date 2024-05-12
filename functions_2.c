//
// Created by caiocv18 on 12/05/2024.
//
#include <stdio.h>

// Declaração de função com parâmetros e retorno
int soma(int a, int b);

int main() {
    int resultado = soma(5, 3);
    printf("O resultado da soma é: %d\n", resultado);
    return 0;
}

// Definição de função
int soma(int a, int b) {
    return a + b;  // Retorna a soma de a e b
}