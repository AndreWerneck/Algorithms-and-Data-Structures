#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

#include <stddef.h>

typedef int Type;
struct Node_t
{
    struct Node_t* next;
    Type key;
};
typedef struct Node_t* Node;

void Imprimir(Node x);

//Retorna o número de elementos na lista x
int Size(Node x);

//Retorna um apontador para nó cuja a chave é k ou retorna
//NULL caso não existe este nó
Node Pertence(Node x, int k);

//k no final da lista X e retorna um ponteiro para o novo nó criado
Node Inserir(Node x, int k);

//Desconecta da lista x o nó cuja chave é k e retorna o ponteiro para
//o novo nó desconectado ou retorna NULL caso k não pertença a x
Node Remover(Node x, int k);

//Cria uma lista encadeada com todos os n elementos de v e retorna um
//ponteiro par ao primeiro elemento dessa lista
Node Criar(int n, int v[]);

//Desaloca a memória reservada para todos os elementos da lista x
Node Deletar(Node x);

#endif // LISTAENCADEADA_H_
