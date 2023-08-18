#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void init(LinkedList *list){
    list -> first=NULL;
    list -> size=0;
}

bool isEmpty(LinkedList *list){
    return(size==0);

}
int enqueue(LinkedList *list, void *data){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode -> data =data;
    newNode -> next = NULL;
    if (isEmpty(list)) 
        list -> first = newNode;
    else{
        Node *aux = list -> first;
        while (aux-> next != NULL)
            aux = aux -> next;
        aux-> next =newNode;
    }
    list -> size++;
    return 1;
}
void* first(LinkedList *list){
    return (isEmpty(list))?NULL:list ->first->data;
}
