#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WorkHash.h"

// Função de dispersão simples - calcular um índice com base na chave
unsigned int hash(char* key, int size) {
    unsigned int hash_value = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash_value = key[i] + 31 * hash_value;
    }
    return hash_value % size;
}

// Inicializar uma nova tabela de dispersão
struct HashTable* createHashTable(int size) {
    struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable));
    table->size = size;
    table->array = (struct Node**)malloc(sizeof(struct Node*) * size);
    for (int i = 0; i < size; i++) {
        table->array[i] = NULL;
    }
    return table;
}

// Inserir um par chave-valor na tabela
void insert(struct HashTable* table, char* key, int value) {
    int index = hash(key, table->size);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = table->array[index];
    table->array[index] = newNode;
}

// Obter o valor associado a uma chave
int get(struct HashTable* table, char* key) {
    int index = hash(key, table->size);
    struct Node* current = table->array[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Chave não encontrada
}

