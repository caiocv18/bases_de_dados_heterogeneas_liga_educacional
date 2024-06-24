//
// Created by caiocv18 on 24/06/2024.
//
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct node {
    int valor;           // Valor armazenado no nó
    struct node* esq;    // Ponteiro para o filho esquerdo
    struct node* dir;    // Ponteiro para o filho direito
} node;

// Função para criar um novo nó com um valor específico
node* novoNode_binary_tree(int valor) {
    node* novo = (node*)malloc(sizeof(node));  // Aloca memória para um novo nó
    novo->valor = valor;                       // Define o valor do novo nó
    novo->esq = NULL;                          // Inicializa o filho esquerdo como NULL
    novo->dir = NULL;                          // Inicializa o filho direito como NULL
    return novo;                               // Retorna o novo nó
}

// Função para inserir um valor na árvore
node* inserir_binary_tree(node* raiz, int valor) {
    if (raiz == NULL) // Se a raiz é NULL, cria um novo nó
        return novoNode_binary_tree(valor);
    if (valor < raiz->valor) // Se o valor é menor que o valor da raiz, insere na subárvore esquerda
        raiz->esq = inserir_binary_tree(raiz->esq, valor);
    else if (valor > raiz->valor) // Se o valor é maior que o valor da raiz, insere na subárvore direita
        raiz->dir = inserir_binary_tree(raiz->dir, valor);
    return raiz; // Retorna a raiz (inalterada, exceto para inserção de novos nós)
}

// Função para buscar um valor na árvore
node* buscar_binary_tree(node* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) // Se a raiz é NULL ou o valor é encontrado, retorna a raiz
        return raiz;
    if (raiz->valor < valor) // Se o valor da raiz é menor que o valor buscado, busca na subárvore direita
        return buscar_binary_tree(raiz->dir, valor);
    return buscar_binary_tree(raiz->esq, valor); // Se o valor da raiz é maior que o valor buscado, busca na subárvore esquerda
}

// Função para encontrar o nó com o menor valor na árvore (usado na remoção)
node* minValorNode_binary_tree(node* node) {
    struct node* current = node;
    while (current && current->esq != NULL) // Percorre a subárvore esquerda para encontrar o menor valor
        current = current->esq;
    return current; // Retorna o nó com o menor valor
}

// Função para remover um valor da árvore
node* remover_binary_tree(node* raiz, int valor) {
    if (raiz == NULL) // Se a árvore está vazia, retorna NULL
        return raiz;
    if (valor < raiz->valor) // Se o valor a ser removido é menor que o valor da raiz, remove da subárvore esquerda
        raiz->esq = remover_binary_tree(raiz->esq, valor);
    else if (valor > raiz->valor) // Se o valor a ser removido é maior que o valor da raiz, remove da subárvore direita
        raiz->dir = remover_binary_tree(raiz->dir, valor);
    else {
        // Se o valor é igual ao valor da raiz, este é o nó a ser removido
        if (raiz->esq == NULL) { // Nó com apenas um filho ou sem filhos (filho direito)
            struct node* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) { // Nó com apenas um filho ou sem filhos (filho esquerdo)
            struct node* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        // Nó com dois filhos: pega o sucessor em ordem (menor na subárvore direita)
        struct node* temp = minValorNode_binary_tree(raiz->dir);
        raiz->valor = temp->valor; // Copia o valor do sucessor para o nó atual
        raiz->dir = remover_binary_tree(raiz->dir, temp->valor); // Remove o sucessor em ordem
    }
    return raiz; // Retorna a raiz (possivelmente modificada)
}

// Função para imprimir a árvore em ordem (in-order traversal)
void imprimirEmOrdem_binary_tree(node* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem_binary_tree(raiz->esq);
        printf("%d ", raiz->valor);
        imprimirEmOrdem_binary_tree(raiz->dir);
    }
}

int main_binary_tree() {
    node* raiz = NULL; // Inicializa a raiz da árvore como NULL

    // Inserindo valores na árvore
    raiz = inserir_binary_tree(raiz, 50);
    raiz = inserir_binary_tree(raiz, 30);
    raiz = inserir_binary_tree(raiz, 20);
    raiz = inserir_binary_tree(raiz, 40);
    raiz = inserir_binary_tree(raiz, 70);
    raiz = inserir_binary_tree(raiz, 60);
    raiz = inserir_binary_tree(raiz, 80);

    // Imprimindo a árvore em ordem
    printf("Árvore em ordem: ");
    imprimirEmOrdem_binary_tree(raiz);
    printf("\n");

    // Buscando valores na árvore
    int valorParaBuscar = 40;
    node* resultadoBusca = buscar_binary_tree(raiz, valorParaBuscar);
    if (resultadoBusca != NULL)
        printf("Valor %d encontrado na árvore.\n", valorParaBuscar);
    else
        printf("Valor %d não encontrado na árvore.\n", valorParaBuscar);

    // Removendo um valor da árvore
    int valorParaRemover = 50;
    raiz = remover_binary_tree(raiz, valorParaRemover);
    printf("Árvore após remover %d: ", valorParaRemover);
    imprimirEmOrdem_binary_tree(raiz);
    printf("\n");

    return 0;
}