//
// Created by caiocv18 on 21/06/2024.
//

#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        // Encontra o menor elemento na lista não ordenada
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Troca o menor elemento encontrado com o primeiro
        // elemento da lista não ordenada
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Array ordenado: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}