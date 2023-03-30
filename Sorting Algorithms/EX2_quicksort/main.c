#include <stdio.h>
#include <stdlib.h>

void Troca(int a,int b)
{
    int aux;
    aux=a;
    a=b;
    b=aux;
}

int particiona(int a[], int first, int last)
{
    int pivo,wall,i;

    pivo= a[last]; //elemento pivo

    wall = (first);

    for (i = first; i < last; i++) {
        if (a[i] <= pivo){
            Troca(a[i],a[wall++]);
        }
    }
    Troca(a[wall],a[last]);

    return (wall);
}

void ordena(int a[], int first, int last) {

int i;

if (last < first){

    return;
 /* condição de parada */

i = particiona(a, first, last); /* i: índice do pivô */

ordena(a, first, i-1); /* ordena partição esquerda */

ordena(a, i+1, last); /* ordena partição direita */
    }
}


void Insercao(int *v, int n) {

    int i,j;
    int aux;

    for (i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;

        while (( j >= 0 ) && (aux < v[j])) {
           v[j + 1] = v[j];
            j--;
    }
    v[j + 1] = aux;
    }
}


void quicksort(int a[], int n) {

 int x = particiona(a,0,n-1); // tamanhosub=indice do pivo
 int tamsubesq = x;
 int tamsubdir = (n-1) - (x);

 if((tamsubesq <=10)&& (tamsubdir<=10)){
  Insercao(a,n);

 }else{

    ordena(a, 0, n-1);
    }
}


int main()
{
    int v[12]={5,8,7,1,3,6,4,2,9,21,15,18};//20,17,19,16,13,15,14,12,11,22};

    quicksort(v,12);

    printf("\n= {");

    for(int i=0;i<=12-1;i++){
        printf("%d ",v[i]);
    }
    printf("}\n");
}
