//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

int main() {
    char str[] = "Linguagem C";
    char *ptr = str;

    while (*ptr != '\0') {
        printf("%c ", *ptr);
        ptr++;
    }

    return 0;
}