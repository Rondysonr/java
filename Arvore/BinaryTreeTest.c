#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int compareChar(void *a, void *b) {
    return (*((char *)a)) - (*((char *)b));
}

void printChar(void *element) {
    printf("%c", *((char *)element));
}

// Função para imprimir a frequência dos caracteres na árvore binária
void printFrequency(TreeNode *root) {
    if (root != NULL) {
        printFrequency(root->left);
        printf("Caracter: %c, Frequência: %d\n", *((char *)(root->element)), *((int *)(root->element)));
        printFrequency(root->right);
    }
}

int main() {
    FILE *file = fopen("plantas.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo\n");
        return 1;
    }

    TreeNode *root = NULL;

    char ch;
    while (fscanf(file, "%c", &ch) == 1) {
        void *element;
        if (find(root, &ch, compareChar, &element)) {
            (*((int *)element))++;
        } else {
            int *frequency = (int *)malloc(sizeof(int));
            *frequency = 1;
            add(&root, frequency, compareChar);
        }
    }

    printf("Frequência dos caracteres:\n");
    printFrequency(root);

    fclose(file);

    destroy(&root);

    return 0;
}
