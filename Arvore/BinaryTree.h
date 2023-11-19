#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct TreeNode {
    void *element;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef int (*TreeComparator)(void *, void *);
typedef void (*printNode)(void *);

int add(TreeNode **root, void *element, TreeComparator f);
int find(TreeNode *root, void *key, TreeComparator f, void **element);
void in_order(TreeNode *root, printNode print);

void destroy(TreeNode **root);

#endif
