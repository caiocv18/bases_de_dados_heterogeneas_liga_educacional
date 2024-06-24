//
// Created by caiocv18 on 24/06/2024.
//

#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Estrutura para representar um bucket
typedef struct Bucket {
    int* data;
    int count;
} Bucket;

// Função para inicializar os buckets
void initializeBuckets(Bucket* buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].data = (int*)malloc(BUCKET_SIZE * sizeof(int));
        buckets[i].count = 0;
    }
}

// Função para ordenar um array usando insertion sort
void insertionSort_bucket_sort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para liberar a memória alocada para os buckets
void freeBuckets(Bucket* buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].data);
    }
}

// Função para encontrar o valor máximo no array
int findMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função principal do Bucket Sort
void bucketSort(int* arr, int size) {
    int max = findMax(arr, size);
    int numBuckets = max / BUCKET_SIZE + 1;

    // Aloca memória para os buckets
    Bucket* buckets = (Bucket*)malloc(numBuckets * sizeof(Bucket));
    initializeBuckets(buckets, numBuckets);

    // Distribui os elementos nos buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        buckets[bucketIndex].data[buckets[bucketIndex].count++] = arr[i];
    }

    // Ordena individualmente cada bucket e combina os resultados
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i].count > 0) {
            insertionSort_bucket_sort(buckets[i].data, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index++] = buckets[i].data[j];
            }
        }
    }

    // Libera a memória alocada para os buckets
    freeBuckets(buckets, numBuckets);
    free(buckets);
}

// Função auxiliar para imprimir o array
void printArray_bucket_sort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main_bucket_sort() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação: ");
    printArray_bucket_sort(arr, size);

    bucketSort(arr, size);

    printf("Array após a ordenação: ");
    printArray_bucket_sort(arr, size);

    return 0;
}