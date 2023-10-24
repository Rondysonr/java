#include "GeneralizedLinkedList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int main (){

Node *list;
int resp, n;
do{
    printf("Qual função? \n");
    printf("-------\n 1 - AddAtom \n 2 - Head \n 3 - Tail \n 4 - Show \n 5 - Search \n 6 - Depth \n 7 - Exit\n-------");
    scanf("%d", &resp);
    switch(resp){
        case 1:
            printf("digite um numero \n");
            scanf("%d", &n);
            addAtom(&list,n);
        break;
        case 2:
            show(list);
        break;
    }

}while (resp ==7 );



return 0;
}