//
// Created by caiocv18 on 13/05/2024.
//

#include <stdio.h>

// Função recursiva para calcular o n-ésimo número de Fibonacci
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci_main() {
    int n = 10; // Número de termos da sequência
    printf("Sequência de Fibonacci até o %d-ésimo termo:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
