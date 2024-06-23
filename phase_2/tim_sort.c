//
// Created by caiocv18 on 22/06/2024.
//
#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b)) // Define o mínimo entre a e b
void insertion_sort_tim_sort(int arr[], int left, int right) {
    // Implementação do Insertion Sort
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge_tim_sort(int arr[], int l, int m, int r) {
    // Implementação do Merge Sort
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void timSort(int arr[], int n) {
    const int RUN = 32;
    // Ordenando subarrays de tamanho RUN
    for (int i = 0; i < n; i+=RUN)
        insertion_sort_tim_sort(arr, i, MIN((i+RUN-1), (n-1)));
    // Juntando os subarrays
    for (int size = RUN; size < n; size = 2*size) {
        for (int left = 0; left < n; left += 2*size) {
            int mid = left + size - 1;
            int right = MIN((left + 2*size - 1), (n-1));
            merge_tim_sort(arr, left, mid, right);
        }
    }
}

void print_array_tim_sort(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main_tim_sort() {
    int arr[] = {5, 21, 7, 23, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Lista antes da ordenação: \n");
    print_array_tim_sort(arr, n);

    timSort(arr, n);

    printf("Lista após a ordenação: \n");
    print_array_tim_sort(arr, n);
    return 0;
}