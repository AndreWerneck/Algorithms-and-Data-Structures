#ifndef __TP2___TSP__List__
#define __TP2___TSP__List__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct City{
    int code;
    int x;
    int y;
    int status;
    struct City* next;
    struct City* prev;
} City;

float calcdist (int x1, int x2, int y1, int y2);
void insereFIM (City *nearest, int code, int x, int y);
float NearestNeighbor (int citynum, City* cities, City* nearest);
void print(City* nearest, int citynum, float total, FILE* out);
#endif /* defined(__TP2___TSP__List__) */
