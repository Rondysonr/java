#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    while (!isSizeOne(minHeap)) {
        struct MinHeapNode* left = extractMin(minHeap);
        struct MinHeapNode* right = extractMin(minHeap);

        struct MinHeapNode* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodesUtil(struct MinHeapNode* root, int arr[], int top, FILE* compressFile) {
    if (root->left == NULL && root->right == NULL) {
        fprintf(compressFile, "%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            fprintf(compressFile, "%d", arr[i]);
        }
        fprintf(compressFile, "\n");
    }

    if (root->left != NULL) {
        arr[top] = 0;
        printCodesUtil(root->left, arr, top + 1, compressFile);
    }

    if (root->right != NULL) {
        arr[top] = 1;
        printCodesUtil(root->right, arr, top + 1, compressFile);
    }
}

void printCodes(struct MinHeapNode* root, int arr[], int top, FILE* compressFile) {
    printCodesUtil(root, arr, top, compressFile);
}

void printFrequenciesWithCodesUtil(struct MinHeapNode* root, char data[], int freq[], int size, int arr[], int top) {
    if (root->left == NULL && root->right == NULL) {
        printf("'%c': %d, Código Huffman: ", root->data, freq[(int)root->data]);
        printCodesUtil(root, arr, top, stdout);
        printf("\n");
    }

    if (root->left != NULL) {
        arr[top] = 0;
        printFrequenciesWithCodesUtil(root->left, data, freq, size, arr, top + 1);
    }

    if (root->right != NULL) {
        arr[top] = 1;
        printFrequenciesWithCodesUtil(root->right, data, freq, size, arr, top + 1);
    }
}

void printFrequenciesWithCodes(struct MinHeapNode* root, char data[], int freq[], int size, int arr[], int top) {
    printf("Caracteres, suas frequências e códigos Huffman:\n");
    printFrequenciesWithCodesUtil(root, data, freq, size, arr, top);
}

void printFrequencies(char data[], int freq[], int size) {
    printf("Caracteres e suas frequências:\n");
    for (int i = 0; i < size; ++i) {
        printf("'%c': %d\n", data[i], freq[i]);
    }
}

void decodeHuffmanUtil(struct MinHeapNode* root, FILE* compressFile, FILE* compressAsciFile) {
    struct MinHeapNode* current = root;

    int bit;
    while ((bit = fgetc(compressFile)) != EOF) {
        if (bit == '0') {
            current = current->left;
        } else if (bit == '1') {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            // Chegamos a uma folha, ou seja, encontramos um caractere
            fprintf(compressAsciFile, "%c", current->data);
            current = root;  // Reiniciar a busca para o próximo caractere
        }
    }
}


void decodeHuffman(struct MinHeapNode* root, FILE* compressFile, FILE* compressAsciFile) {
    // Chamada para a função auxiliar
    decodeHuffmanUtil(root, compressFile, compressAsciFile);
}
