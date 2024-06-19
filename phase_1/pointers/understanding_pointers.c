//
// Created by caiocv18 on 15/05/2024.
//

#include <stdio.h>

// Exemplo de uso de ponteiros

int main_pointers_1() {
    int x = 10;
    int* ptr = &x;

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Valor de ptr: %p\n", ptr);
    printf("Valor apontado por ptr: %d\n", *ptr);
    printf("Endereço de ptr: %p\n", &ptr);

    return 0;
}