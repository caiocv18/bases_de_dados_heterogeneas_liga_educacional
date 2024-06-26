//
// Created by caiocv18 on 26/06/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define NUM_NODES 3
#define BUFFER_SIZE 1024

typedef struct {
    int id;
    char data[BUFFER_SIZE];
} Record;

Record database[NUM_NODES][BUFFER_SIZE];
int record_count[NUM_NODES] = {0};
pthread_mutex_t lock[NUM_NODES];

void insert_record(int node_id, int id, const char *data) {
    pthread_mutex_lock(&lock[node_id]);
    database[node_id][record_count[node_id]].id = id;
    strcpy(database[node_id][record_count[node_id]].data, data);
    record_count[node_id]++;
    pthread_mutex_unlock(&lock[node_id]);
    printf("Node %d: INSERTED\n", node_id);
}

void get_record(int node_id, int id) {
    char result[BUFFER_SIZE] = "NOT FOUND\n";
    pthread_mutex_lock(&lock[node_id]);
    for (int i = 0; i < record_count[node_id]; i++) {
        if (database[node_id][i].id == id) {
            snprintf(result, BUFFER_SIZE, "FOUND: %s\n", database[node_id][i].data);
            break;
        }
    }
    pthread_mutex_unlock(&lock[node_id]);
    printf("Node %d: %s", node_id, result);
}

void distribute_data(const char *command, int id, const char *data) {
    int node_id = id % NUM_NODES;

    if (strcmp(command, "INSERT") == 0) {
        insert_record(node_id, id, data);
    } else if (strcmp(command, "GET") == 0) {
        get_record(node_id, id);
    }
}

int main() {
    for (int i = 0; i < NUM_NODES; i++) {
        pthread_mutex_init(&lock[i], NULL);
    }

    distribute_data("INSERT", 1, "Data for record 1");
    distribute_data("INSERT", 2, "Data for record 2");
    distribute_data("INSERT", 3, "Data for record 3");
    distribute_data("GET", 1, "");

    for (int i = 0; i < NUM_NODES; i++) {
        pthread_mutex_destroy(&lock[i]);
    }

    return 0;
}
