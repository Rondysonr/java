#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WorkHash.h"

bool compare(void* data_1,void* data_2){

    if(strcmp (data_1,data_2)==0) return true;
    else return false;
}
void print(void* data){

  char* string_data = (char*)data;
  if (string_data) printf("%s ",string_data);
}


int main(){

FILE *arquivo;
char *string;

arquivo = fopen("ListaDePalavrasPT.txt","r");
HashStruct tabela;
initHash(&tabela);

if(arquivo == NULL){
    printf("Arquivo não abriu. \n"); return 1;
    {
        string = (char*)malloc(sizeof(char) * 100);
      while (fscanf(arquivo,"%s \n",string ) !=EOF ){
    
      put (&tabela,string,string,compare);
      string = (char*)malloc(sizeof(char) * 100);
    }
}

showHashStruct(&tabela,print);
fclose(arquivo);

return EXIT_SUCCESS;
}