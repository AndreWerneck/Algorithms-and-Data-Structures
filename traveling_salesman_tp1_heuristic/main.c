#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "List.h"


int main () {
    FILE *arq;
    FILE *saida;
    int citynum;

    arq = fopen(arqv[1], "r");
    saida = fopen(arqv[2], "w");
    if (arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return 0;
    } //Realiza abertura do arquivo

    City *cities = (City*) malloc(sizeof(City)); //Lista encadeada de cidades
    City *nearest= (City*) malloc(sizeof(City)); //Lista encadeada de caminho otimizado

    City *temp; //Ponteiro utilizado em comparaçoes
    City *create; //Ponteiro utilizado para criar cidades na Lista

    fscanf(arq, "%d", &citynum); //Lê o numero de cidades presentes no arquivo de entrada

    temp = cities;
    for (int x = 0; x < citynum; x++) {
        fscanf(arq, "%d %d %d", &temp->code, &temp->x, &temp->y); //Le as informacoes de cada cidade
        temp->status = 0; //Marca cidades lidas como nao comparadas ainda
        if (x == citynum -1) break;
        create = (City*) malloc(sizeof(City)); //Aloca espaco para cada cidade
        temp->next = create; //Adiciona cidades na lista "cities"
        create->prev = temp;
        temp = create;
    }

    temp->next = cities;
    cities->prev = temp;

    //COMEÇA A COMPARAR

    nearest->code = cities->code;
    nearest->x = cities->x;
    nearest->y = cities->y; //COPIA PRIMEIRA CIDADE PARA NOVA LISTA
    nearest->prev = nearest;
    nearest->next = nearest;

    temp = cities;
    cities->prev->next = cities->next;
    cities->next->prev = cities->prev;
    cities = cities->next;
    free(temp); //APAGA PRIMEIRA CIDADE DA LISTA ANTIGA.
    temp = cities;

    float disttotal = NearestNeighbor(citynum, cities, nearest);
    print(nearest, citynum, disttotal, saida);

    return 0;
}
