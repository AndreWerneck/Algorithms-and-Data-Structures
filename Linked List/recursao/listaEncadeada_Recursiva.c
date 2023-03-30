#include "listaEncadeada.h"
#include <stddef.h>
#include <stdio.h>

struct Node_t
{
    struct Node_t* next;
    Type key;
};

struct List_t
{
    int size;
};

void Imprimir(Node x)
{
    printf("\n%d\n", x->next->key);
    if (x->next->next == NULL)
        return;

    Imprimir(x->next);
}

Node new_list(int k)
{
    list q = malloc(sizeof(struct List_t));
    q->size=0;
    Node n=malloc(sizeof(struct Node_t));
    n->key=k;
    n->next=NULL;
    return n;

}

int Size(Node x)
{
    if(x==NULL){
        return 0;
    }
    return 1+Size(x->next);

}

Node Pertence(Node x, int k)
{
    if(x==NULL){
        return 0;
    }else if(k==x->key){
        return x;
        }else{
           Pertence(x->next,k);
            }
}


Node Inserir(Node x, int k)
{
    if(x->next==NULL){
        x->next=new_list(k);
        return x->next;
    }
    Inserir(x->next,k);

}

Node Remover(Node x, int k)
{

  if(x->next == NULL) {
    return NULL;
  }
  if(k == x->next->key){
    x->next = x->next->next;
    return x->next;
  }
  Remover(x->next, k);
}

Node Criar(int n, int v[])
{
    if(n>=0){
        Node x = new_list(v[n-1]);
        x->next=Criar(n-1,v);
        return x;
    }
    return NULL;
}

Node Deletar(Node x)
{
  Node remover = Remover(x, x->key);
  free(remover);
  return remover;
}

void swap(Node x,Node y)
{
    Node aux;
    aux=x;
    x=y;
    y=aux;
}

Node Ordenar(Node x)
{
    int s = Size(x);
    if(s==1){
        return x;
    }
    for (Node i=x;i->next!=NULL;i=i->next){
    if(x->key>x->next->key){
        swap(x,x->next);}
    }
    Ordenar(x);

}



