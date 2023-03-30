#include "listaEncadeada.h"
#include <stddef.h>
#include <stdio.h>

void Imprimir(Node x)
{
    Node n = x;

    while(n != NULL)
    {
        printf("%d\n", n->key);
        n = n->next;
    }
}

int Size(Node x)
{
    Node n = x;
    int i = 0;

    while(n != NULL)
    {
        n = n->next;
        i++;
    }

    return i;
}

Node Pertence(Node x, int k)
{
    Node n = x;

    while(n != NULL)
    {
        if (n->key == k)
            return n;

        n = n->next;
    }

    return NULL;
}

Node Inserir(Node x, int k)
{
    Node n = x;

    if(n != NULL)
    {
        while(n->next != NULL)
            n = n->next;
    }

    n->next = malloc(sizeof(struct Node_t));
    n->next->next = NULL;
    n->next->key = k;

    return n->next;
}

Node Remover(Node x, int k)
{
    Node n = x;
    Node aux;

    if(n != NULL)
    {
        while(n->next->key != k)
            n = n->next;

        aux = n->next->next;
        free(n->next);
        n->next = aux;

        return aux;
    }

    return NULL;
}

Node Criar(int n, int v[])
{
    Node x = malloc(sizeof(struct Node_t));
    Node aux = x;

    x->key = v[0];
    for (int i = 1; i < n; i++)
    {
        aux->next = malloc(sizeof(struct Node_t));
        aux->next->next = NULL;
        aux->next->key = v[i];

        aux = aux->next;
    }

    return x;
}

Node Deletar(Node x)
{
    Node n = x;
    while(n != NULL)
    {
        n = x->next;
        free(x);
        x = n;
    }
}







