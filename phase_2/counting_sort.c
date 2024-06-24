//
// Created by caiocv18 on 22/06/2024.
//
#include <stdio.h>

// Função que realiza o Counting Sort
void counting_sort(int array[], int size) {
    int output[10];
    int count[10];
    int max = array[0];

    // Encontra o elemento máximo no array
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Inicializa o array de contagem
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Armazena a contagem de cada elemento
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Armazena a contagem cumulativa de cada array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Encontra o índice de cada elemento do array original no array de contagem e coloca os elementos no array de saída
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copia o array de saída para o array original
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Função para imprimir um array
void print_array_counting_sort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Programa principal para testar a função acima
int main_counting_sort() {
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(array) / sizeof(array[0]);
    counting_sort(array, n);
    print_array_counting_sort(array, n);
}