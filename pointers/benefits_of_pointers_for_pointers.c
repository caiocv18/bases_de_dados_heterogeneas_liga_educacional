//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

void modifyPointer(int **pptr) {
    static int b = 20;
    *pptr = &b;
}

int main() {
    int a = 10;
    int *ptr = &a;

    printf("Valor inicial de ptr: %p\n", ptr);
    printf("Valor apontado por ptr: %d\n", *ptr);

    modifyPointer(&ptr);

    printf("Novo valor de ptr: %p\n", ptr);
    printf("Novo valor apontado por ptr: %d\n", *ptr);

    return 0;
}