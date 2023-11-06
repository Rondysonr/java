#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WorkHash.h"


bool compare_dados(void* data_1, void* data_2) {
    return strcmp((char*)data_1, (char*)data_2) == 0;
}

void print(void* data) {
    char* string_data = (char*)data;
    if (string_data) {
        printf("%s ", string_data);
    }
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

    while (fscanf(arquivo, "%s", string) != EOF) {
       
        put(&tabela, string, string, compare_dados);
        string = (char*)malloc(sizeof(char) * 100); // Aloca memória para a próxima string

    }

    showHashStruct(&tabela, print);
    fclose(arquivo);
    
    free(string);

    // Exibe o número de colisões
    //printf("Número de colisões: %d\n", num_collisions);

    return EXIT_SUCCESS;
}
