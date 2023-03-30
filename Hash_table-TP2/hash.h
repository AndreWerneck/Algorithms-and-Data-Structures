#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _HASH_H
#define _HASH_H

typedef struct hash_t* hash;
typedef char* string;

/*typedef struct worter{
    const char* prefixo;
    const char* palavra;
}worter;*/

hash criaTabela(int m); // criar a tabela hash

unsigned int hashing (string n,unsigned int m); // funcao de hash - indexa a string-

int numeriza(char t); // converte um char num inteiro

void insere(hash table, string w, int tam);

void imprime(hash table, string w, int tam);

#endif // _HASH_H



