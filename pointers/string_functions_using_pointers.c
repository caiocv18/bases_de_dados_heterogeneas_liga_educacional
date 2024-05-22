//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Ponteiros";
    char dest[20];

    strcpy(dest, src);
    printf("String copiada: %s\n", dest);
    printf("Comprimento da string: %zu\n", strlen(dest));

    return 0;
}