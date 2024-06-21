//
// Created by caiocv18 on 21/06/2024.
//
#include <stdio.h>

// Função para realizar a ordenação usando o algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
   int i, j, temp;

   // Loop externo para passar por todos os elementos
   for(i = 0; i < n-1; i++) {
      // Loop interno para realizar a comparação entre elementos adjacentes
      for(j = 0; j < n-i-1; j++) {
         // Troca os elementos se estiverem na ordem errada
         if(arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

int main_buble_sort() {
   // Inicializa um array com elementos desordenados
   int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
   // Calcula o tamanho do array
   int n = sizeof(arr) / sizeof(arr[0]);

   // Chama a função bubbleSort para ordenar o array
   bubbleSort(arr, n);

   // Imprime o array ordenado
   printf("Array ordenado: \n");
   for(int i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n"); // Adiciona uma nova linha após a impressão do array

   return 0;
}
