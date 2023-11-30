#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    FILE* inputFile = fopen("planta.txt", "r");
    FILE* compressFile = fopen("compressao.txt", "w");

    if (!inputFile || !compressFile) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int freq[256] = {0};
    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        freq[(int)c]++;
    }

    int size = 0;
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            size++;
        }
    }

    char data[size];
    int count[size];
    int j = 0;
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            data[j] = (char)i;
            count[j] = freq[i];
            j++;
        }
    }

    struct MinHeapNode* root = buildHuffmanTree(data, count, size);

    int arr[100], top = 0;

    // Imprimir no terminal
    printFrequenciesWithCodes(root, data, count, size, arr, top);

    // Imprimir no arquivo "compressao.txt"
    printCodes(root, arr, top, compressFile);

    fclose(inputFile);
    fclose(compressFile);

    compressFile = fopen("compressao.txt", "r");
    FILE* compressAsciFile = fopen("compressaoAsci.txt", "w");

    if (!compressFile || !compressAsciFile) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    decodeHuffman(root, compressFile, compressAsciFile);

    fclose(compressFile);
    fclose(compressAsciFile);

    return 0;
}
