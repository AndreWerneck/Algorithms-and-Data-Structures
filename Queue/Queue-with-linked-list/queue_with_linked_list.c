// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "queue_with_linked_list.h"

#include <stdlib.h>

// Define como os elementos da fila serão organizados na memória.
struct Node {
  Type key;
  struct Node* prev;
  struct Node* next;
};

struct queue_t{
  struct Node* end;  // Ponteiro para o sentinela.
  int size;  // Número de elementos na fila.
};


queue new_queue()
{
    queue q = malloc(sizeof(struct queue_t));
    q->end= malloc(sizeof(struct Node));
    q->size=0;
    q->end->next=q->end;
    q->end->prev=q->end;
    return q;
}

bool empty(queue q)
{
    if ((q->end->prev==q->end) && (q->end->next==q->end)){

        return true;
    }else{
        return false;
        }
}

int size(queue q)
{
    return q->size;
}

Type front(queue q)
{
    return q->end->next->key;
}

Type back(queue q)
{
    return q->end->prev->key;
}

void push(Type k, queue q)
{
    struct Node* ultimo= malloc(sizeof(struct Node));
    ultimo= q->end->prev;
    struct Node* novo=malloc(sizeof(struct Node));
    novo->key=k;
    novo->next=ultimo->next;
    novo->prev=ultimo;
    ultimo->next->prev=novo;
    ultimo->next=novo;
    q->size++;
}

void pop(queue q)
{
    struct Node* primeiro=malloc(sizeof(struct Node));
    primeiro=q->end->next;
    primeiro->prev->next=primeiro->next;
    primeiro->next->prev=primeiro->prev;
    free(primeiro);
    q->size--;
}

void copy(queue q, queue p)
{
    if(p->size!=q->size){
        p->size=q->size;
    }

    while(!empty(p)){
        pop(p);
    }

    struct Node* i=malloc(sizeof(struct Node));
    for(i=q->end->next;i!=q->end;i=i->next){
        push(i->key,p);
    }
    free(i);
}

void swap(queue q, queue p)
{
    queue a=malloc(sizeof(struct queue_t));

    copy(q,a);
    copy(p,q);
    copy(a,p);
    free(a);
}

void delete_queue(queue q)
{
    while(!empty(q)){
        pop(q);
    }
    free(q->end);
    free(q);
}




