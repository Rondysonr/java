#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WorkHash.h"


int main(){

FILE *arquivo;

arquivo = fopen("ListaDePalavrasPT.txt","r");
    if(arquivo == NULL){
        printf("Arquivo não abriu. \n");
        return 1
    }


fclose(arquivo);

return EXIT_SUCCESS;
}