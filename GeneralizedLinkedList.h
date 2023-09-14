#ifndef DataStructure_GeneralizedLinkedList_h
#define DataStructure_GeneralizedLinkedList_h
#include <stdbool.h>

typedef struct Node {
    int type; //0 atomo e 1 lista
    union {
        int atom;
        struct Node *list;
    }atomList;
    struct Node *next;
}Node;

int addAtom(Node **list, int atom);
int addList(Node **list, Node **subList);
Node* head(Node *list);
Node* tail(Node *list);
void show(Node *list);
boolean search(Node *list, int atom);
int depth(Node *list);

#endif