#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// Definir a estrutura para um nó de lista ligada
struct Node {
    char* key;
    int value;
    struct Node* next;
};

// Definir a estrutura da tabela de dispersão
struct HashTable {
    int size;
    struct Node** array;
};

// Funções da tabela de dispersão
struct HashTable* createHashTable(int size);
void insert(struct HashTable* table, char* key, int value);
int get(struct HashTable* table, char* key);

#endif  // HASH_TABLE_H