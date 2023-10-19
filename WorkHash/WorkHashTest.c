#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WorkHash.h"

int main() {
    struct HashTable* table = createHashTable(100);

    FILE* file = fopen("ListaDePalavrasPT.txt", "r");
    if (file == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        return 1;
    }

    char word[256];  // Supondo que a maior palavra tenha até 255 caracteres
    while (fgets(word, sizeof(word), file) != NULL) {
        // Remova a quebra de linha do final da palavra
        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }
        // Insira a palavra na tabela de dispersão com um valor padrão, por exemplo, 1.
        insert(table, word, 1);
    }

    fclose(file);

    // Agora, a tabela de dispersão contém as palavras lidas do arquivo.






    // Liberação de memória
/*    for (int i = 0; i < table->size; i++) {
        struct Node* current = table->array[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(table->array);
    free(table);*/

    return 0;
}

