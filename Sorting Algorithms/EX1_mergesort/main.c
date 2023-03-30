#include <stdio.h>
#include <stdlib.h>

void merge(int* v, int inicio, int meio, int fim)
{

    int tamanho = fim-inicio+1;
    int* aux;
    int end1,end2,first1,first2,i,j,k;

    first1=inicio;
    first2=meio+1;
    end1=0;
    end2=0;

    aux=(int*)malloc(tamanho*sizeof(int));

    if(aux!=NULL){

        for(i=0; i<tamanho;i++){
            if(!end1 && !end2){
                if(v[first1]<v[first2]){
                    aux[i]=v[first1++];
                }else {
                    aux[i]=v[first2++];
                }
                if(first1>meio){
                    end1=1;
                }
                if(first2>fim){
                    end2=1;
                }
            }else{

            if(!end1){
                aux[i]=v[first1++];
            }else{
                aux[i]=v[first2++];
            }

            }
        }

        for(j=0,k=inicio;j<tamanho;j++,k++){
            v[k]=aux[j];
        }
    }
    free(aux);
}




void mergesort(int* v,int inicio, int fim)
{
    int meio = (inicio+fim)/2;
    if(fim <= inicio){
        return;
    }
    mergesort(v,inicio,meio);
    mergesort(v,meio+1,fim);
    merge(v,inicio,meio,fim);
}





int main()
{
    int v[7]={5,8,7,1,3,6,4};

    mergesort(v,0,6);

    printf("\n= {");

    for(int i=0;i<=7-1;i++){
        printf("%d ",v[i]);
    }
    printf("}\n");
}
