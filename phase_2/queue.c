//
// Created by caiocv18 on 19/06/2024.
//

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da fila
struct QueueNode {
    int data;
    struct QueueNode *next;
};

// Estrutura para representar uma fila
struct Queue {
    struct QueueNode *front, *rear;
};

// Função para criar um novo nó da fila
struct QueueNode *newNodeQueue(int data) {
    struct QueueNode *temp = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Função para criar uma fila vazia
struct Queue *createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Função para enfileirar um elemento
void enqueue(struct Queue *q, int data) {
    struct QueueNode *temp = newNodeQueue(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    printf("%d enfileirado na fila\n", data);
}

// Função para desenfileirar um elemento
int dequeue(struct Queue *q) {
    if (q->front == NULL)
        return -1;
    struct QueueNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    int dequeued = temp->data;
    free(temp);
    return dequeued;
}

int main_queue() {
    struct Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("%d desenfileirado da fila\n", dequeue(q));

    return 0;
}