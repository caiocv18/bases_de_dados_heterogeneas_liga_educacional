//
// Created by caiocv18 on 24/06/2024.
//
#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
struct Node {
    int key;
    struct Node *left, *right;
};

// Função para criar um novo nó de árvore
struct Node *newNode_tree_sort(int item) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Função para inserir um novo nó com uma chave específica na BST
struct Node* insert(struct Node* Node, int key) {
    // Caso base: se a árvore está vazia, retorna um novo nó
    if (Node == NULL) return newNode_tree_sort(key);

    // Caso contrário, percorre a árvore
    if (key < Node->key)
        Node->left  = insert(Node->left, key);
    else if (key > Node->key)
        Node->right = insert(Node->right, key);

    // Retorna o nó (inalterado)
    return Node;
}

// Função para percorrer a BST em ordem (in-order traversal)
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

// Função principal para o Tree Sort
void treeSort(int arr[], int n) {
    struct Node *root = NULL;

    // Constrói a BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        insert(root, arr[i]);

    // Imprime em ordem
    inorder(root);
}

int main_tree_sort() {
    int arr[] = {5, 4, 7, 2, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    treeSort(arr, n);

    return 0;
}