//
// Created by caiocv18 on 11/05/2024.
//
#include <stdio.h>

union Dados {
    int inteiro;
    float flutuante;
    char* texto;
};

int second_main() {
    union Dados dados;

    dados.inteiro = 42;
    printf("Valor inteiro: %d\n", dados.inteiro);

    dados.flutuante = 3.1415;
    // Neste ponto, o valor de `inteiro` pode ser corrompido devido à nova atribuição a `flutuante`
    printf("Valor flutuante: %f\n", dados.flutuante);

    dados.texto = "Olá, mundo!";
    // Neste ponto, os valores de `inteiro` e `flutuante` são indefinidos
    printf("Valor texto: %s\n", dados.texto);

    return 0;
}