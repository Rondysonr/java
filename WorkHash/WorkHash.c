#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WorkHash.h"
#include "log.h"

void initHash(HashStruct *hashStruct) {
    //log_trace("Entrando em initHash");
    for (int i=0;i<MAX;i++) {
        //chamando init de DoublyLinkedList para inicializar cada lista do vetor
        //log_debug("Inicializando Lista do Hash %d", i);
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
   // log_trace("Saindo de initHash");
}

bool isHashEmpty(HashStruct *hashStruct) {
    return hashStruct->size==0;
}

int hash(char *key) {
   // log_trace("Entrando em hash");
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os códigos ascii de cada letra com um peso
        sum+=key[i]*(i+1);
    }
  //  log_debug("key: %s", key);
   // log_debug("sum: %d", sum);
    int hashvalue = sum%MAX;
   // log_debug("Hash: %d", hashvalue);
   // log_trace("Saindo de hash");
    return hashvalue; //retorna o resto da divisão
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal)  {
   // log_trace("Entrando em put");
   // log_info("Adicionando novo elemento no Hash");
    if (!containsKey(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }

    //log_trace("Saindo de put");
    return 0;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal) {
    //log_trace("Entrando em containsKey");
    //calcula a posição
    int hashValue = hash(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
   // log_debug("Posição na lista %d: %d", hashValue, pos);
    //log_trace("Saindo de containsKey");
    return (pos!=-1)?true:false;
}

void* get(HashStruct *hashStruct, char *key, compare equal) {
   // log_trace("Entrando em get");
    // descobre em qual fila/lista está o dado
    int hashValue = hash(key);
    //first é nó sentinela, começamos do segundo nó
    Node *aux = hashStruct->hashes[hashValue].first->next;
    // procuramos o dado na lista
    while(aux!=hashStruct->hashes[hashValue].first && !equal(key, aux->data))
        aux=aux->next;

   // log_debug("Nó foi localizado?: %d", aux!=hashStruct->hashes[hashValue].first);
    //log_trace("Saindo de get");

    return aux->data;
}

void* removeKey(HashStruct *hashStruct, char *key, compare equal) {
  //  log_trace("Entrando em removeKey");
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    void* result = removePos(&hashStruct->hashes[hashValue], pos);
    if (result!=NULL) hashStruct->size--;
   // log_trace("Saindo de removeKey");
    return result;
}

void showHashStruct(HashStruct *hashStruct, printNode print) {
 //   log_trace("Entrando em showHashStruct");
    printf("There are %d elements in the Hash\n\n",hashStruct->size);
    for (int i=0; i < MAX; i++) {
        printf("Hash %d has %d elements: ",i,hashStruct->hashes[i].size);
        show(&hashStruct->hashes[i],print);
        printf("\n");
    }
   // log_trace("Saindo showHashStruct");
}
