// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)
#include <stdbool.h>

#ifndef STACK_WITH_LINKED_LIST_H_
#define STACK_WITH_LINKED_LIST_H_

// Tipo dos elementos na pilha.
typedef char Type;

// Tipo de dado stack (Pilha).
// Para garantir o ecapsulamento, 'struct stack_t' só é definido num arquivo ".c".
typedef struct stack_t* stack;

// Cria uma pilha vazia.
stack new_stack();

// Testa se a pilha está vazia.
bool empty(stack s);

// Retorna o número de elementos na pilha.
int size(stack s);

// Retorna o elemento que está no topo da pilha.
// Precondição: a pilha não pode estar vazia.
Type top(stack s);

// Insere k no topo da pilha.
void push(Type k, stack s);

// Remove o elemento que está no topo da pilha.
// Precondição: a pilha não pode estar vazia.
void pop(stack s);

// Faz a pilha s ter os mesmos elementos que a pilha p.
void copy(stack p, stack s);

// Troca o conteúdo da pilha s com o da pilha p.
void swap(stack p, stack s);

// Libera a memória alocada para a pilha.
void delete_stack(stack s);

// reserva espaco na memoria para a stack caso necessario
void reserve(int m,stack s);

#endif  // STACK_H
