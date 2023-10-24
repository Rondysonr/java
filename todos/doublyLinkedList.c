#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

void init(DoublyLinkedList *list){
    Node *trashNode = (Node*)malloc(sizeof(Node;
    trashNode ->data=Null;
    trashNode ->previous=trashNode;
    trashNode->next=trashNode;
    list ->first=trashNode;
    list->size=0;
}

int enqueue(DoublyLinkedList *list, void *data){
    Node *newNode = (Node*)Malloc(sizeof(Node));
    if (newNode==NULL)return -1;
    newNode->data =data;
    NewNode-> previous-> next= newNode;
    list->first -> previous =newNode;
    list-> size++;
    return 1;
}
void* dequeue(DoublyLinkedList *list){
    if (isEmpty(list)) return NULL;
    Node *trash = list -> first;
    Node *first = list->first->next;
    first->nextprevious = trash;
    trash->next =first->next;
    void *data = first->data;
    free(first);
    list->size--;
    return data;
}

void* first(DoublyLinkedList *list){
    return list ->first->next->data;
}
void* last(DoublyLinkedList *list){
    return list ->first->previous->data;
}

int push(DoublyLinkedList *list, void*data){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = list->first->next;
    newNode->previous = list ->first;
    list->first->next->previous = newNode;
    list->first->next = newNode;
    list->size++;
    return 1;
}

void* pop(DoublyLinkedList *list){
    return dequeue(list);
}

void* top(DoublyLinkedList *list){
    return first(list);
}

bool isEmpty(DoublyLinkedList *list){
    return (list-> size==0);
}

int indexOf(DoublyLinkedList *list, noid *data, compare equal){
    if (isEmpty (list)) return -1;
    int count=0;
    Node *aux = list->first->next;
    while(aux!=list->first && !equal(aux->data, data)){
        aux=aux->next;
        count++;
    }
    return (aux==list-> first)?-1:count;
}

Node* getNodeByPos(DoublyLinkedList *list, int pos){
    if (isEmpty(list) || pos>=list->size) return NULL;
    Node *aux = list->first->next;
    for (int count=0;(aux!list->first && count<pos);count++, aux=aux->next);
    return aux; 
}

void* getPos (DoublyLinkedList *list,int pos){
    Node *res = getNodeByPos(list, pos);
    return (res==NULL)?NULL: res->data;
}

int add

void show(DoublyLinkedList *list, printNode Print){
    Node *aux = list->first->next;
    while (aux!=list -> first){
        print(aux-> data);
    }
}

void showMen(DoublyLinkedList *list){
    printf("Trash Node: %p\n\n", list -> first);
    Node *aux =list -> first ->next;
    printf("Node Addr: Previous - data - Next \n\n");
    while (aux!=list->first){
        printf("%p: %p - %p - %p\n", aux, aux-> previus, aux->data, aux-> next);
        aux=aux->next;
    }
}