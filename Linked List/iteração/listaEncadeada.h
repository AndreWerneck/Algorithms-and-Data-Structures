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

//Retorna o n�mero de elementos na lista x
int Size(Node x);

//Retorna um apontador para n� cuja a chave � k ou retorna
//NULL caso n�o existe este n�
Node Pertence(Node x, int k);

//k no final da lista X e retorna um ponteiro para o novo n� criado
Node Inserir(Node x, int k);

//Desconecta da lista x o n� cuja chave � k e retorna o ponteiro para
//o novo n� desconectado ou retorna NULL caso k n�o perten�a a x
Node Remover(Node x, int k);

//Cria uma lista encadeada com todos os n elementos de v e retorna um
//ponteiro par ao primeiro elemento dessa lista
Node Criar(int n, int v[]);

//Desaloca a mem�ria reservada para todos os elementos da lista x
Node Deletar(Node x);

#endif // LISTAENCADEADA_H_
