//
// Created by caiocv18 on 22/06/2024.
//
#include  <stdio.h>

// Função para ordenar o array usando ShellSort
void shellSort(int arr[], int n) {
    // Começamos com um gap grande e reduzimos o gap
    int gap, i, j, temp;

    // gap é reduzido pela metade a cada iteração
    for (gap = n/2; gap > 0; gap /= 2) {
        // Fazemos um passo de inserção para cada gap
        for (i = gap; i < n; i++) {
            // Salvamos arr[i] em temp e criamos um espaço no local i
            temp = arr[i];

            // Deslocamos os elementos anteriores arr[0..i-1] que são maiores que temp
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // colocamos temp (o elemento original arr[i]) na sua posição correta
            arr[j] = temp;
        }
    }
}

// Função para imprimir um array
void print_array_shell(int arr[], int n) {
    int i;
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para testar a função acima
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array antes da ordenação: \n");
    print_array_shell(arr, n);

    shellSort(arr, n);

    printf("\nArray depois da ordenação: \n");
    print_array_shell(arr, n);

    return 0;
}