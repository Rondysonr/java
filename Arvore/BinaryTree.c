#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int add(TreeNode **root, void *element, TreeComparator f) {
    if ((*root) == NULL) {
        TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
        if (newnode == NULL)
            return 0;
        newnode->element = element;
        newnode->left = newnode->right = NULL;
        *root = newnode;
        return 1;
    }
    int compvalue = f(element, (*root)->element);
    if (compvalue > 0) {
        return add(&(*root)->right, element, f);
    } else if (compvalue < 0) {
        return add(&(*root)->left, element, f);
    } else {
        return -1;
    }
}

int find(TreeNode *root, void *key, TreeComparator f, void **element) {
    int compvalue;
    if (root == NULL)
        return 0;
    compvalue = f(key, root->element);
    if (compvalue == 0) {
        *element = root->element;
        return 1;
    }
    if (compvalue > 0)
        return find(root->right, key, f, element);
    return find(root->left, key, f, element);
}

void in_order(TreeNode *root, printNode print) {
    if (root != NULL) {
        in_order(root->left, print);
        print(root->element);
        in_order(root->right, print);
    }
}

// Implementações das demais funções...

void destroy(TreeNode **root) {
    if (*root == NULL)
        return;
    destroy(&(*root)->left);
    destroy(&(*root)->right);
    free(*root);
    *root = NULL;
}
