//
// Created by caiocv18 on 24/06/2024.
//
#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore AVL
typedef struct Node {
    int valor;
    struct Node* esq;
    struct Node* dir;
    int altura;
} Node;

// Função para obter a altura de um nó
int altura_avl_tree(Node* n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

// Função para obter o maior valor entre dois inteiros
int max_avl_tree(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
Node* novoNode_avl_tree(int valor) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->valor = valor;
    node->esq = NULL;
    node->dir = NULL;
    node->altura = 1; // Novo nó inicialmente adicionado na folha
    return(node);
}

// Rotação à direita
Node* rotacaoDireita_avl_tree(Node* y) {
    Node* x = y->esq;
    Node* T2 = x->dir;

    // Realiza a rotação
    x->dir = y;
    y->esq = T2;

    // Atualiza as alturas
    y->altura = max_avl_tree(altura_avl_tree(y->esq), altura_avl_tree(y->dir)) + 1;
    x->altura = max_avl_tree(altura_avl_tree(x->esq), altura_avl_tree(x->dir)) + 1;

    // Retorna a nova raiz
    return x;
}

// Rotação à esquerda
Node* rotacaoEsquerda_avl_tree(Node* x) {
    Node* y = x->dir;
    Node* T2 = y->esq;

    // Realiza a rotação
    y->esq = x;
    x->dir = T2;

    // Atualiza as alturas
    x->altura = max_avl_tree(altura_avl_tree(x->esq), altura_avl_tree(x->dir)) + 1;
    y->altura = max_avl_tree(altura_avl_tree(y->esq), altura_avl_tree(y->dir)) + 1;

    // Retorna a nova raiz
    return y;
}

// Obtém o fator de balanceamento de um nó
int getBalance_avl_tree(Node* n) {
    if (n == NULL)
        return 0;
    return altura_avl_tree(n->esq) - altura_avl_tree(n->dir);
}

// Função para inserir um novo valor na árvore AVL
Node* inserir_avl_tree(Node* node, int valor) {
    // 1. Realiza a inserção normal de uma árvore binária de busca
    if (node == NULL)
        return(novoNode_avl_tree(valor));

    if (valor < node->valor)
        node->esq = inserir_avl_tree(node->esq, valor);
    else if (valor > node->valor)
        node->dir = inserir_avl_tree(node->dir, valor);
    else // Valores iguais não são permitidos na árvore AVL
        return node;

    // 2. Atualiza a altura deste nó ancestral
    node->altura = 1 + max_avl_tree(altura_avl_tree(node->esq), altura_avl_tree(node->dir));

    // 3. Obtém o fator de balanceamento deste nó ancestral para verificar se este nó se tornou desbalanceado
    int balance = getBalance_avl_tree(node);

    // Se o nó se tornou desbalanceado, então há 4 casos

    // Caso Esquerda-Esquerda
    if (balance > 1 && valor < node->esq->valor)
        return rotacaoDireita_avl_tree(node);

    // Caso Direita-Direita
    if (balance < -1 && valor > node->dir->valor)
        return rotacaoEsquerda_avl_tree(node);

    // Caso Esquerda-Direita
    if (balance > 1 && valor > node->esq->valor) {
        node->esq = rotacaoEsquerda_avl_tree(node->esq);
        return rotacaoDireita_avl_tree(node);
    }

    // Caso Direita-Esquerda
    if (balance < -1 && valor < node->dir->valor) {
        node->dir = rotacaoDireita_avl_tree(node->dir);
        return rotacaoEsquerda_avl_tree(node);
    }

    // Retorna o ponteiro do nó (inalterado)
    return node;
}

// Função para buscar um valor na árvore AVL
Node* buscar_avl_tree(Node* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (raiz->valor < valor)
        return buscar_avl_tree(raiz->dir, valor);

    return buscar_avl_tree(raiz->esq, valor);
}

// Função para encontrar o nó com o menor valor (usado na remoção)
Node* minValorNode_avl_tree(Node* node) {
    Node* atual = node;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

// Função para remover um nó da árvore AVL
Node* remover_avl_tree(Node* raiz, int valor) {
    // 1. Realiza a remoção normal de uma árvore binária de busca
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor)
        raiz->esq = remover_avl_tree(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover_avl_tree(raiz->dir, valor);
    else {
        // nó com apenas um filho ou nenhum filho
        if ((raiz->esq == NULL) || (raiz->dir == NULL)) {
            Node* temp = raiz->esq ? raiz->esq : raiz->dir;

            // Sem filho
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else // Um filho
                *raiz = *temp; // Copia os conteúdos do filho não vazio

            free(temp);
        } else {
            // nó com dois filhos: Obtém o sucessor em ordem (menor na subárvore direita)
            Node* temp = minValorNode_avl_tree(raiz->dir);

            // Copia o valor do sucessor em ordem para este nó
            raiz->valor = temp->valor;

            // Remove o sucessor em ordem
            raiz->dir = remover_avl_tree(raiz->dir, temp->valor);
        }
    }

    // Se a árvore tinha apenas um nó, então retorna
    if (raiz == NULL)
        return raiz;

    // 2. Atualiza a altura do nó atual
    raiz->altura = 1 + max_avl_tree(altura_avl_tree(raiz->esq), altura_avl_tree(raiz->dir));

    // 3. Obtém o fator de balanceamento deste nó para verificar se este nó se tornou desbalanceado
    int balance = getBalance_avl_tree(raiz);

    // Se o nó se tornou desbalanceado, então há 4 casos

    // Caso Esquerda-Esquerda
    if (balance > 1 && getBalance_avl_tree(raiz->esq) >= 0)
        return rotacaoDireita_avl_tree(raiz);

    // Caso Esquerda-Direita
    if (balance > 1 && getBalance_avl_tree(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda_avl_tree(raiz->esq);
        return rotacaoDireita_avl_tree(raiz);
    }

    // Caso Direita-Direita
    if (balance < -1 && getBalance_avl_tree(raiz->dir) <= 0)
        return rotacaoEsquerda_avl_tree(raiz);

    // Caso Direita-Esquerda
    if (balance < -1 && getBalance_avl_tree(raiz->dir) > 0) {
        raiz->dir = rotacaoDireita_avl_tree(raiz->dir);
        return rotacaoEsquerda_avl_tree(raiz);
    }

    return raiz;
}

// Função para imprimir a árvore AVL em ordem (in-order traversal)
void imprimirEmOrdem(Node* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->dir);
    }
}

int main_avl_tree() {
    Node* raiz = NULL;

    // Inserindo valores na árvore AVL
    raiz = inserir_avl_tree(raiz, 10);
    raiz = inserir_avl_tree(raiz, 20);
    raiz = inserir_avl_tree(raiz, 30);
    raiz = inserir_avl_tree(raiz, 40);
    raiz = inserir_avl_tree(raiz, 50);
    raiz = inserir_avl_tree(raiz, 25);

    // Imprimindo a árvore em ordem
    printf("Árvore AVL em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    // Buscando valores na árvore AVL
    int valorParaBuscar = 30;
    Node* resultadoBusca = buscar_avl_tree(raiz, valorParaBuscar);
    if (resultadoBusca != NULL)
        printf("Valor %d encontrado na árvore AVL.\n", valorParaBuscar);
    else
        printf("Valor %d não encontrado na árvore AVL.\n", valorParaBuscar);

    // Removendo um valor da árvore AVL
    int valorParaRemover = 20;
    raiz = remover_avl_tree(raiz, valorParaRemover);
    printf("Árvore AVL após remover %d: ", valorParaRemover);
    imprimirEmOrdem(raiz);
    printf("\n");

    return 0;
}