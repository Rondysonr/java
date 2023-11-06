#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "WorkHash.h"

#define MAX_PIXELS 3000

// Protótipo da função customHash
int customHash(char *key) {
    int productSum = 0;
    if (key[0] != '\0') {
        productSum += key[0] * 7;
    }
    if (key[2] != '\0') {
        productSum += key[2] * 5;
    }
    if (key[4] != '\0') {
        productSum += key[4] * 13;
    }
    return productSum % MAX_PIXELS;
}

int efficientHash(char *key) {
    unsigned int hash = 0;
    unsigned int prime = 31;  // Um número primo adequado

    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * prime) + key[i];
    }

    return hash % MAX_PIXELS;
}

bool compare_dados(void* data_1, void* data_2) {
    return strcmp((char*)data_1, (char*)data_2) == 0;
}

void print(void* data) {
    char* string_data = (char*)data;
    if (string_data) {
        printf("%s ", string_data);
    }
}

int calculateGreenTone(int numElements) {
    int greenTone = (numElements * 255) / MAX_PIXELS;
    return greenTone;
}

void createPPMImage(const char* filename, int* greenTones) {
    FILE* imageFile = fopen(filename, "w");

    if (!imageFile) {
        perror("Erro ao criar o arquivo PPM");
        return;
    }

    fprintf(imageFile, "P3\n"); // Cabeçalho PPM P3
    fprintf(imageFile, "%d %d\n", MAX_PIXELS, MAX_PIXELS); // Tamanho da imagem fixo em 3000x3000
    fprintf(imageFile, "255\n"); // Valor máximo de cor

    for (int i = 0; i < MAX_PIXELS; i++) {
        for (int j = 0; j < MAX_PIXELS; j++) {
            int greenTone = greenTones[i];
            fprintf(imageFile, "0 %d 0 ", greenTone);
        }
        fprintf(imageFile, "\n");
    }

    fclose(imageFile);
    printf("Imagem PPM criada com sucesso: %s\n", filename);
}

int main() {
    FILE* arquivo;
    arquivo = fopen("ListaDePalavrasPT.txt", "r");

    if (arquivo == NULL) {
        fprintf(stderr, "Arquivo não abriu.\n");
        return EXIT_FAILURE;
    }

    HashStruct tabela;
    initHash(&tabela);

    int escolha;
    printf("Escolha uma opcao de distribuicao:\n");
    printf("1. Distribuicao original\n");
    printf("2. Nova distribuicao (letras multiplicadas)\n");
    printf("3. Distribuicao eficiente\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    int* greenTones = (int*)malloc(sizeof(int) * MAX_PIXELS);
    if (greenTones == NULL) {
        fprintf(stderr, "Falha na alocação de memória para tons de verde.\n");
        fclose(arquivo);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < MAX_PIXELS; i++) {
        greenTones[i] = 0;
    }

    char* string = (char*)malloc(sizeof(char) * 100);

    if (string == NULL) {
        fprintf(stderr, "Falha na alocação de memória.\n");
        fclose(arquivo);
        free(greenTones);
        return EXIT_FAILURE;
    }

    while (fscanf(arquivo, "%s", string) != EOF) {
        char* word = (char*)malloc(strlen(string) + 1);
        strcpy(word, string);

        int hashValue;
        if (escolha == 1) {
            hashValue = hash(word);
        } else if (escolha == 2) {
            hashValue = customHash(word);
        } else if (escolha == 3) {
            hashValue = efficientHash(word);
        } else {
            fprintf(stderr, "Opcao invalida.\n");
            break;
        }

        put(&tabela, word, word, compare_dados);
        greenTones[hashValue]++;
    }

    showHashStruct(&tabela, print);

    createPPMImage("imagem_hash.ppm", greenTones);

    fclose(arquivo);
    free(string);
    free(greenTones);

    return EXIT_SUCCESS;
}








