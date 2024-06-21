//
// Created by caiocv18 on 21/06/2024.
//

#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nodo de lista ligada
struct Node {
    int data;
    struct Node* next;
};

// Função para trocar dados de dois nodos a e b
void swap(struct Node *a, struct Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Função para aplicar bubble sort na lista ligada
void bubbleSort2(struct Node *start) {
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
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

// Função para imprimir os nodos da lista ligada
void printList2(struct Node *start) {
    struct Node *temp = start;
    printf("\n");
    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Função para criar um novo nodo
struct Node *newNode2(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Função para adicionar um novo nodo no final da lista
void insertAtEnd(struct Node** start, int data) {
    struct Node *new_node = newNode2(data);
    struct Node *last = *start;

    if(*start == NULL) {
        *start = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

int main() {
    struct Node *start = newNode2(64);
    insertAtEnd(&start, 34);
    insertAtEnd(&start, 25);
    insertAtEnd(&start, 12);
    insertAtEnd(&start, 22);
    insertAtEnd(&start, 11);
    insertAtEnd(&start, 90);

    printf("Lista ligada antes de ser ordenada ");
    printList2(start);

    bubbleSort2(start);

    printf("\n\nLista ligada depois de ser ordenada ");
    printList2(start);

    return 0;
}
