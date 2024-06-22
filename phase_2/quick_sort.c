//
// Created by caiocv18 on 22/06/2024.
//
#include <stdio.h>

// Função para trocar dois elementos
void swap_quick_sort(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função que toma o último elemento como pivô, coloca o elemento pivô em sua posição correta na lista ordenada, e coloca os menores à esquerda do pivô e os maiores à direita
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_quick_sort(&arr[i], &arr[j]);
        }
    }
    swap_quick_sort(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal que implementa QuickSort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Função para imprimir um array
void print_array_quick_sort(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Programa principal para testar as funções acima
int main_quick_sort() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    printf("Array ordenado: \n");
    print_array_quick_sort(arr, n);
    return 0;
}