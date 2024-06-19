//
// Created by caiocv18 on 25/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

int main_practical_examples_of_memory_allocation_and_release() {
    int n;
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Aloca memória para n inteiros

    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // Inicializa o array
    }

    printf("Elementos do array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr); // Libera a memória alocada

    return 0;
}