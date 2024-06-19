//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

int main_array_and_pointers_1() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr; // ptr aponta para o primeiro elemento de arr

    for(int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, *(ptr + i));
    }

    return 0;
}