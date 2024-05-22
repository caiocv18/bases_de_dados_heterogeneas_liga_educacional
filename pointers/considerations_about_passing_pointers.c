//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

void safeModify(int *ptr) {
    if (ptr != NULL) {
        *ptr = 42; // Modifica o valor se o ponteiro não for nulo
    } else {
        printf("Erro: Ponteiro nulo!\n");
    }
}

int main() {
    int b = 0;
    safeModify(&b);
    printf("Valor de b após modificação segura: %d\n", b);

    int *nullPtr = NULL;
    safeModify(nullPtr); // Teste com ponteiro nulo

    return 0;
}