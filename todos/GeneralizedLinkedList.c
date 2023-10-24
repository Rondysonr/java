#include "GeneralizedLinkedList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int addAtom(Node **list, int atom){
    Node *no= (Node*)malloc(sizeof(Node));
    no-> atomList.atom = atom; 
    no -> type = 0;
    if  (*list == NULL)
        *list = no;
    else{ 
        Node *aux= *list;
        while(aux-> next !=NULL)
            aux= aux->next;
        aux -> next = no;
    } 
    return 1;
    
}
int addList(Node **list, Node **subList);
Node* head(Node *list);
Node* tail(Node *list);

void show(Node *list){
    printf("(");
    Node *aux = list;
    while(aux != NULL){
        printf ("%d", aux-> atomList.atom);
        aux=aux -> next;
    } 
    printf(")");
}
bool search(Node *list, int atom);
int depth(Node *list);