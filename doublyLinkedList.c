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
    NewNode->
}

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