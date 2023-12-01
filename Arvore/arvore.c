#include "arvore.h"
#include <stdlib.h>
#include <string.h>

struct Node *newNode(char data, unsigned freq) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct MinHeap *createMinHeap(unsigned capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node **)malloc(minHeap->capacity * sizeof(struct Node *));
    return minHeap;
}

void swapNode(struct Node **a, struct Node **b) {
    struct Node *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx) {
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

int isSizeOne(struct MinHeap *minHeap) {
    return (minHeap->size == 1);
}

struct Node *extractMin(struct MinHeap *minHeap) {
    struct Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct Node *node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

struct Node *buildHuffmanTree(char data[], int freq[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, newNode(data[i], freq[i]));

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(struct Node *root, int arr[], int top, FILE *compressFile) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, compressFile);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, compressFile);
    }

    if (!(root->left) && !(root->right)) {
        for (int i = 0; i < top; ++i) {
            fprintf(compressFile, "%d", arr[i]);
        }
    }
}

void decodeHuffman(struct Node *root, FILE *compressFile, FILE *compressAsciFile) {
    rewind(compressFile);

    struct Node *current = root;

    int bit;
    while (fscanf(compressFile, "%1d", &bit) != EOF) {
        if (bit == 0 && current->left) {
            current = current->left;
        } else if (bit == 1 && current->right) {
            current = current->right;
        }

        if (!(current->left) && !(current->right)) {
            fprintf(compressAsciFile, "%c", current->data);
            current = root; // Reinicia a busca no topo da árvore
        }
    }
}

void printFrequencies(char data[], int freq[], int size) {
    printf("Caracteres e suas frequências:\n");
    for (int i = 0; i < size; ++i) {
        printf("'%c': %d\n", data[i], freq[i]);
    }
}

void printHuffmanCodes(struct Node *root, char code[], int top) {
    if (!(root->left) && !(root->right)) {
        printf("Caractere: '%c', Código Huffman: %s\n", root->data, code);
        return;
    }

    if (root->left) {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }
}

void printHuffmanTree(struct Node *root) {
    char code[100]; // Ajuste conforme necessário
    int top = 0;
    printf("Caracteres e seus códigos Huffman:\n");
    printHuffmanCodes(root, code, top);
}
