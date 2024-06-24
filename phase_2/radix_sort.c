//
// Created by caiocv18 on 24/06/2024.
//
#include <stdio.h>

// Função para obter o máximo valor em arr[]
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Função para fazer a contagem e ordenação dos dígitos baseado no expoente
void countSort(int arr[], int n, int exp) {
    int output[n]; // Array de saída
    int count[10] = {0};

    // Contar o número de ocorrências em count[]
    for (int i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    // Mudar count[i] para que ele se torne a posição atual do dígito no output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construir o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    // Copiar o array de saída para arr[], de modo que arr[] contenha os números ordenados
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Função que implementa o Radix Sort
void radixsort(int arr[], int n) {
    // Encontrar o maior número para saber o número de dígitos
    int max = getMax(arr, n);

    // Fazer a contagem e ordenação para cada dígito. Note que ao invés de passar o número de dígitos, exp é passado. exp é 10^i onde i é o dígito atual
    for (int exp = 1; max/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Função para imprimir o array
void print_radix_sort(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Programa principal para testar a função acima
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print_radix_sort(arr, n);
    return 0;
}