//
// Created by caiocv18 on 26/06/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INITIAL_CAPACITY 10

// Estrutura de dados para a pilha
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Função para inicializar a pilha
Stack* createStack_stack_postfix_infix() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = INITIAL_CAPACITY;
    stack->top = -1;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    if (stack->data == NULL) {
        perror("Falha na alocação de memória");
        exit(EXIT_FAILURE);
    }
    return stack;
}

// Função para verificar se a pilha está vazia
int isEmpty_stack_postfix_infix(Stack *stack) {
    return stack->top == -1;
}

// Função para verificar se a pilha está cheia
int isFull_stack_postfix_infix(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Função para redimensionar a pilha dinamicamente
void resizeStack_stack_postfix_infix(Stack *stack) {
    stack->capacity *= 2;
    stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
    if (stack->data == NULL) {
        perror("Falha na realocação de memória");
        exit(EXIT_FAILURE);
    }
}

// Função para empilhar um elemento
void push_stack_postfix_infix(Stack *stack, int value) {
    if (isFull_stack_postfix_infix(stack)) {
        resizeStack_stack_postfix_infix(stack);
    }
    stack->data[++stack->top] = value;
}

// Função para desempilhar um elemento
int pop_stack_postfix_infix(Stack *stack) {
    if (isEmpty_stack_postfix_infix(stack)) {
        perror("Pilha vazia");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Função para retornar o elemento do topo da pilha sem removê-lo
int peek_stack_postfix_infix(Stack *stack) {
    if (isEmpty_stack_postfix_infix(stack)) {
        perror("Pilha vazia");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

// Função para verificar a precedência dos operadores
int precedence_stack_postfix_infix(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

// Função para converter expressão infix para postfix
void infixToPostfix_stack_postfix_infix(char *infix, char *postfix) {
    Stack *stack = createStack_stack_postfix_infix();
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push_stack_postfix_infix(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty_stack_postfix_infix(stack) && peek_stack_postfix_infix(stack) != '(') {
                postfix[k++] = pop_stack_postfix_infix(stack);
            }
            pop_stack_postfix_infix(stack);
        } else {
            while (!isEmpty_stack_postfix_infix(stack) && precedence_stack_postfix_infix(peek_stack_postfix_infix(stack)) >= precedence_stack_postfix_infix(infix[i])) {
                postfix[k++] = pop_stack_postfix_infix(stack);
            }
            push_stack_postfix_infix(stack, infix[i]);
        }
    }
    while (!isEmpty_stack_postfix_infix(stack)) {
        postfix[k++] = pop_stack_postfix_infix(stack);
    }
    postfix[k] = '\0';
    free(stack->data);
    free(stack);
}

// Função para avaliar uma expressão postfix
int evaluatePostfix(char *postfix) {
    Stack *stack = createStack_stack_postfix_infix();
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push_stack_postfix_infix(stack, postfix[i] - '0');
        } else {
            int val2 = pop_stack_postfix_infix(stack);
            int val1 = pop_stack_postfix_infix(stack);
            switch (postfix[i]) {
                case '+': push_stack_postfix_infix(stack, val1 + val2); break;
                case '-': push_stack_postfix_infix(stack, val1 - val2); break;
                case '*': push_stack_postfix_infix(stack, val1 * val2); break;
                case '/': push_stack_postfix_infix(stack, val1 / val2); break;
                case '^': push_stack_postfix_infix(stack, val1 ^ val2); break;
            }
        }
    }
    int result = pop_stack_postfix_infix(stack);
    free(stack->data);
    free(stack);
    return result;
}

// Função principal para testar operações avançadas em pilhas
int main_stack_postfix_infix() {
    char infix[] = "3+(2*2)-(2/1)";
    char postfix[100];

    infixToPostfix_stack_postfix_infix(infix, postfix);
    printf("Expressão Infix: %s\n", infix);
    printf("Expressão Postfix: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Resultado da expressão postfix: %d\n", result);

    return 0;
}