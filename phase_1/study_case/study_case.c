//
// Created by caiocv18 on 04/06/2024.
//

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float historico_compras[10];
} Cliente;

void adicionar_cliente(Cliente clientes[], int *num_clientes) {
    Cliente novo_cliente;
    printf("Digite o nome do cliente: ");
    scanf("%s", novo_cliente.nome);
    printf("Digite a idade do cliente: ");
    scanf("%d", &novo_cliente.idade);
    printf("Digite o histórico de compras (10 valores): ");
    for (int i = 0; i < 10; i++) {
        scanf("%f", &novo_cliente.historico_compras[i]);
    }
    clientes[*num_clientes] = novo_cliente;
    (*num_clientes)++;
}

void visualizar_clientes(Cliente clientes[], int num_clientes) {
    for (int i = 0; i < num_clientes; i++) {
        printf("Cliente %d\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Histórico de compras: ");
        for (int j = 0; j < 10; j++) {
            printf("%.2f ", clientes[i].historico_compras[j]);
        }
        printf("\n");
    }
}

void buscar_cliente(Cliente clientes[], int num_clientes, char nome[]) {
    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            printf("Cliente encontrado!\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Idade: %d\n", clientes[i].idade);
            printf("Histórico de compras: ");
            for (int j = 0; j < 10; j++) {
                printf("%.2f ", clientes[i].historico_compras[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Cliente não encontrado.\n");
}

int main_study_case() {
    Cliente clientes[100];
    int num_clientes = 0;
    int opcao;
    char nome[50];

    do {
        printf("1. Adicionar cliente\n");
        printf("2. Visualizar clientes\n");
        printf("3. Buscar cliente\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_cliente(clientes, &num_clientes);
                break;
            case 2:
                visualizar_clientes(clientes, num_clientes);
                break;
            case 3:
                printf("Digite o nome do cliente: ");
                scanf("%s", nome);
                buscar_cliente(clientes, num_clientes, nome);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}