#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

#include <stddef.h>

typedef int Type;

//para garantir o encapsulamento tudo sera definido no arquivo .c
typedef struct Node_t* Node;
typedef struct List_t* list;

void Imprimir(Node x);

//cria uma lista vazia
Node new_list(int k);

//Retorna o n�mero de elementos na lista x
int Size(Node x);

//Retorna um n� cuja a chave � k ou retorna
//NULL caso n�o existe este n�
Node Pertence(Node x, int k);

//k no final da lista X e retorna um ponteiro para o novo n� criado
Node Inserir(Node x, int k);

//Desconecta da lista x o n� cuja chave � k e retorna o ponteiro para
//o novo n� desconectado ou retorna NULL caso k n�o perten�a a x
Node Remover(Node x, int k);

//Cria uma lista encadeada com todos os n elementos de v e retorna um
//ponteiro para o primeiro elemento dessa lista
Node Criar(int n, int v[]);

//Desaloca a mem�ria reservada para todos os elementos da lista x
Node Deletar(Node x);

//ordena os elementos da lista x do menor para o maior e
//retorna um ponteiro para o menor elemento ou NULL caso x esteja vazia
Node Ordenar(Node x);

//Inverte a ordem dos elementos de x
Node Inverter(Node x);

#endif // LISTAENCADEADA_H_
