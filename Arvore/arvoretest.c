#include "arvore.h"

int main() {
    FILE *inputFile = fopen("planta.txt", "r");
    FILE *compressFile = fopen("compressao.txt", "w");

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

    struct Node *root = buildHuffmanTree(data, count, size);

    printFrequencies(data, count, size);
    printHuffmanTree(root);

    int arr[100], top = 0;
    printCodes(root, arr, top, compressFile);

    fclose(compressFile);

    compressFile = fopen("compressao.txt", "r");
    if (!compressFile) {
        perror("Erro ao abrir o arquivo compressao.txt para leitura");
        return 1;
    }

    FILE *compressAsciFile = fopen("compressaoAsci.txt", "w");

    if (!compressAsciFile) {
        perror("Erro ao abrir o arquivo compressaoAsci.txt");
        return 1;
    }

    decodeHuffman(root, compressFile, compressAsciFile);

    fclose(compressFile);
    fclose(compressAsciFile);

    return 0;
}
