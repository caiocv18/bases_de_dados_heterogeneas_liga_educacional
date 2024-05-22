//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

void printReverse(int *ptr, int size) {
    for(int i = size - 1; i >= 0; i--) {
        printf("Elemento %d: %d\n", i, *(ptr + i));
    }
}

int main_practical_effects_of_pointer_arithmetic() {
    int arr[5] = {10, 20, 30, 40, 50};
    printReverse(arr, 5); // Imprime o array em ordem reversa

    return 0;
}