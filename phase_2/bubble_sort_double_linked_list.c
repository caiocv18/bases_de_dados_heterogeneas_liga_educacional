//
// Created by caiocv18 on 21/06/2024.
//
#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nodo de lista duplamente ligada
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Função para trocar dados de dois nodos a e b
void swap2(struct Node *a, struct Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Função para aplicar bubble sort na lista duplamente ligada
void bubbleSort3(struct Node *start) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    // Checagem de lista vazia
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap2(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

// Função para imprimir os nodos da lista duplamente ligada
void printList3(struct Node *start) {
    struct Node *temp = start;
    printf("\n");
    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Função para criar um novo nodo
struct Node *newNode3(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Função para adicionar um novo nodo no final da lista
void insertAtEnd3(struct Node** start, int data) {
    struct Node *new_node = newNode3(data);
    struct Node *last = *start;

    if(*start == NULL) {
        *start = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

int main_bubble_sort_doubly_linked_list() {
    struct Node *start = newNode3(64);
    insertAtEnd3(&start, 34);
    insertAtEnd3(&start, 25);
    insertAtEnd3(&start, 12);
    insertAtEnd3(&start, 22);
    insertAtEnd3(&start, 11);
    insertAtEnd3(&start, 90);

    printf("Lista duplamente ligada antes de ser ordenada ");
    printList3(start);

    bubbleSort3(start);

    printf("\n\nLista duplamente ligada depois de ser ordenada ");
    printList3(start);

    return 0;
}