#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;

    return (*d1==*d2)?true:false;
}

int main() {
    LinkedList list;
    init(&list);

    int *aux = (int *)malloc(sizeof(int));
    *aux=1;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=2;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=3;
    enqueue(&list, aux);

    printf("%d\n",*((int*)first(&list)));
    printf("%d\n",indexOf(&list,aux,compara));
    printf("%d\n",*((int*)getPos(&list,2)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    //printf("%d\n",*((int*)dequeue(&stack)));

    return EXIT_SUCCESS;
}