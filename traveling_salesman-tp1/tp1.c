#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include <math.h>


int cont=0;


float menor (int n,float v[])
{
    float menor_valor;
    int i;
    menor_valor=v[0];
    for (i=0;i<n;i++)
        {
            if (v[i]<menor_valor){
                 menor_valor=v[i];

            }

        }
    return menor_valor;
}

float calcula_distancia(int x1,int x2, int y1, int y2)
{
    return sqrt(pow((x1 - x2), 2)+ pow((y1 - y2), 2));
}

int num_ciclos(int n)
 {
     if(n==0)
        {
        return 1;
        }else {
            return n * num_ciclos(n-1);
            }
 }

void swap(city *a, city *b)
{
	city aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
//PARTE 1 e 2


float rotas_possiveis(city *cidade, int first, int last,FILE *f)
{
    float cost=0;
    int j,i;
   	if(first==last)
	{
            aux=0;
	        for(i = 1; i <=last; i++){
            fprintf(f,"%d->", cidade[i].code);
            vetor[i]=cidade[i].code;

            if((i+1)>last){
                aux += calcula_distancia(cidade[i].x,cidade[1].x,cidade[i].y,cidade[1].y);
                }else {
                aux += calcula_distancia(cidade[i].x,cidade[i+1].x,cidade[i].y,cidade[i+1].y);

                }
            }

            fprintf(f,"%d = $%.2f",cidade[1].code,aux);
            fprintf(f,"\n");

            if(cont==0){
                menor_custo=aux;
                for(int j=0;j<last+1;j++){
                    melhor_visita[j]=vetor[j];
                }
            }
            else if(aux<menor_custo){
                menor_custo=aux;
                for(int j=0;j<last;j++){
                    melhor_visita[j]=vetor[j];
                }
            }

            aux=0;
            cont++;

	}
	else
	{

		for(int i = first; i < last; i++)
		{
		    swap((cidade+first),(cidade+i));
			rotas_possiveis(cidade, first+1,last,f);
		    swap((cidade+first),(cidade+i)); // backtracking
		}
	}


    return menor_custo;

}

void imprimir_vetor(int n,city vet[])
{
    for(int a=1;a<=n;a++){
        printf("%d\t%d\t%d\n",vet[a].code,vet[a].x,vet[a].y);
        }
}


