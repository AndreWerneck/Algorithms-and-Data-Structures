#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include <math.h>

int main(char * argv[], int argc)
{
    FILE *arq;
    FILE *saida;
    int i,n,k=0;
    float cost;


    arq=fopen(argv[1],"r");
    saida=fopen(argv[2],"w");
    if(arq==NULL){
        printf("Erro ao abrir o arquivo de entrada\n");
        return 0;
    }
    fscanf(arq,"%d",&n);

    city cidade[n];

        for(i=1;i<=n;i++){
        fscanf(arq,"%d %d %d",&cidade[i].code, &cidade[i].x, &cidade[i].y);
        }

    printf("\n");
    imprimir_vetor(n,cidade);
    printf("\n\n");

    k=num_ciclos(n-1);
    fprintf(saida,"%d\n",k);


    vetor = malloc(n*sizeof(int));
    melhor_visita = malloc(n*sizeof(int));

    cost=rotas_possiveis(cidade,1,n,saida);

    printf("\n");

    fprintf(saida,"Menor custo= $%.2f\n",cost);
    fprintf(saida,"Melhor caminho :\n");
    for (i = 1; i <=n; i++) {
        fprintf(saida, "%d -> ", melhor_visita[i]);
    }
    fprintf(saida, "%d", melhor_visita[1]);

    fclose(arq);
    fclose(saida);
    free(vetor);
    free(melhor_visita);

    return 0;
}


