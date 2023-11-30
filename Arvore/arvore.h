#include <stdlib.h>
#include <stdio.h>

#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq);

struct MinHeap* createMinHeap(unsigned capacity);

void swapNode(struct MinHeapNode** a, struct MinHeapNode** b);

void minHeapify(struct MinHeap* minHeap, int idx);

int isSizeOne(struct MinHeap* minHeap);

struct MinHeapNode* extractMin(struct MinHeap* minHeap);

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode);

void buildMinHeap(struct MinHeap* minHeap);

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size);

void printCodesUtil(struct MinHeapNode* root, int arr[], int top, FILE* compressFile);

void printCodes(struct MinHeapNode* root, int arr[], int top, FILE* compressFile);

void printFrequenciesWithCodesUtil(struct MinHeapNode* root, char data[], int freq[], int size, int arr[], int top);

void printFrequenciesWithCodes(struct MinHeapNode* root, char data[], int freq[], int size, int arr[], int top);


void decodeHuffmanUtil(struct MinHeapNode* root, FILE* compressFile, FILE* compressAsciFile);

void decodeHuffman(struct MinHeapNode* root, FILE* compressFile, FILE* compressAsciFile);

int calculateTotalBits(struct MinHeapNode* root, int freq[], int arr[], int top);

#endif // ARVORE_H_INCLUDED
