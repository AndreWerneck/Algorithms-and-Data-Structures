#include <stdio.h>
#include<stdlib.h>
#include "stack_with_linked_list.h"


// Define como os elementos da pilha serão organizados na memória.
struct Node{
  Type key; // elemento da pilha
  struct Node* prev; // ponteiro que aponta para o elemento anterior
  struct Node* next; // ponteiro que aponta para o elemento seguinte
};

typedef struct stack_t{
  struct Node* end;  // Ponteiro para o sentinela.
  int size;  // Número de elementos na pilha.
}stack_t;

stack new_stack()
{
  stack s = malloc(sizeof (stack_t));
  s->size=0;
  s->end=malloc(sizeof(struct Node));
  s->end->prev=s->end;
  s->end->next=s->end;
  return s;
}

bool empty(stack s)
{
    if((s->end->prev==s->end)&&(s->end->next==s->end)){

        return true;
    }else {

         return false;
    }
}

int size(stack s)
{
    return s->size;
}

Type top(stack s)
{
    return s->end->next->key;
}

void push(Type k, stack s)
{
    struct Node* primeiro;
    primeiro=s->end->next;
    struct Node* novo=malloc(sizeof(struct Node));
    novo->key=k;
    novo->prev=primeiro->prev;
    novo->next=primeiro;
    primeiro->prev->next=novo;
    primeiro->prev=novo;
    s->size++;
}

void pop(stack s)
{
    struct Node* primeiro;
    primeiro=s->end->next;// topo da pilha - eh o 1 a sair!!!!
    primeiro->prev->next=primeiro->next;
    primeiro->next->prev=primeiro->prev;
    free(primeiro);
    s->size--;
}

void copy(stack p, stack s)
{
    if(s->size!=p->size){
        s->size=p->size;
    }
    while(!empty(s)){
        pop(s);
    }
    struct Node* i;
    for(i=p->end->prev;i!=p->end;i=i->prev){
        push(i->key,s);
    }
    free(i);
}

void swap(stack p, stack s)
{
    stack a= new_stack();
    copy(s, a);
    copy(p, s);
    copy(a, p);
}

void delete_stack(stack s)
{
  while(!empty(s)){
    pop(s);
  }
  free(s->end);
  free(s);
}







