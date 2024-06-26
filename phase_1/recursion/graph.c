//
// Created by caiocv18 on 14/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Estrutura do nó da lista de adjacências
struct Node {
    int vertex;
    struct Node* next;
};

// Estrutura do grafo
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

// Função para criar um novo nó da lista de adjacências
struct Node* create_node_graph(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo
struct Graph* create_graph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Função para adicionar aresta
void add_edge(struct Graph* graph, int src, int dest) {
    // Adiciona aresta de src para dest
    struct Node* newNode = create_node_graph(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Adiciona aresta de dest para src (grafo não direcionado)
    newNode = create_node_graph(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Função recursiva de DFS
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visitando vértice %d\n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int graph_main() {
    struct Graph* graph = create_graph(6);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    add_edge(graph, 3, 5);

    printf("Busca em profundidade (DFS) a partir do vértice 0:\n");
    DFS(graph, 0);

    return 0;
}