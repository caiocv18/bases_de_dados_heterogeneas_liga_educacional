//
// Created by caiocv18 on 12/05/2024.
//

#include <stdio.h>

int fourth_main() {
    // Introdução às estruturas de controle em C
    printf("Estruturas de controle em C são essenciais para direcionar o fluxo de execução de programas.\n");

    // Exemplo de if-else
    int idade = 20;
    printf("\nExemplo de if-else:\n");
    if (idade >= 18) {
        printf("Você é maior de idade.\n");
    } else {
        printf("Você é menor de idade.\n");
    }

    // Exemplo de switch
    char nota = 'B';
    printf("\nExemplo de switch:\n");
    switch (nota) {
    case 'A':
        printf("Excelente!\n");
        break;
    case 'B':
        printf("Ótimo!\n");
        break;
    case 'C':
        printf("Bom!\n");
        break;
    case 'D':
        printf("Você passou...\n");
        break;
    case 'F':
        printf("Tente novamente.\n");
        break;
    default:
        printf("Nota inválida.\n");
    }

    // Exemplo de for loop
    printf("\nExemplo de for loop:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Exemplo de while loop
    printf("\nExemplo de while loop:\n");
    int i = 1;
    while (i <= 5) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    // Exemplo de do-while loop
    printf("\nExemplo de do-while loop:\n");
    int j = 1;
    do {
        printf("%d ", j);
        j++;
    } while (j <= 5);
    printf("\n");

    return 0;
}
