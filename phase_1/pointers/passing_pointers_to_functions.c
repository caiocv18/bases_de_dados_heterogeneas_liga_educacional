//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

void modifyValue(int *ptr) {
    *ptr = 20; // Modifica o valor da variável apontada pelo ponteiro
}

int main_passing_pointers_to_functions() {
    int a = 10;
    printf("Valor de a antes da modificação: %d\n", a);

    modifyValue(&a); // Passa o endereço de 'a' para a função
    printf("Valor de a após a modificação: %d\n", a);

    return 0;
}