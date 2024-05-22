//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

int main() {
    int a = 10;
    int *ptr = &a;      // Ponteiro para 'a'
    int **pptr = &ptr;  // Ponteiro para ponteiro

    printf("Valor de a: %d\n", a);
    printf("Valor de ptr: %p\n", ptr);
    printf("Valor apontado por ptr: %d\n", *ptr);
    printf("Valor de pptr: %p\n", pptr);
    printf("Valor apontado por pptr: %p\n", *pptr);
    printf("Valor apontado pelo valor apontado por pptr: %d\n", **pptr);

    return 0;
}