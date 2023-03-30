#include "List.h"

float calcdist (int x1, int x2, int y1, int y2) {
    return sqrt((pow (x1-x2, 2)) + (pow(y1 - y2, 2)));
}

void insereFIM (City *nearest, int code, int x, int y){
    City *insere = (City*) malloc(sizeof(City));
    insere->code = code;
    insere->x = x;
    insere->y = y;
    insere->next = nearest;
    insere->prev = nearest->prev;
    nearest->prev->next = insere;
    nearest->prev = insere;
}

float NearestNeighbor (int citynum, City* cities, City* nearest ){
    int ciclos = 0;
    float menordist = 0;
    float distatual;
    float disttotal = 0;
    City* menor = cities; //Ponteiro utilizado para salvar cidade com menor distancia da idade comparada (* temp)
    City* compara = nearest; //Ponteiro para a cidade a ser comparada
    City* temp = cities;
    City* apaga;

    while (ciclos < citynum-1){
        while (temp->status == 0){
            distatual = calcdist(compara->x, temp->x, compara->y, temp->y);
            if (distatual < menordist || menordist == 0){
                menor = temp;
                menordist = distatual;
            }
            temp->status = 1;
            temp = temp->next;
        }
        insereFIM(nearest, menor->code, menor->x, menor->y);
        disttotal = disttotal + menordist;
        compara = compara -> next;
        apaga = cities;
        while (apaga != menor)
            apaga = apaga->next;
        apaga->prev->next = apaga->next;
        apaga->next->prev = apaga->prev;
        cities = cities->next;
        //free (apaga);
        cities = cities->next;
        temp = cities;
        while (temp->status != 0){
            temp->status = 0;
            temp = temp->next;
        }
        menor = cities;
        ciclos++;
        if (ciclos == citynum -1){
            disttotal = disttotal + calcdist(nearest->x, nearest->prev->x, nearest->y, nearest->prev->y);
        }
        menordist = 0;
    }
    return disttotal;

}

void print(City* nearest, int citynum, float total, FILE *out){
    City* percorre = nearest;
    fprintf(out, "Melhor caminho: $%f\n", total);
    for (int x=0; x <= citynum; x++){
        fprintf(out, "%d ", percorre->code);
        percorre = percorre->next;
    }

}
