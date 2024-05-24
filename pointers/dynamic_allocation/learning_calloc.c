//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

int main_learning_calloc() {
    int *ptr = (int *)calloc(5, sizeof(int)); // Aloca memória para 5 inteiros e inicializa com zero

    if (ptr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]); // Imprime os valores inicializados com zero
    }

    free(ptr); // Libera a memória alocada

    return 0;
}