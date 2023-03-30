// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "priority_queue_with_linked_list.h"

#include <stdlib.h>

struct Node {
  Type key;
  struct Node* prev;
  struct Node* next;
};

struct priority_queue_t{
  struct Node* end;
  int size;
};

priority_queue new_priority_queue() {

    priority_queue q = malloc(sizeof(struct priority_queue_t));
    q->size=0;
    q->end=malloc(sizeof(struct Node));
    q->end->prev=q->end;
    q->end->next=q->end;
    return q;
}

bool empty(priority_queue q) {
    if((q->end->prev==q->end)&&(q->end->next==q->end)){
        return true;
    }else {
        return false;
        }
}

int size(priority_queue q) {
    return q->size;
}


Type top(priority_queue q) { // retorna o menor elemento da fila- ultima posicao
    return q->end->next->key;
}

void push(Type k, priority_queue q)
{
    struct Node* elemento = q->end;
    while (elemento->next!=q->end && elemento->next->key<k){
    elemento=elemento->next;
    }
    struct Node* novo = malloc(sizeof(struct Node));
    novo->key=k;
    novo->prev=elemento;
    novo->next=elemento->next;
    novo->prev->next=novo;
    novo->next->prev=novo;
    q->size++;
}

void pop(priority_queue q) {

    struct Node* first = q->end->next;
    first->prev->next=first->next;
    first->next->prev=first->prev;
    free(first);
    q->size--;
}

void copy(priority_queue q, priority_queue p) {

    while(!empty(p)){
        pop(p);
    }
    struct Node*i;
    for(i=q->end->next;i!=q->end;i=i->next){
        push(i->key,p);
    }
}


void swap(priority_queue q, priority_queue p) {
    struct priority_queue_t i = *q;
    *q=*p;
    *p=i;
}

void delete_priority_queue(priority_queue q) {
    free(q->end);
    free(q);
}
