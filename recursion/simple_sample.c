//
// Created by caiocv18 on 13/05/2024.
//

// exemplo de laço de repetição para apresentar 5 números utilizando recursividade

#include <stdio.h>

void print_numbers(int n) {
    if (n == 0) {
        return;
    }
    print_numbers(n - 1);
    printf("%d\n", n);
}

int main() {
    print_numbers(5);
    return 0;
}