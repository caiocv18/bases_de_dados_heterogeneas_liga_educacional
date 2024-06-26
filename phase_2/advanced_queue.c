//
// Created by caiocv18 on 26/06/2024.
//
#include <stdio.h>
#include <stdlib.h>

// Estrutura de dados para a fila circular
typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

// Função para inicializar a fila circular
CircularQueue* createCircularQueue(int capacity) {
    CircularQueue *queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->data == NULL) {
        perror("Falha na alocação de memória");
        exit(EXIT_FAILURE);
    }
    return queue;
}

// Função para verificar se a fila circular está cheia
int isFullCircular(CircularQueue* queue) {
    return (queue->size == queue->capacity);
}

// Função para verificar se a fila circular está vazia
int isEmptyCircular(CircularQueue* queue) {
    return (queue->size == 0);
}

// Função para adicionar um elemento à fila circular
void enqueueCircular(CircularQueue* queue, int item) {
    if (isFullCircular(queue)) {
        printf("Fila circular cheia\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
    printf("Adicionado %d à fila circular\n", item);
}

// Função para remover um elemento da fila circular
int dequeueCircular(CircularQueue* queue) {
    if (isEmptyCircular(queue)) {
        printf("Fila circular vazia\n");
        return -1;
    }
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Estrutura de dados para a fila de prioridade
typedef struct {
    int *data;
    int *priority;
    int size;
    int capacity;
} PriorityQueue;

// Função para inicializar a fila de prioridade
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue *queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->data = (int*)malloc(queue->capacity * sizeof(int));
    queue->priority = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->data == NULL || queue->priority == NULL) {
        perror("Falha na alocação de memória");
        exit(EXIT_FAILURE);
    }
    return queue;
}

// Função para verificar se a fila de prioridade está vazia
int isEmptyPriority(PriorityQueue* queue) {
    return (queue->size == 0);
}

// Função para adicionar um elemento à fila de prioridade
void enqueuePriority(PriorityQueue* queue, int item, int prio) {
    if (queue->size == queue->capacity) {
        printf("Fila de prioridade cheia\n");
        return;
    }
    int i;
    for (i = queue->size - 1; i >= 0; i--) {
        if (prio > queue->priority[i]) {
            queue->data[i + 1] = queue->data[i];
            queue->priority[i + 1] = queue->priority[i];
        } else {
            break;
        }
    }
    queue->data[i + 1] = item;
    queue->priority[i + 1] = prio;
    queue->size++;
    printf("Adicionado %d com prioridade %d à fila de prioridade\n", item, prio);
}

// Função para remover um elemento da fila de prioridade
int dequeuePriority(PriorityQueue* queue) {
    if (isEmptyPriority(queue)) {
        printf("Fila de prioridade vazia\n");
        return -1;
    }
    return queue->data[--queue->size];
}

// Função principal para testar operações avançadas em filas
int main_advanced_queue() {
    CircularQueue *circularQueue = createCircularQueue(5);

    enqueueCircular(circularQueue, 10);
    enqueueCircular(circularQueue, 20);
    enqueueCircular(circularQueue, 30);
    enqueueCircular(circularQueue, 40);
    enqueueCircular(circularQueue, 50);

    printf("Removido da fila circular: %d\n", dequeueCircular(circularQueue));
    printf("Removido da fila circular: %d\n", dequeueCircular(circularQueue));

    PriorityQueue *priorityQueue = createPriorityQueue(5);

    enqueuePriority(priorityQueue, 10, 1);
    enqueuePriority(priorityQueue, 20, 3);
    enqueuePriority(priorityQueue, 30, 2);
    enqueuePriority(priorityQueue, 40, 4);
    enqueuePriority(priorityQueue, 50, 5);

    printf("Removido da fila de prioridade: %d\n", dequeuePriority(priorityQueue));
    printf("Removido da fila de prioridade: %d\n", dequeuePriority(priorityQueue));

    // Liberando memória alocada
    free(circularQueue->data);
    free(circularQueue);
    free(priorityQueue->data);
    free(priorityQueue->priority);
    free(priorityQueue);

    return 0;
}