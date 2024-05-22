//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

void allocateArray(int ***array, int rows, int cols) {
    *array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*array)[i] = (int *)malloc(cols * sizeof(int));
    }
}

void freeArray(int ***array, int rows) {
    for (int i = 0; i < rows; i++) {
        free((*array)[i]);
    }
    free(*array);
}

int main() {
    int **array;
    int rows = 3, cols = 4;

    allocateArray(&array, rows, cols);

    // Usar o array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    freeArray(&array, rows);

    return 0;
}