//
// Created by caiocv18 on 12/05/2024.
//
#include <stdio.h>

int eighth_main()
{
    // Array de inteiros
    int numeros[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++)
    {
        printf("Número na posição %d: %d\n", i, numeros[i]);
    }

    // Array de caracteres (String)
    char saudacao[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("\nSaudação: %s\n", saudacao);

    // Array de ponto flutuante
    double temperaturas[3] = {36.5, 37.2, 38.1};
    for (int i = 0; i < 3; i++)
    {
        printf("Temperatura %d: %.1f\n", i, temperaturas[i]);
    }

    // Array bidimensional (Matriz)
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Elemento [%d][%d]: %d\n", i, j, matriz[i][j]);
        }
    }

    // Array tridimensional
    int cubo[2][2][2] = {
        {
            {1, 2},
            {3, 4}
        },
        {
            {5, 6},
            {7, 8}
        }
    };
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                printf("Elemento [%d][%d][%d]: %d\n", i, j, k, cubo[i][j][k]);
            }
        }
    }

    return 0;
}
