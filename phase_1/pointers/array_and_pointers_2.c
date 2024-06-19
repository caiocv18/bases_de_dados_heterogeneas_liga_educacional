//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

void reverseArray(int *ptr, int size) {
    int temp;
    for(int i = 0; i < size / 2; i++) {
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + (size - 1 - i));
        *(ptr + (size - 1 - i)) = temp;
    }
}

int main_array_with_pointers_2() {
    int arr[5] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);

    for(int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, arr[i]);
    }

    return 0;
}
