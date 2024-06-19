//
// Created by caiocv18 on 19/06/2024.
//

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista encadeada
struct Node {
    int data;
    struct Node *next;
};

// Função para adicionar um novo nó no início da lista
void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Função para remover o primeiro nó da lista
void deleteFirst(struct Node **head_ref) {
    if (*head_ref == NULL) return;
    struct Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// Função para imprimir a lista encadeada
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main_list() {
    struct Node *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    printf("Lista encadeada: ");
    printList(head);

    deleteFirst(&head);
    printf("Lista após remover o primeiro nó: ");
    printList(head);

    return 0;
}