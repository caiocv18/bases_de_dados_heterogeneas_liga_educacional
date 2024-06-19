//
// Created by caiocv18 on 14/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista ligada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* create_node_linked_list(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função recursiva para imprimir a lista
void print_list(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d -> ", node->data);
    print_list(node->next);  // Chamada recursiva para o próximo nó
}

// Função recursiva para buscar um elemento na lista
struct Node* search(struct Node* node, int key) {
    if (node == NULL || node->data == key) {
        return node;
    }
    return search(node->next, key);  // Chamada recursiva para o próximo nó
}

// Função recursiva para inserir um elemento no final da lista
void insert_at_end(struct Node** head, int data) {
    if (*head == NULL) {
        *head = create_node_linked_list(data);
        return;
    }
    insert_at_end(&(*head)->next, data);  // Chamada recursiva para o próximo nó
}

// Função recursiva para remover um nó com um valor específico
struct Node* delete_node(struct Node* head, int key) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    head->next = delete_node(head->next, key);  // Chamada recursiva para o próximo nó
    return head;
}

int linked_list_main() {
    struct Node* head = NULL;

    // Inserir elementos na lista
    insert_at_end(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);

    // Imprimir a lista
    printf("Lista: ");
    print_list(head);
    printf("NULL\n");

    // Buscar um elemento
    int key = 3;
    struct Node* found = search(head, key);
    if (found != NULL) {
        printf("Elemento %d encontrado.\n", key);
    } else {
        printf("Elemento %d não encontrado.\n", key);
    }

    // Remover um elemento
    head = delete_node(head, 2);
    printf("Lista após remover 2: ");
    print_list(head);
    printf("NULL\n");

    return 0;
}
