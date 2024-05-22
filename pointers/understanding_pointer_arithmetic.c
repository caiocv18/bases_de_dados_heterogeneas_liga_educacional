//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("Valor inicial de ptr: %p\n", ptr);
    ptr++; // Incrementa o ponteiro para o próximo elemento do array
    printf("Valor de ptr após incremento: %p\n", ptr);
    ptr--; // Decrementa o ponteiro para o elemento anterior do array
    printf("Valor de ptr após decremento: %p\n", ptr);

    return 0;
}