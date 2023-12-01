#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>

struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct Node **array;
};

struct Node *newNode(char data, unsigned freq);
struct MinHeap *createMinHeap(unsigned capacity);
void swapNode(struct Node **a, struct Node **b);
void minHeapify(struct MinHeap *minHeap, int idx);
int isSizeOne(struct MinHeap *minHeap);
struct Node *extractMin(struct MinHeap *minHeap);
void insertMinHeap(struct MinHeap *minHeap, struct Node *node);
struct Node *buildHuffmanTree(char data[], int freq[], int size);
void printCodes(struct Node *root, int arr[], int top, FILE *compressFile);
void decodeHuffman(struct Node *root, FILE *compressFile, FILE *compressAsciFile);
void printFrequencies(char data[], int freq[], int size);
void printHuffmanCodes(struct Node *root, char code[], int top);
void printHuffmanTree(struct Node *root);

#endif
