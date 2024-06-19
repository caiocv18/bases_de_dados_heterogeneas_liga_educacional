//
// Created by caiocv18 on 19/06/2024.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} LinearList;

// Função para inicializar a lista linear
void initLinearList(LinearList *list) {
    list->size = 0;
}

// Função para inserir um elemento na lista linear
void insertLinearList(LinearList *list, int value, int position) {
    if (list->size == MAX) {
        printf("Lista cheia\n");
        return;
    }
    if (position < 0 || position > list->size) {
        printf("Posição inválida\n");
        return;
    }
    for (int i = list->size; i > position; i--) {
        list->arr[i] = list->arr[i - 1];
    }
    list->arr[position] = value;
    list->size++;
}

// Função para remover um elemento da lista linear
void removeLinearList(LinearList *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Posição inválida\n");
        return;
    }
    for (int i = position; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
}

// Função para imprimir a lista linear
void printLinearList(LinearList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

int main_linear_list() {
    LinearList list;
    initLinearList(&list);

    insertLinearList(&list, 10, 0);
    insertLinearList(&list, 20, 1);
    insertLinearList(&list, 30, 2);
    printLinearList(&list);

    removeLinearList(&list, 1);
    printLinearList(&list);

    return 0;
}