//
// Created by caiocv18 on 24/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(5 * sizeof(int)); // Aloca memória para 5 inteiros

    if (ptr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Uso do ponteiro

    free(ptr); // Libera a memória alocada

    return 0;
}