//
// Created by caiocv18 22/05/2024.
//

#include <stdio.h>

int main_addition_and_subtraction_with_pointers() {
    int arr[5] = {100, 200, 300, 400, 500};
    int *ptr = arr;

    printf("Elemento na posição 0: %d\n", *ptr);
    printf("Elemento na posição 2: %d\n", *(ptr + 2)); // Acessa o terceiro elemento
    printf("Elemento na posição 4: %d\n", *(ptr + 4)); // Acessa o quinto elemento

    return 0;
}