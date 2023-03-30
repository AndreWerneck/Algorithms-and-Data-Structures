#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash.h"
#include "list.h"

struct hash_t{
    ListSentinel *lista;
};

hash criaTabela(int m){
    int i;
    hash tabela = malloc (pow(26,m) * sizeof(struct hash_t));
    for(i = 0; i < pow(26,m) ; i++){
        tabela[i].lista = NULL;
    }
    return tabela;
}

int numeriza(char t){
    int aux;
    aux = (int)t - 97;
    return aux;
}

unsigned int hashing(string n,unsigned int m){
    unsigned int resultado=0;
    unsigned int tam = pow(26,m);
    for(int i =0;i<m;i++){
        int tascii = numeriza(n[i]);
        resultado += tascii * (pow(26,m-i-1));
    }
    unsigned int i = (resultado%tam);
    return i;
}

void insere(hash t,string w,int tam){
    unsigned int indice = hashing(w,tam);
    if (t[indice].lista == NULL){
        t[indice].lista = createList();
        addNodeList(t[indice].lista, w);
    }
    else{
        addNodeList(t[indice].lista, w);
    }
}

void imprime(hash table, string w, int tam){
    unsigned int indice = hashing(w,tam);
    if (table[indice].lista == NULL){
        printf("Não encontrado nenhuma palavra \n");
    }
    else{
        printList(table[indice].lista);
    }
}






