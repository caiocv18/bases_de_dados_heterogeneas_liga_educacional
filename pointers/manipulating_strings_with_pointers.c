//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

int main_manipulating_strings_with_pointers() {
    char str[] = "Linguagem C";
    char *ptr = str;

    while (*ptr != '\0') {
        printf("%c ", *ptr);
        ptr++;
    }

    return 0;
}