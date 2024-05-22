//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    char *ptr = str;

    while (*ptr != '\0') {
        printf("%c ", *ptr);
        ptr++; // Avança para o próximo caractere
    }

    return 0;
}