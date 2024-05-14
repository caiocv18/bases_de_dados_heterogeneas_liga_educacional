//
// Created by caiocv18 on 14/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* create_node(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função recursiva para a travessia em ordem
void inorder_traversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorder_traversal(node->left);   // Percorre a subárvore esquerda
    printf("%d ", node->data);      // Visita o nó atual
    inorder_traversal(node->right);  // Percorre a subárvore direita
}

int main() {
    // Criando nós da árvore
    struct Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    // Travessia em ordem da árvore
    printf("Travessia em Ordem: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}
