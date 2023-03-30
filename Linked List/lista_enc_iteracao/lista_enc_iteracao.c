#include "lista_enc_iteracao.h"
#include <stdio.h>
#include <stdlib.h>

struct Node{
    Type key; // elemento da lista
    struct Node* next; // ponteiro que aponta para o proximo elemento da lista
};

No new_list()
{
  No l = malloc(sizeof(struct Node));
  l->next=NULL;
  l=NULL;
  return l;
}

void Imprimir(No x)
{
    while(x!=NULL){
        printf("%d\n",x->key);
        x=x->next;
    }
}

int Size(No x)
{
    int i=0;
    while(x!=NULL){
        x=x->next;
        i++;
    }
    return i;
}

No Pertence(No x, int k)
{
    int i=0;
    while(x!=NULL){
        if(x->key==k){
            return x;
            x=x->next;
        }
    }
    return NULL;
}

No Inserir(No x, int k)
{
    int s = Size(x);
    int i;
    for(i=0;i<s;i++){
        if(i==s-1){
            x->next->key=k;
            x->next->next=NULL;
        }
    }
   return x->next;
}

No Remover(No x, int k)
{
   if(Pertence(x,k)!=NULL){
    while(x->key!=k){
        x=x->next;
    }

   }

}






