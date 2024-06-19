//
// Created by caiocv18 on 19/06/2024.
//

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da pilha
struct StackNode {
    int data;
    struct StackNode *next;
};

// Função para criar um novo nó da pilha
struct StackNode *newNode(int data) {
    struct StackNode *stackNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Função para verificar se a pilha está vazia
int isEmpty(struct StackNode *root) {
    return !root;
}

// Função para empilhar um elemento
void push(struct StackNode **root, int data) {
    struct StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d empilhado na pilha\n", data);
}

// Função para desempilhar um elemento
int pop(struct StackNode **root) {
    if (isEmpty(*root))
        return -1;
    struct StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Função para visualizar o elemento no topo da pilha
int peek(struct StackNode *root) {
    if (isEmpty(root))
        return -1;
    return root->data;
}

int main_stack() {
    struct StackNode *root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("%d desempilhado da pilha\n", pop(&root));
    printf("Elemento no topo da pilha: %d\n", peek(root));

    return 0;
}