//
// Created by caiov on 22/06/2024.
//
#include <stdio.h>

// Função para trocar dois elementos
void swap_heap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função para transformar um array em um heap
void heapify(int arr[], int n, int i) {
    int maior = i; // Inicializa o maior como a raiz
    int esquerda = 2*i + 1; // esquerda = 2*i + 1
    int direita = 2*i + 2; // direita = 2*i + 2

    // Se o filho da esquerda é maior que a raiz
    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    // Se o filho da direita é maior que a raiz
    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    // Se a maior não é a raiz
    if (maior != i) {
        swap_heap(&arr[i], &arr[maior]);

        // Recursivamente heapify a subárvore afetada
        heapify(arr, n, maior);
    }
}

// Função principal para fazer a ordenação heap
void heapSort(int arr[], int n) {
    // Construir heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Uma por uma extrai um elemento do heap
    for (int i=n-1; i>=0; i--) {
        // Move o nó raiz atual para o final
        swap_heap(&arr[0], &arr[i]);

        // chama max heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

// Função para imprimir um array de tamanho n
void print_array_heap(int arr[], int n) {
    for (int i=0; i<n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Programa principal
int main_heap() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("Array ordenado é \n");
    print_array_heap(arr, n);
}