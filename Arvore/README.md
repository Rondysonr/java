## Sobre o Codigo: 
Este codigo não tem menu, ele le um arquivo chamado planta 
cria a arvore e imprime no terminal, caractere e frequencia e em seguida caractere e código de huffman
gera um arquivo chamado compressao.txt com os codigos de huffman de todas as variaveis,
em seguida le compressao.txt e retorna a comparação de huffman com a tabela Asci em compressaoAsci.txt,
 
## Instruções: 
    1 - Verifique se o seu arquivo possui o nome "planta".
    2 - A cada nova atualização no codigo execute a instrução Execução
    para torna-lo executavel.

## Execução:
  
    1 - make
    2 - ./meu_programa


## DAS FUNÇÕES:


# newNode:
    Descrição: Cria um novo nó para a árvore de Huffman com o caractere e a frequência fornecidos.
    Parâmetros:
    ```c
        char data: Caractere do nó.
        unsigned freq: Frequência do caractere.
    ```
# createMinHeap:
    Descrição: Cria e retorna um novo heap mínimo (min heap) para armazenar os nós da árvore de Huffman.
    Parâmetros:
    ```c
        unsigned capacity: Capacidade máxima do heap.
    ```
# swapNode:
    Descrição: Troca dois nós no heap.
    Parâmetros:
    ```c
        struct Node** a: Primeiro nó.
        struct Node** b: Segundo nó.
    ```
# minHeapify:
    Descrição: Mantém a propriedade de heap mínimo após a remoção de um nó.
    Parâmetros:
    ```c
        struct MinHeap* minHeap: Heap mínimo.
        int idx: Índice do nó a ser verificado e ajustado.
    ```
# isSizeOne:
    Descrição: Verifica se o tamanho do heap mínimo é um.
    Parâmetros:
    ```c
        struct MinHeap* minHeap: Heap mínimo.
    ```
# extractMin:
    Descrição: Extrai o nó com a menor frequência do heap mínimo.
    Parâmetros:
    ```c
        struct MinHeap* minHeap: Heap mínimo.
    ```
# insertMinHeap: 
    ```c
    Descrição: Insere um novo nó no heap mínimo.
    Parâmetros:
        struct MinHeap* minHeap: Heap mínimo.
        struct Node* node: Nó a ser inserido.
    ```
# buildHuffmanTree:
    Descrição: Constrói a árvore de Huffman usando o algoritmo de construção de heap mínimo.
    Parâmetros:
        ```c
        char data[]: Array de caracteres.
        int freq[]: Array de frequências correspondentes.
        int size: Tamanho dos arrays.
        ```

# printCodes:
    Descrição: Imprime os códigos Huffman para cada caractere na árvore.
    Parâmetros:
    ```c
        struct Node* root: Raiz da árvore.
        int arr[]: Array temporário para armazenar os códigos.
        int top: Índice do topo do array.
        FILE* compressFile: Arquivo para gravar os códigos.
     ```
# decodeHuffman:
    Descrição: Decodifica os bits da compressão Huffman para os caracteres originais.
    Parâmetros:
    ```c
        struct Node* root: Raiz da árvore de Huffman.
        FILE* compressFile: Arquivo contendo os bits comprimidos.
        FILE* compressAsciFile: Arquivo para gravar os caracteres decodificados.
    ```
# printFrequencies:
    Descrição: Imprime os caracteres e suas frequências.
    Parâmetros:
    ```c
       - char data[]: Array de caracteres.
       - int freq[]: Array de frequências correspondentes.
         int size: Tamanho dos arrays.
    ```
# printHuffmanCodes:
    Descrição: Imprime os códigos Huffman para cada caractere na árvore.
    Parâmetros:
    ```c
        -struct Node* root: Raiz da árvore.
        -char code[]: Array temporário para armazenar os códigos.
        -int top: Índice do topo do array.
    ```
# printHuffmanTree:
Descrição: Imprime os caracteres e seus códigos Huffman.
Parâmetros:
    ```c
    - struct Node* root: Raiz da árvore.
    ```
 
