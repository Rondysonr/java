#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "WorkHash.h"

#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 128
#define MAX_PIXELS (IMAGE_WIDTH * IMAGE_HEIGHT)

int efficientHash(char *key) {
    int hashValue = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = (hashValue * 31) + key[i];
    }

    if (hashValue < 0) {
        hashValue = -hashValue;
    }

    return hashValue % MAX_PIXELS;
}


int customHash(char *key) {
    int primeNumbers[] = {2, 3, 5, 7, 11};
    int productSum = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        char c = tolower(key[i]);
        int multiplier = 1;

        if (c == 'a') {
            multiplier = primeNumbers[0];
        } else if (c == 'e') {
            multiplier = primeNumbers[1];
        } else if (c == 'i') {
            multiplier = primeNumbers[2];
        } else if (c == 'o') {
            multiplier = primeNumbers[3];
        } else if (c == 'u') {
            multiplier = primeNumbers[4];
        }

        productSum += key[i] * multiplier;
    }

    return productSum % MAX_PIXELS;
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

int calculateGreenTone(int numElements, int maxElements) {
    int greenTone = (numElements * 255) / maxElements;
    return greenTone;
}

void createPPMImage(const char* filename, int** distributionMatrix, int maxElements) {
    FILE* imageFile = fopen(filename, "w");

    if (!imageFile) {
        perror("Erro ao criar o arquivo PPM");
        return;
    }

    fprintf(imageFile, "P3\n");
    fprintf(imageFile, "%d %d\n", IMAGE_WIDTH, IMAGE_HEIGHT);
    fprintf(imageFile, "255\n");

    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            int numElements = distributionMatrix[i][j];
            int greenTone = calculateGreenTone(numElements, maxElements);

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
    printf("\n\nEscolha uma opcao de distribuicao:\n");
    printf("1. Distribuicao original\n");
    printf("2. Distribuicao multiplicacao de vogais\n");
    printf("3. Distribuicao eficiente\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    int** distributionMatrix = (int**)malloc(sizeof(int*) * IMAGE_HEIGHT);
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        distributionMatrix[i] = (int*)malloc(sizeof(int) * IMAGE_WIDTH);
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            distributionMatrix[i][j] = 0;
        }
    }

    int maxElements = 0;

    char* string = (char*)malloc(sizeof(char) * 100);

    if (string == NULL) {
        fprintf(stderr, "Falha na alocação de memória.\n");
        fclose(arquivo);
        for (int i = 0; i < IMAGE_HEIGHT; i++) {
            free(distributionMatrix[i]);
        }
        free(distributionMatrix);
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
        distributionMatrix[hashValue / IMAGE_WIDTH][hashValue % IMAGE_WIDTH]++;

        if (distributionMatrix[hashValue / IMAGE_WIDTH][hashValue % IMAGE_WIDTH] > maxElements) {
            maxElements = distributionMatrix[hashValue / IMAGE_WIDTH][hashValue % IMAGE_WIDTH];
        }
    }

        printf("\n");

    createPPMImage("imagem_hash.ppm", distributionMatrix, maxElements);

    fclose(arquivo);
    free(string);
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        free(distributionMatrix[i]);
    }
    free(distributionMatrix);

    return EXIT_SUCCESS;
}






