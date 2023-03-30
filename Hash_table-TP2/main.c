#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash.h"

int main(int argc, char **argv)
{
    int n = 0;

    sscanf(argv[2], "%d", &n);
    FILE * fp;
    fp = fopen(argv[1], "r");
    
    if(fp == NULL){
        printf("Erro ao ler o arquivo");
        return 0;
    }
    
    hash tabela = criaTabela(n);
    string str = malloc(50*sizeof(char));
    for (int i=0; i<50; i++){
        str[i] = 0;
    }
    while (fscanf(fp, "%s", str) != EOF){
        insere(tabela, str, n);
    }
    
    char srch[50];
    for (int i =0; i<50; i++){
        srch[i] = 0;
    }
    
    sscanf(argv[3], "%s",srch);
    imprime(tabela, srch, n);
    
    fclose(fp);
    free(str);
    return 0;
}
