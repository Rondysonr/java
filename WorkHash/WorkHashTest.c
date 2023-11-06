#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "WorkHash.h"

// Protótipo da função customHash
int customHash(char *key);

bool compare_dados(void* data_1, void* data_2) {
    return strcmp((char*)data_1, (char*)data_2) == 0;
}

void print(void* data) {
    char* string_data = (char*)data;
    if (string_data) {
        printf("%s ", string_data);
    }
}
// Função customHash
int customHash(char *key) {
    int productSum = 0;

    // Multiplica a primeira letra por 7
    if (key[0] != '\0') {
        productSum += key[0] * 7;
    }

    // Multiplica a terceira letra por 5
    if (key[2] != '\0') {
        productSum += key[2] * 5;
    }

    // Multiplica a quinta letra por 13
    if (key[4] != '\0') {
        productSum += key[4] * 13;
    }

    return productSum % MAX;
}

int main() {
    FILE* arquivo;
    char* string;
    arquivo = fopen("ListaDePalavrasPT.txt", "r");
    HashStruct tabela;
    initHash(&tabela);

    if (arquivo == NULL) {
        fprintf(stderr, "Arquivo não abriu.\n");
        return EXIT_FAILURE;
    }

    string = (char*)malloc(sizeof(char) * 100);

    if (string == NULL) {
        fprintf(stderr, "Falha na alocação de memória.\n");
        fclose(arquivo);
        return EXIT_FAILURE;
    }

    int escolha;
    printf("Escolha uma opcao de distribuicao:\n");
    printf("1. Distribuicao original\n");
    printf("2. Nova distribuicao (letras multiplicadas)\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    while (fscanf(arquivo, "%s", string) != EOF) {
        int hashValue;
        if (escolha == 1) {
            hashValue = hash(string);
        } else if (escolha == 2) {
            hashValue = customHash(string);
        } else {
            fprintf(stderr, "Opcao invalida.\n");
            break;
        }

        put(&tabela, string, string, compare_dados);
        string = (char*)malloc(sizeof(char) * 100); // Aloca memória para a próxima string
    }

    showHashStruct(&tabela, print);
    fclose(arquivo);
    
    free(string);

    return EXIT_SUCCESS;
}




