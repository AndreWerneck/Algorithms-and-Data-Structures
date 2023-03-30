// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#ifndef LIST_ENC_ITERACAO_H_
#define LIST_ENC_ITERACAO_H_

typedef int Type;

struct Node;
// Tipo de dado List (fila).
// Para garantir o ecapsulamento, 'struct List_t' só é definido no arquivo ".c".
//typedef Node* No;
// Define como os elementos da fila serão organizados na memória.
typedef struct Node* No;

//cria uma lista vazia
No new_list();

//retorne o número de elementos na lista x
int Size(No x);

// retorna um no cuja chave é k
//retorna NULL caso nao exista esse nó
No Pertence(No x, int k);

//insere k no final da lista x
//retorna o novo no criado
No Inserir(No x, int k);

//exclui o no com chave k da lista x
//retorna null caso k nao pertenca a x
//retorna o novo no desconectado
No Remover(No x, int k);

No Criar(int n, int v[]);

No Deletar(No x);

No Ordenar(No x);

No Inverter(No x);

No Concatenar(No x, No y);

No Mesclar(No x, No y);

//imprimi a lista
void Imprimir(No x);

#endif  // List_H_
