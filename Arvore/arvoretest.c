
#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

int main() {
    FILE* inputFile = fopen("planta.txt", "r");
    FILE* compressFile = fopen("compressao.txt", "w");

    if (!inputFile || !compressFile) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int freq[256] = {0};
    int c;
    while ((c = fgetc(inputFile)) != EOF) {
        if (c >= 0 && c < 256) {
            freq[c]++;
        }
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
    printFrequenciesWithCodes(root, data, count, size, arr, top);

    printFrequencies(data, count, size);

    int totalBits = calculateTotalBits(root, count, arr, 0);
    printf("Número total de bits: %d\n", totalBits);

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
