//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

int main_learning_malloc() {
    int *ptr = (int *)malloc(5 * sizeof(int)); // Aloca memória para 5 inteiros

    if (ptr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2; // Inicializa a memória alocada
        printf("%d ", ptr[i]);
    }

    free(ptr); // Libera a memória alocada

    return 0;
}