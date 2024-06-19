//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

void concatStrings(char *dest, const char *src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}

int main_advantages_of_using_pointers_in_strings() {
    char str1[20] = "Hello";
    char str2[] = " World";

    concatStrings(str1, str2);
    printf("String concatenada: %s\n", str1);

    return 0;
}