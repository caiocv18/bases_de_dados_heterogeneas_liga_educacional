//
// Created by caiocv18 on 12/05/2024.
//

#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa pessoa = {"João Silva", 30, 1.75};

    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Altura: %.2f metros\n", pessoa.altura);

    return 0;
}