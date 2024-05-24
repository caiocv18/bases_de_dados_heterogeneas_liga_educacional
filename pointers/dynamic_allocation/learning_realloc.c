//
// Created by caiocv18 on 23/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(5 * sizeof(int)); // Aloca memória para 5 inteiros

    if (ptr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2;
    }

    // Redimensiona o array para 10 inteiros
    ptr = (int *)realloc(ptr, 10 * sizeof(int));

    if (ptr == NULL) {
        printf("Erro ao realocar memória.\n");
        return 1;
    }

    for (int i = 5; i < 10; i++) {
        ptr[i] = i * 2;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr); // Libera a memória alocada

    return 0;
}