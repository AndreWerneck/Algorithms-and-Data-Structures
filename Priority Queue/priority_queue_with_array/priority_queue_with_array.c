// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "priority_queue_with_array.h"

#include <stdlib.h>

// Os elementos da fila estão distribuídos do maior para o menor no vetor,
// ou seja, o maior elemento está necessariamente no índice 0 do vetor.
struct priority_queue_t{
  Type* array;  // Vetor que contém os elementos da fila.
  int capacity; // Número de elementos alocados no vetor array.
  int size;  // Número de elementos na fila.
};

void reserve(int m, priority_queue q) {
  if (m > q->capacity) {
    q->capacity = m;
    Type* aux = malloc(sizeof(struct priority_queue_t) * q->capacity);
    for (int i = 0; i < q->size; i++) {
      aux[i] = q->array[i];
    }
    free(q->array);
    q->array = aux;
  }
}

priority_queue new_priority_queue()
{
    priority_queue q = malloc(sizeof(struct priority_queue_t));
    q->size=0;
    q->capacity = 17;
    q->array=malloc(q->capacity * sizeof(struct priority_queue_t));
    return q;
}

bool empty(priority_queue q)
{
    if (q->size==0){
        return true;
    }else {
        return false;
        }
}

int size(priority_queue q)
{
    return q->size;
}

Type top(priority_queue q) // retorna o menor elemento, ou seja, o ultimo da fila.
{
    return q->array[(q->size - 1)%q->capacity];
}

void push(Type k, priority_queue q)
{
    int i=(q->size-1)%q->capacity;
    if(q->size==q->capacity){
        reserve(2*q->capacity,q);
    }
    while(k>=q->array[i]&& i>=0){
       q->array[i+1]=q->array[i];
       i--;
       }
    q->array[i+1]=k;
    q->size++;
}

void pop(priority_queue q) // remove o menor elemento
{
    q->array[(q->size -1)%q->capacity]=q->array[(q->size-2)%q->capacity];
    q->size--;
}

void copy(priority_queue q, priority_queue p)
{
    int i;
    reserve(q->capacity,p);
    p->size=q->size;

    for(i=0;i<(q->size)%q->capacity;i++){
        p->array[i]=q->array[i];
    }
}

void swap(priority_queue q, priority_queue p)
{
    priority_queue a = malloc(sizeof(struct priority_queue_t));
    copy(q,a);
    copy(p,q);
    copy(a,p);
}

void delete_priority_queue(priority_queue q)
{
    free(q->array);
    free(q);
}






