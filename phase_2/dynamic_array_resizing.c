//
// Created by caiocv18 on 26/06/2024.
//
#include <stdio.h>
#include <stdlib.h>

// Função para adicionar um elemento ao array dinâmico
void addElement(int **array, int *size, int *capacity, int element) {
    // Verifica se o array está cheio, se sim, dobra o tamanho
    if (*size >= *capacity) {
        *capacity *= 2;
        *array = realloc(*array, (*capacity) * sizeof(int));
        if (*array == NULL) {
            perror("Falha na realocação de memória");
            exit(EXIT_FAILURE);
        }
    }
    (*array)[*size] = element;
    (*size)++;
}

// Função para remover um elemento do array dinâmico
void removeElement(int **array, int *size, int *capacity) {
    if (*size > 0) {
        (*size)--;
        // Verifica se o array está menos do que um quarto cheio, se sim, reduz pela metade
        if (*size > 0 && *size <= (*capacity) / 4) {
            *capacity /= 2;
            *array = realloc(*array, (*capacity) * sizeof(int));
            if (*array == NULL) {
                perror("Falha na realocação de memória");
                exit(EXIT_FAILURE);
            }
        }
    }
}

// Função principal para testar o redimensionamento dinâmico
int main() {
    int *array = NULL;
    int size = 0;     // Número atual de elementos no array
    int capacity = 1; // Capacidade atual do array

    // Inicialmente, aloca espaço para um elemento
    array = malloc(capacity * sizeof(int));
    if (array == NULL) {
        perror("Falha na alocação de memória");
        return EXIT_FAILURE;
    }

    // Adiciona elementos ao array
    for (int i = 0; i < 10; i++) {
        addElement(&array, &size, &capacity, i + 1);
        printf("Adicionado: %d, Tamanho: %d, Capacidade: %d\n", i + 1, size, capacity);
    }

    // Remove elementos do array
    for (int i = 0; i < 5; i++) {
        removeElement(&array, &size, &capacity);
        printf("Removido: %d, Tamanho: %d, Capacidade: %d\n", i + 1, size, capacity);
    }

    // Libera a memória alocada
    free(array);

    return 0;
}