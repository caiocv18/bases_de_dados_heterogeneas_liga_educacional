//
// Created by caiocv18 on 12/05/2024.
//

#include <stdio.h>

int third_main() {
    // Demonstração de tipos primitivos
    int idade = 30;
    char letra = 'A';
    float altura = 1.75f;
    double pi = 3.141592653589793;
    void *ptr = NULL;

    // Impressão dos tipos primitivos
    printf("Idade: %d\n", idade);
    printf("Letra: %c\n", letra);
    printf("Altura: %.2f metros\n", altura);
    printf("Valor de pi: %.15f\n", pi);

    // ptr é um ponteiro para void, não temos o que imprimir diretamente
    printf("Ponteiro: %p\n", ptr);

    // Demonstração de qualificadores de tipo
    unsigned int distancia = 4294967295; // Máximo para 32 bits
    signed int temperatura = -273;
    long int populacao = 7000000000;
    short int sala = 30;

    // Impressão dos qualificadores de tipo
    printf("Distância: %u\n", distancia);
    printf("Temperatura: %d\n", temperatura);
    printf("População estimada: %ld\n", populacao);
    printf("Número de alunos na sala: %hd\n", sala);

    return 0;
}
